#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> w(N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i) { cin >> w.at(i) >> v.at(i); }

    vector<vector<long long>> dp(N+1, vector<long long>(W+1, -1));
    dp.at(0).at(0) = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= W; ++j) {
            if(dp.at(i).at(j) == -1) { continue; }

            dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j));

            if(j + w.at(i) <= W) { dp.at(i+1).at(j+w.at(i)) = max(dp.at(i+1).at(j+w.at(i)), dp.at(i).at(j) + v.at(i)); }
        }
    }

    long long max_num = 0;
    for(int i = 0; i <= W; ++i) { max_num = max(max_num, dp.at(N).at(i)); }

    cout << max_num << endl;

    return 0;
}
