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

class ImageDithering {
    public:
    int count(string dithered, vector<string> screen) {
        int cnt = 0;
        for (std::vector<string>::iterator i = screen.begin(); i != screen.end(); ++i){
            int l = (*i).length();
            for (int j = 0; j < l ; j++){
                if(dithered.find((*i)[j]) != string::npos){
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string dithered, vector<string> screen, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ImageDithering *instance = new ImageDithering();
    int __result = instance->count(dithered, screen);
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
            string dithered = "BW";
            string screen[] = {
                "AAAAAAAA",
                "ABWBWBWA",
                "AWBWBWBA",
                "ABWBWBWA",
                "AWBWBWBA",
                "AAAAAAAA"
            };
            int __expected = 24;
            return do_test(dithered, to_vector(screen), __expected, __no);
        }
        case 1: {
            string dithered = "BW";
            string screen[] = {
                "BBBBBBBB",
                "BBWBWBWB",
                "BWBWBWBB",
                "BBWBWBWB",
                "BWBWBWBB",
                "BBBBBBBB"
            };
            int __expected = 48;
            return do_test(dithered, to_vector(screen), __expected, __no);
        }
        case 2: {
            string dithered = "ACEGIKMOQSUWY";
            string screen[] = {
                "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"
            };
            int __expected = 150;
            return do_test(dithered, to_vector(screen), __expected, __no);
        }
        case 3: {
            string dithered = "CA";
            string screen[] = {
                "BBBBBBB",
                "BBBBBBB",
                "BBBBBBB"
            };
            int __expected = 0;
            return do_test(dithered, to_vector(screen), __expected, __no);
        }
        case 4: {
            string dithered = "DCBA";
            string screen[] = {
                "ACBD"
            };
            int __expected = 4;
            return do_test(dithered, to_vector(screen), __expected, __no);
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
    cout << "ImageDithering (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380037800;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
