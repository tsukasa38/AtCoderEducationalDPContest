#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> p(N);
    for(int i = 0; i < N; ++i) { cin >> p.at(i); } 

    vector<vector<double>> dp(N+1, vector<double>(N+1, 0));
    dp.at(0).at(0) = 1;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= N; ++j) {
            dp.at(i+1).at(j) += dp.at(i).at(j) * (1.0 - p.at(i));
            if(j+1 <= N) { dp.at(i+1).at(j+1) += dp.at(i).at(j) * p.at(i); }
        }
    }

    double ans = 0;
    for(int i = ((N+1)/2); i <= N; ++i) { ans += dp.at(N).at(i); }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
