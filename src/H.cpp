#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    for(int i = 0; i < H; ++i) { for(int j = 0; j < W; ++j) { cin >> a.at(i).at(j); }}

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp.at(0).at(0) = 1;

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(a.at(i).at(j) == '#') { continue; }
            if(i+1 < H) { (dp.at(i+1).at(j) += dp.at(i).at(j)) %= MOD; }
            if(j+1 < W) { (dp.at(i).at(j+1) += dp.at(i).at(j)) %= MOD; }
        }
    }

    cout << dp.at(H-1).at(W-1) << endl;

    return 0;
}
