#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &graph, vector<int> &dist) {
    int size = graph.size();
    vector<bool> visit(size, false);
    queue<pair<int,int>> q;
    q.push({1,0});
    visit[1] = true;
    
    while (!q.empty()) {
        int src = q.front().first;
        int depth = q.front().second;
        q.pop(); // pop 할 떄 주의
        dist[src] = depth;
        
        for (int i = 0; i <graph[src].size(); i++) {
            int dst = graph[src][i];
            if (!visit[dst]) {
                q.push({dst,depth+1});
                visit[dst] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < edge.size(); i++) {
        int v1 = edge[i][0];
        int v2 = edge[i][1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    vector<int> dist(n+1, -1);
    BFS(graph, dist);
    int maxNum = 0;
    for (int i = 1; i < dist.size(); i++) {
        maxNum = max(maxNum, dist[i]);
    }
    int answer = 0;
    for (int i = 1; i < dist.size(); i++) {
        if (maxNum == dist[i]) answer++;
    }
    return answer;
}
