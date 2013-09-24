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

class DivisorDigits {
    typedef std::vector<int> VI;
    VI getDig(int number){
        VI res;
        int num = number;
        while(num > 0){
            res.push_back(num%10);
            num /=10;
        }
        return res;
    }
    public:
    int howMany(int number) {
        VI nums;
        nums = getDig(number);
        int cnt = 0;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i){
            if(((*i) > 0) && (number % *(i) == 0)) cnt++;
        }
        return cnt;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int number, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    DivisorDigits *instance = new DivisorDigits();
    int __result = instance->howMany(number);
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
            int number = 12345;
            int __expected = 3;
            return do_test(number, __expected, __no);
        }
        case 1: {
            int number = 661232;
            int __expected = 3;
            return do_test(number, __expected, __no);
        }
        case 2: {
            int number = 52527;
            int __expected = 0;
            return do_test(number, __expected, __no);
        }
        case 3: {
            int number = 730000000;
            int __expected = 0;
            return do_test(number, __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "DivisorDigits (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380038881;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
