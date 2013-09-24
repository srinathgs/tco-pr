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

class CCipher {
    public:
        string alphabets;
        CCipher():alphabets("ABCDEFGHIJKLMNOPQRSTUVWXYZ"){}
        string decode(string cipherText, int shift) {
            string res;
            res.resize(cipherText.length());
            int l = cipherText.length();
            for (int i = 0; i < l; ++i){
                res[i] = alphabets[((cipherText[i] - 'A') - shift) % 26];
            }
            return res;
        }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string cipherText, int shift, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    CCipher *instance = new CCipher();
    string __result = instance->decode(cipherText, shift);
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
            string cipherText = "VQREQFGT";
            int shift = 2;
            string __expected = "TOPCODER";
            return do_test(cipherText, shift, __expected, __no);
        }
        case 1: {
            string cipherText = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            int shift = 10;
            string __expected = "QRSTUVWXYZABCDEFGHIJKLMNOP";
            return do_test(cipherText, shift, __expected, __no);
        }
        case 2: {
            string cipherText = "TOPCODER";
            int shift = 0;
            string __expected = "TOPCODER";
            return do_test(cipherText, shift, __expected, __no);
        }
        case 3: {
            string cipherText = "ZWBGLZ";
            int shift = 25;
            string __expected = "AXCHMA";
            return do_test(cipherText, shift, __expected, __no);
        }
        case 4: {
            string cipherText = "DBNPCBQ";
            int shift = 1;
            string __expected = "CAMOBAP";
            return do_test(cipherText, shift, __expected, __no);
        }
        case 5: {
            string cipherText = "LIPPSASVPH";
            int shift = 4;
            string __expected = "HELLOWORLD";
            return do_test(cipherText, shift, __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "CCipher (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380038459;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
