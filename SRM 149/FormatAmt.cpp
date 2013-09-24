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

class FormatAmt {
    typedef std::vector<int> VI;
    VI getDig(int number){
        VI digits;
        while(number > 0){
            digits.push_back(number % 10);
            number /= 10;
        }
        return digits;
    }
    public:
    string amount(int dollars, int cents) {
        ostringstream s;
        
        
        
        if(dollars > 0){
            VI digits = getDig(dollars);
            
            for (std::vector<int>::iterator i = digits.begin(); i != digits.end(); ++i){
                s << (*i);
                if(i != digits.begin() && (digits.size() > 3) && ((i - digits.begin() + 1) % 3 == 0) && ((i + 1) != digits.end())) s << ",";
                
            }
            s << "$";
        }
        else{
            s << "0$";
        }
        string res = s.str();
        res = string(res.rbegin(),res.rend());
        s.str("");
        s << ".";
        if(cents < 10) s << "0";
        s << cents;
        return res + s.str();
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int dollars, int cents, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FormatAmt *instance = new FormatAmt();
    string __result = instance->amount(dollars, cents);
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
            int dollars = 123456;
            int cents = 0;
            string __expected = "$123,456.00";
            return do_test(dollars, cents, __expected, __no);
        }
        case 1: {
            int dollars = 49734321;
            int cents = 9;
            string __expected = "$49,734,321.09";
            return do_test(dollars, cents, __expected, __no);
        }
        case 2: {
            int dollars = 0;
            int cents = 99;
            string __expected = "$0.99";
            return do_test(dollars, cents, __expected, __no);
        }
        case 3: {
            int dollars = 249;
            int cents = 30;
            string __expected = "$249.30";
            return do_test(dollars, cents, __expected, __no);
        }
        case 4: {
            int dollars = 1000;
            int cents = 1;
            string __expected = "$1,000.01";
            return do_test(dollars, cents, __expected, __no);
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
    cout << "FormatAmt (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380039265;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
