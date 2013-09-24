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
#include <algorithm>
using namespace std;

class DiskSpace {
    public:
    int minDrives(vector<int> used, vector<int> total) {
        int u = 0;
        int n = used.size();
        int ans = 0;
        for(int i = 0; i < n; i++) 
            u+= used[i];
        sort(total.rbegin(),total.rend());
        for(int i = 0; i < n; i++){
            if(u != 0) ans++;
            u -= min(u,total[i]);
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> used, vector<int> total, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    DiskSpace *instance = new DiskSpace();
    int __result = instance->minDrives(used, total);
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
            int used[] = {
                300, 525, 110
            };
            int total[] = {
                350, 600, 115
            };
            int __expected = 2;
            return do_test(to_vector(used), to_vector(total), __expected, __no);
        }
        case 1: {
            int used[] = {
                1, 200, 200, 199, 200, 200
            };
            int total[] = {
                1000, 200, 200, 200, 200, 200
            };
            int __expected = 1;
            return do_test(to_vector(used), to_vector(total), __expected, __no);
        }
        case 2: {
            int used[] = {
                750, 800, 850, 900, 950
            };
            int total[] = {
                800, 850, 900, 950, 1000
            };
            int __expected = 5;
            return do_test(to_vector(used), to_vector(total), __expected, __no);
        }
        case 3: {
            int used[] = {
                49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49
            };
            int total[] = {
                50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50
            };
            int __expected = 49;
            return do_test(to_vector(used), to_vector(total), __expected, __no);
        }
        case 4: {
            int used[] = {
                331, 242, 384, 366, 428, 114, 145, 89, 381, 170, 329, 190, 482, 246, 2, 38, 220, 290, 402, 385
            };
            int total[] = {
                992, 509, 997, 946, 976, 873, 771, 565, 693, 714, 755, 878, 897, 789, 969, 727, 765, 521, 961, 906
            };
            int __expected = 6;
            return do_test(to_vector(used), to_vector(total), __expected, __no);
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
    cout << "DiskSpace (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380045548;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
