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

class StreetParking {
    typedef std::vector<bool> VB;
    public:
    int freeParks(string street) {
        int n = street.length();
        VB parkable(n + 1,true);
        for(int i = 0; i < 2; i++){
            if(street[i] != '-'){
                parkable[i] = false;
            }
        }
        for(int i = 2; i < n; i++){
            if(street[i] == 'D'){
                parkable[i] = false;
            }
            else if(street[i] == 'B'){
                parkable[i] = false;
                parkable[i - 1] = false;
                parkable[i - 2] = false;
            }
            else if(street[i] == 'S'){
                parkable[i] = false;
                parkable[i+1] = false;
                parkable[i-1] = false;
            }
        }
        int parkableSpaces = 0;
        for(int i = 0; i < parkable.size() - 1; i++){
            if(parkable[i] == true)
                parkableSpaces++;
        }
        return parkableSpaces;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string street, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    StreetParking *instance = new StreetParking();
    int __result = instance->freeParks(street);
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
            string street = "---B--S-D--S--";
            int __expected = 4;
            return do_test(street, __expected, __no);
        }
        case 1: {
            string street = "DDBDDBDDBDD";
            int __expected = 0;
            return do_test(street, __expected, __no);
        }
        case 2: {
            string street = "--S--S--S--S--";
            int __expected = 2;
            return do_test(street, __expected, __no);
        }
        case 3: {
            string street = "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D";
            int __expected = 14;
            return do_test(street, __expected, __no);
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
    cout << "StreetParking (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380046973;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
