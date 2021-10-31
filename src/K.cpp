#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 0; i < N; ++i) { cin >> a.at(i); }

    vector<bool> dp(K+1, false);

    for(int i = 0; i <= K; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i + a.at(j) <= K && !dp.at(i)) { dp.at(i + a.at(j)) = true; }
        }
    }

    cout << (dp.at(K) ? "First" : "Second") << endl;

    return 0;
}
