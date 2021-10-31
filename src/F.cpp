#include <vector>
#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int N = s.size();
    int M = t.size();

    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(s.at(i) == t.at(j)) { dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j+1), dp.at(i).at(j) + 1); }
            else { dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j), dp.at(i).at(j+1)); }
        }
    }

    int i = N;
    int j = M;
    int len = dp.at(N).at(M);

    string ans(len, ' ');

    while(len > 0) {
        if(s.at(i-1) == t.at(j-1)) {
            ans.at(len-1) = s.at(i-1);
            len--;
            i--;
            j--;
        }else if(dp.at(i).at(j) == dp.at(i-1).at(j)) {
            i--;
        }else if(dp.at(i).at(j) == dp.at(i).at(j-1)) {
            j--;
        }
    }

    cout << ans << endl;

    return 0;
}
