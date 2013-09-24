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

class RectangularGrid {
    public:
    long long countRectangles(int width, int height) {
        long long ans = 0;
        for(int i = 1; i <=  width; i++)
            for(int j = 1; j <= height; j++){
                if(i == j) continue;
                ans += (width - i + 1) * (height - j + 1);
            }
        return ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int width, int height, long long __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    RectangularGrid *instance = new RectangularGrid();
    long long __result = instance->countRectangles(width, height);
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
            int width = 3;
            int height = 3;
            long long __expected = 22LL;
            return do_test(width, height, __expected, __no);
        }
        case 1: {
            int width = 5;
            int height = 2;
            long long __expected = 31LL;
            return do_test(width, height, __expected, __no);
        }
        case 2: {
            int width = 10;
            int height = 10;
            long long __expected = 2640LL;
            return do_test(width, height, __expected, __no);
        }
        case 3: {
            int width = 1;
            int height = 1;
            long long __expected = 0LL;
            return do_test(width, height, __expected, __no);
        }
        case 4: {
            int width = 592;
            int height = 964;
            long long __expected = 81508708664LL;
            return do_test(width, height, __expected, __no);
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
    cout << "RectangularGrid (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1376677121;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
