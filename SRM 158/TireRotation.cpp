#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

class TireRotation {
    string rotate(string inp){
        swap(inp[0],inp[3]);
        swap(inp[2],inp[3]);
        swap(inp[3],inp[1]);
        return inp;
    }
    public:
    int getCycle(string initial, string current) {
        string curr = initial;
        for(int i = 1; i <=4; i++){
            if(curr == current){
                return i;
            }
            curr = rotate(curr);
        }
        return -1;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string initial, string current, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    TireRotation *instance = new TireRotation();
    int __result = instance->getCycle(initial, current);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            string initial = "ABCD";
            string current = "ABCD";
            int __expected = 1;
            return do_test(initial, current, __expected, __no);
        }
        case 1: {
            string initial = "ABCD";
            string current = "DCAB";
            int __expected = 2;
            return do_test(initial, current, __expected, __no);
        }
        case 2: {
            string initial = "ABCD";
            string current = "CDBA";
            int __expected = 4;
            return do_test(initial, current, __expected, __no);
        }
        case 3: {
            string initial = "ABCD";
            string current = "ABDC";
            int __expected = -1;
            return do_test(initial, current, __expected, __no);
        }
        case 4: {
            string initial = "ZAXN";
            string current = "XNAZ";
            int __expected = 4;
            return do_test(initial, current, __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "TireRotation (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380046459;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
