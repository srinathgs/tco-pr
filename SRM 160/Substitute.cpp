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

class Substitute {
    public:
    int getValue(string key, string code) {
        string actualCode = "";
        stringstream s;
        int n = code.length();
        for(int i = 0; i < n; i++){
            if(key.find(code[i]) != string::npos)
                actualCode += code[i];
        }
        string newKey = string(key.begin(), key.end() - 1);
        newKey += *(key.end() - 1) + newKey;
        int l = actualCode.length();
        for(int i = 0; i < l; i++){
            s << (newKey.find(actualCode[i]) + 1)%10;
        }
        int res;
        s >> res;
        return res;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string key, string code, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Substitute *instance = new Substitute();
    int __result = instance->getValue(key, code);
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
            string key = "TRADINGFEW";
            string code = "LGXWEV";
            int __expected = 709;
            return do_test(key, code, __expected, __no);
        }
        case 1: {
            string key = "ABCDEFGHIJ";
            string code = "XJ";
            int __expected = 0;
            return do_test(key, code, __expected, __no);
        }
        case 2: {
            string key = "CRYSTALBUM";
            string code = "MMA";
            int __expected = 6;
            return do_test(key, code, __expected, __no);
        }

        // Your custom testcase goes here
        case 3:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "Substitute (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 3; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380049849;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
