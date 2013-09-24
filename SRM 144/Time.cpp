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
#include<string>
#include<sstream>

using namespace std;

class Time{
private:
	string toStr(int a){ostringstream os; os << a; return os.str();}
public:
	string whatTime(int seconds){
		int secs = seconds % 60;
		seconds -= secs;
		string s = toStr(secs);
		int min = seconds % 3600;
		seconds -= min;
		min /= 60;
		string m = toStr(min);
		int hr = seconds / 3600;
		string h = toStr(hr);
		return h + ":" + m + ":" + s;
		
	}

};
// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int seconds, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Time *instance = new Time();
    string __result = instance->whatTime(seconds);
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
            int seconds = 0;
            string __expected = "0:0:0";
            return do_test(seconds, __expected, __no);
        }
        case 1: {
            int seconds = 3661;
            string __expected = "1:1:1";
            return do_test(seconds, __expected, __no);
        }
        case 2: {
            int seconds = 5436;
            string __expected = "1:30:36";
            return do_test(seconds, __expected, __no);
        }
        case 3: {
            int seconds = 86399;
            string __expected = "23:59:59";
            return do_test(seconds, __expected, __no);
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
    cout << "Time (200 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380037216;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 200 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
