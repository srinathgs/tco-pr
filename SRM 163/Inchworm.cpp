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

class Inchworm {
    public:
    int lunchtime(int branch, int rest, int leaf) {
        int res = 0;
        for(int i = 0; i <= branch; i+=rest){
            if( (i % leaf) == 0){
                res++;
            }
        }
        return res;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int branch, int rest, int leaf, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Inchworm *instance = new Inchworm();
    int __result = instance->lunchtime(branch, rest, leaf);
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
            int branch = 11;
            int rest = 2;
            int leaf = 4;
            int __expected = 3;
            return do_test(branch, rest, leaf, __expected, __no);
        }
        case 1: {
            int branch = 12;
            int rest = 6;
            int leaf = 4;
            int __expected = 2;
            return do_test(branch, rest, leaf, __expected, __no);
        }
        case 2: {
            int branch = 20;
            int rest = 3;
            int leaf = 7;
            int __expected = 1;
            return do_test(branch, rest, leaf, __expected, __no);
        }
        case 3: {
            int branch = 21;
            int rest = 7;
            int leaf = 3;
            int __expected = 2;
            return do_test(branch, rest, leaf, __expected, __no);
        }
        case 4: {
            int branch = 15;
            int rest = 16;
            int leaf = 5;
            int __expected = 1;
            return do_test(branch, rest, leaf, __expected, __no);
        }
        case 5: {
            int branch = 1000;
            int rest = 3;
            int leaf = 7;
            int __expected = 48;
            return do_test(branch, rest, leaf, __expected, __no);
        }
        case 6: {
            int branch = 1000;
            int rest = 7;
            int leaf = 3;
            int __expected = 48;
            return do_test(branch, rest, leaf, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "Inchworm (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380053367;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
