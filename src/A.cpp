#include <vector>
#include <iostream>
using namespace std;

const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;

    vector<int> h(N);
    for(int i = 0; i < N; ++i) { cin >> h.at(i); }

    vector<int> dp(N, INF);
    dp.at(0) = 0;

    for(int i = 0; i < N; ++i) {
        if(i+1 < N) { dp.at(i+1) = min(dp.at(i+1), dp.at(i) + abs(h.at(i) - h.at(i+1))); }
        if(i+2 < N) { dp.at(i+2) = min(dp.at(i+2), dp.at(i) + abs(h.at(i) - h.at(i+2))); }
    }

    cout << dp.at(N-1) << endl;

    return 0;
}
