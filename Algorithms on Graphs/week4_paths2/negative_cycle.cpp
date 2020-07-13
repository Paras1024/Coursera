#include <bits/stdc++.h>

using namespace std;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  
  int dist[adj.size()];
  for(int i=0;i<adj.size();i++)
  dist[i] = 99999999;
  
  
  for(int j=1;j<=adj.size()-1;j++)
  {
  	for(int u=0;u<adj.size();u++)
  	for(int i=0;i<adj[u].size();i++)
  		if(dist[adj[u][i]] > dist[u] + cost[u][i])
  		dist[adj[u][i]] = dist[u] + cost[u][i];
  }
  for(int u=0;u<adj.size();u++)
  	for(int i=0;i<adj[u].size();i++)
  		if(dist[adj[u][i]] > dist[u] + cost[u][i])
  		return 1;
  
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
