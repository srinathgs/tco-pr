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

class GuessTheNumber {
    public:
    int noGuesses(int upper, int answer) {
        int guessNo = 1;
        int lower = 1;
        int mid = lower + (upper - lower) / 2; 
        while(mid != answer){
            if(mid < answer){
                lower = mid+1;
            }
            else if(mid > answer){
                upper = mid - 1;
            }
            mid = lower + (upper - lower)/2;
            guessNo++;
        }
        return guessNo;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int upper, int answer, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GuessTheNumber *instance = new GuessTheNumber();
    int __result = instance->noGuesses(upper, answer);
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
            int upper = 9;
            int answer = 6;
            int __expected = 3;
            return do_test(upper, answer, __expected, __no);
        }
        case 1: {
            int upper = 1000;
            int answer = 750;
            int __expected = 2;
            return do_test(upper, answer, __expected, __no);
        }
        case 2: {
            int upper = 643;
            int answer = 327;
            int __expected = 7;
            return do_test(upper, answer, __expected, __no);
        }
        case 3: {
            int upper = 157;
            int answer = 157;
            int __expected = 8;
            return do_test(upper, answer, __expected, __no);
        }
        case 4: {
            int upper = 128;
            int answer = 64;
            int __expected = 1;
            return do_test(upper, answer, __expected, __no);
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
    cout << "GuessTheNumber (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380045882;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
