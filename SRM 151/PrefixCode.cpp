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

class PrefixCode {
    bool hasPrefix(string a, string b){
        if(b.length() > a.length()){
            return false;
        }
        for(int i = b.length() - 1; i >= 0; i--){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    public:
    string isOne(vector<string> words) {
        ostringstream s;
        int n = words.size();
        if(n > 1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i != j){
                        if(hasPrefix(words[i],words[j])){
                            s << "No, "<< j;
                            return s.str();
                        }
                    }
                }
            }
        }
        s.str("");
        s<<"Yes";
        return s.str();
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> words, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    PrefixCode *instance = new PrefixCode();
    string __result = instance->isOne(words);
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
            string words[] = {
                "trivial"
            };
            string __expected = "Yes";
            return do_test(to_vector(words), __expected, __no);
        }
        case 1: {
            string words[] = {
                "10001",
                "011",
                "100",
                "001",
                "10"
            };
            string __expected = "No, 2";
            return do_test(to_vector(words), __expected, __no);
        }
        case 2: {
            string words[] = {
                "no",
                "nosy",
                "neighbors",
                "needed"
            };
            string __expected = "No, 0";
            return do_test(to_vector(words), __expected, __no);
        }
        case 3: {
            string words[] = {
                "1010",
                "11",
                "100",
                "0",
                "1011"
            };
            string __expected = "Yes";
            return do_test(to_vector(words), __expected, __no);
        }
        case 4: {
            string words[] = {
                "No",
                "not"
            };
            string __expected = "Yes";
            return do_test(to_vector(words), __expected, __no);
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
    cout << "PrefixCode (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380040794;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
