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

class FixedPointTheorem {
    double F(double R, double X){
        return R*X*(1-X);
    }
    public:
    double cycleRange(double R) {
        double x = 0.25;
        for (int i = 0; i < 200000; ++i){
            x = F(R,x);
        }
        double min = F(R,x);
        double max = min;
        for(int i = 200001; i < 201000; i++){
            x = F(R,x);
            if(x > max){
                max = x;
            }
            if(x < min){
                min = x;
            }
        }

        return max - min;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(double R, double __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FixedPointTheorem *instance = new FixedPointTheorem();
    double __result = instance->cycleRange(R);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            double R = 0.1;
            double __expected = 0.0;
            return do_test(R, __expected, __no);
        }
        case 1: {
            double R = 3.05;
            double __expected = 0.14754098360655865;
            return do_test(R, __expected, __no);
        }
        case 2: {
            double R = 3.4499;
            double __expected = 0.4175631735867292;
            return do_test(R, __expected, __no);
        }
        case 3: {
            double R = 3.55;
            double __expected = 0.5325704489850351;
            return do_test(R, __expected, __no);
        }
        case 4: {
            double R = 3.565;
            double __expected = 0.5454276003030636;
            return do_test(R, __expected, __no);
        }
        case 5: {
            double R = 3.5689;
            double __expected = 0.5489996297493569;
            return do_test(R, __expected, __no);
        }
        case 6: {
            double R = 3.00005;
            double __expected = 0.004713996108955176;
            return do_test(R, __expected, __no);
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
    cout << "FixedPointTheorem (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380042483;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
