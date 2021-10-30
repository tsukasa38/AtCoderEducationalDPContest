#include <vector>
#include <iostream>
using namespace std;

using Graph = vector<vector<int>>;

int longest_path_length(Graph &graph, vector<int> &dp, int s) {
    if(dp.at(s) != -1) { return dp.at(s); }

    int ans = 0;
    int edge_num = graph.at(s).size();

    for(int i = 0; i < edge_num; ++i) {
        int g = graph.at(s).at(i);
        ans = max(ans, longest_path_length(graph, dp, g) + 1);
    }

    dp.at(s) = ans;
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edge(M, vector<int>(2));
    for(int i = 0; i < M; ++i) { cin >> edge.at(i).at(0) >> edge.at(i).at(1); }

    Graph graph(N+1);
    for(int i = 0; i < M; ++i) {
        int s = edge.at(i).at(0);
        int g = edge.at(i).at(1);
        graph.at(s).push_back(g);
    }

    vector<int> dp(N+1, -1);

    int ans = 0;

    for(int i = 1; i <= N; ++i) {
        ans = max(ans, longest_path_length(graph, dp, i));
    }

    cout << ans << endl;

    return 0;
}
