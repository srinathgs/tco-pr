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

class ProfitCalculator {
    public:
    int percent(vector<string> items){
        int n = items.size();
        double sales = 0;
        double costs = 0;
        for(int i = 0; i < n; i++){
            double sale,cost;
            istringstream s(items[i]);
            s >> sale >> cost;
            sales += sale;
            costs += cost;
        }
        return 100*((sales - costs)/sales);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> items, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ProfitCalculator *instance = new ProfitCalculator();
    int __result = instance->percent(items);
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
            string items[] = {
                "012.99 008.73",
                "099.99 050.00",
                "123.45 101.07"
            };
            int __expected = 32;
            return do_test(to_vector(items), __expected, __no);
        }
        case 1: {
            string items[] = {
                "000.00 049.99",
                "999.99 936.22",
                "033.99 025.64",
                "249.99 211.87"
            };
            int __expected = 4;
            return do_test(to_vector(items), __expected, __no);
        }
        case 2: {
            string items[] = {
                "822.77 704.86",
                "829.42 355.45",
                "887.18 949.38"
            };
            int __expected = 20;
            return do_test(to_vector(items), __expected, __no);
        }
        case 3: {
            string items[] = {
                "612.72 941.34",
                "576.46 182.66",
                "787.41 524.70",
                "637.96 333.23",
                "345.01 219.69",
                "567.22 104.77",
                "673.02 885.77"
            };
            int __expected = 23;
            return do_test(to_vector(items), __expected, __no);
        }
        case 4: {
            string items[] = {
                "811.22 275.32",
                "433.89 006.48",
                "141.28 967.41",
                "344.47 786.23",
                "897.47 860.61",
                "007.42 559.29",
                "255.72 460.00",
                "419.35 931.19",
                "419.25 490.52",
                "199.78 114.44",
                "505.63 276.58",
                "720.96 735.00",
                "719.90 824.46",
                "816.58 195.94",
                "498.68 453.05",
                "399.48 921.39",
                "930.88 017.63",
                "422.20 075.39",
                "380.22 917.27",
                "630.83 995.87",
                "821.07 126.87",
                "715.73 985.62",
                "246.23 134.64",
                "168.28 550.33",
                "707.28 046.72",
                "117.76 281.87",
                "595.43 410.45",
                "345.28 532.42",
                "554.24 264.34",
                "195.73 814.87",
                "131.98 041.28",
                "595.13 939.47",
                "576.04 107.70",
                "716.00 404.75",
                "524.24 029.96",
                "673.49 070.97",
                "288.09 849.43",
                "616.34 236.34",
                "401.96 316.33",
                "371.18 014.27",
                "809.63 508.33",
                "375.68 290.84",
                "334.66 477.89",
                "689.54 526.35",
                "084.77 316.51",
                "304.76 015.91",
                "460.63 636.56",
                "357.84 436.20",
                "752.24 047.64",
                "922.10 573.12"
            };
            int __expected = 10;
            return do_test(to_vector(items), __expected, __no);
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
    cout << "ProfitCalculator (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380043575;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
