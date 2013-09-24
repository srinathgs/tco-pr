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
typedef vector<int> vi;

class WidgetRepairs{

    public:
        int days(vi arrivals, int numPerDay){
            int remaining = 0;
            for(unsigned int i = 0; i < arrivals.size() - 1; i++){
                remaining = 0;
                if(arrivals[i]>numPerDay)
                {
                    remaining = arrivals[i] - numPerDay;
                    arrivals[i] -= remaining;
                }
                arrivals[i+1] += remaining;
            }
            if(arrivals.back()>numPerDay){
                remaining = arrivals.back() - numPerDay;
                arrivals.back() = arrivals.back() - remaining;
                while(remaining > numPerDay){
                    arrivals.push_back(remaining);
                    if(arrivals.back()>numPerDay){
                        arrivals.back() = arrivals.back() - numPerDay;
                        remaining -= numPerDay;
                    }
                }
            }
            arrivals.push_back(remaining);
            int numDays = 0;
            for(unsigned int j = 0; j < arrivals.size();j++){
                if(arrivals[j]>0){
                    numDays++;
                }
            }
            return numDays;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> arrivals, int numPerDay, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    WidgetRepairs *instance = new WidgetRepairs();
    int __result = instance->days(arrivals, numPerDay);
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
            int arrivals[] = {
                10, 0, 0, 4, 20
            };
            int numPerDay = 8;
            int __expected = 6;
            return do_test(to_vector(arrivals), numPerDay, __expected, __no);
        }
        case 1: {
            int arrivals[] = {
                0, 0, 0
            };
            int numPerDay = 10;
            int __expected = 0;
            return do_test(to_vector(arrivals), numPerDay, __expected, __no);
        }
        case 2: {
            int arrivals[] = {
                100, 100
            };
            int numPerDay = 10;
            int __expected = 20;
            return do_test(to_vector(arrivals), numPerDay, __expected, __no);
        }
        case 3: {
            int arrivals[] = {
                27, 0, 0, 0, 0, 9
            };
            int numPerDay = 9;
            int __expected = 4;
            return do_test(to_vector(arrivals), numPerDay, __expected, __no);
        }
        case 4: {
            int arrivals[] = {
                6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6
            };
            int numPerDay = 3;
            int __expected = 15;
            return do_test(to_vector(arrivals), numPerDay, __expected, __no);
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
    cout << "WidgetRepairs (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380040526;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
