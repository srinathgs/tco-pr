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

class CardCount {
    typedef std::vector<string> VS;
    public:
    vector<string> dealHands(int numPlayers, string deck) {
        VS dealHands(numPlayers);
        int n = deck.length();
        n = ((int)(n / numPlayers)) * numPlayers;
        for(int i = 0; i < n; i++){
            dealHands[i % numPlayers] += deck[i];
        }
        return dealHands;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(int numPlayers, string deck, vector<string> __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    CardCount *instance = new CardCount();
    vector<string> __result = instance->dealHands(numPlayers, deck);
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
            int numPlayers = 6;
            string deck = "012345012345012345";
            string __expected[] = {
                "000",
                "111",
                "222",
                "333",
                "444",
                "555"
            };
            return do_test(numPlayers, deck, to_vector(__expected), __no);
        }
        case 1: {
            int numPlayers = 4;
            string deck = "111122223333";
            string __expected[] = {
                "123",
                "123",
                "123",
                "123"
            };
            return do_test(numPlayers, deck, to_vector(__expected), __no);
        }
        case 2: {
            int numPlayers = 1;
            string deck = "012345012345012345";
            string __expected[] = {
                "012345012345012345"
            };
            return do_test(numPlayers, deck, to_vector(__expected), __no);
        }
        case 3: {
            int numPlayers = 6;
            string deck = "01234";
            string __expected[] = {
                "",
                "",
                "",
                "",
                "",
                ""
            };
            return do_test(numPlayers, deck, to_vector(__expected), __no);
        }
        case 4: {
            int numPlayers = 2;
            string deck = "";
            string __expected[] = {
                "",
                ""
            };
            return do_test(numPlayers, deck, to_vector(__expected), __no);
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
    cout << "CardCount (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380051188;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
