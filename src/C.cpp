#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> happiness(N, vector<int>(3));
    for(int i = 0; i < N; ++i) { for(int j = 0; j < 3; ++j) { cin >> happiness.at(i).at(j); }}

    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp.at(0).at(0) = happiness.at(0).at(0);
    dp.at(0).at(1) = happiness.at(0).at(1);
    dp.at(0).at(2) = happiness.at(0).at(2);

    for(int i = 0; i < N-1; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(j == 0) {
                dp.at(i+1).at(1) = max(dp.at(i+1).at(1), dp.at(i).at(j) + happiness.at(i+1).at(1));
                dp.at(i+1).at(2) = max(dp.at(i+1).at(2), dp.at(i).at(j) + happiness.at(i+1).at(2));
            }
            if(j == 1) {
                dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(j) + happiness.at(i+1).at(0));
                dp.at(i+1).at(2) = max(dp.at(i+1).at(2), dp.at(i).at(j) + happiness.at(i+1).at(2));
            }
            if(j == 2) {
                dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(j) + happiness.at(i+1).at(0));
                dp.at(i+1).at(1) = max(dp.at(i+1).at(1), dp.at(i).at(j) + happiness.at(i+1).at(1));
            }
        }
    }

    int max_num = 0;
    for(int i = 0; i < 3; ++i) { max_num = max(max_num, dp.at(N-1).at(i)); }

    cout << max_num << endl;

    return 0;
}
