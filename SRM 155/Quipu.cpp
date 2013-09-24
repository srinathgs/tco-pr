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

class Quipu {
    public:
    int readKnots(string knots) {
        ostringstream s;
        int n = knots.length();
        int res;
        char prev = knots[0];
        int num = 0;
        for(int i = 1; i < n; i++){
            if(prev == '-' && knots[i] == '-'){
                s << 0;
                prev = '-';
            }
            else if (prev == '-' && knots[i] == 'X'){
                num = 1;
                prev = 'X';
            }
            else if(prev == 'X' && knots[i] == 'X'){
                num++;
                prev = 'X';
            }
            else if(prev == 'X' && knots[i] == '-'){
                s << num;
                prev = '-';
            }
        }
        istringstream o(s.str());
        
        o >> res;
        return res;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string knots, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Quipu *instance = new Quipu();
    int __result = instance->readKnots(knots);
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
            string knots = "-XX-XXXX-XXX-";
            int __expected = 243;
            return do_test(knots, __expected, __no);
        }
        case 1: {
            string knots = "-XX--XXXX---XXX-";
            int __expected = 204003;
            return do_test(knots, __expected, __no);
        }
        case 2: {
            string knots = "-X-";
            int __expected = 1;
            return do_test(knots, __expected, __no);
        }
        case 3: {
            string knots = "-X-------";
            int __expected = 1000000;
            return do_test(knots, __expected, __no);
        }
        case 4: {
            string knots = "-XXXXXXXXX--XXXXXXXXX-XXXXXXXXX-XXXXXXX-XXXXXXXXX-";
            int __expected = 909979;
            return do_test(knots, __expected, __no);
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
    cout << "Quipu (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380044115;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
