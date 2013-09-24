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

class MostProfitable {
    public:
    string bestItem(vector<int> costs, vector<int> prices, vector<int> sales, vector<string> items) {
        long max = 0;
        int idx = -1;
        int n = costs.size();
        for(int i = 0; i < n; i++){
            long earnings = (prices[i] - costs[i]) * sales[i];
            if(earnings > max){
                max = earnings;
                idx = i;
            }
        }
        if(idx > -1)
        return items[idx];
        return "";

    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> costs, vector<int> prices, vector<int> sales, vector<string> items, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    MostProfitable *instance = new MostProfitable();
    string __result = instance->bestItem(costs, prices, sales, items);
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
            int costs[] = {
                100, 120, 150, 1000
            };
            int prices[] = {
                110, 110, 200, 2000
            };
            int sales[] = {
                20, 100, 50, 3
            };
            string items[] = {
                "Video Card",
                "256M Mem",
                "CPU/Mobo combo",
                "Complete machine"
            };
            string __expected = "Complete machine";
            return do_test(to_vector(costs), to_vector(prices), to_vector(sales), to_vector(items), __expected, __no);
        }
        case 1: {
            int costs[] = {
                100
            };
            int prices[] = {
                100
            };
            int sales[] = {
                134
            };
            string items[] = {
                "Service, at cost"
            };
            string __expected = "";
            return do_test(to_vector(costs), to_vector(prices), to_vector(sales), to_vector(items), __expected, __no);
        }
        case 2: {
            int costs[] = {
                38, 24
            };
            int prices[] = {
                37, 23
            };
            int sales[] = {
                1000, 643
            };
            string items[] = {
                "Letter",
                "Postcard"
            };
            string __expected = "";
            return do_test(to_vector(costs), to_vector(prices), to_vector(sales), to_vector(items), __expected, __no);
        }
        case 3: {
            int costs[] = {
                10, 10
            };
            int prices[] = {
                11, 12
            };
            int sales[] = {
                2, 1
            };
            string items[] = {
                "A",
                "B"
            };
            string __expected = "A";
            return do_test(to_vector(costs), to_vector(prices), to_vector(sales), to_vector(items), __expected, __no);
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
    cout << "MostProfitable (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380043143;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
