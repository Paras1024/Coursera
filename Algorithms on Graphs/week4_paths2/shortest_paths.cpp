#include <bits/stdc++.h>
using namespace std;

void reachability(vector<vector<int> > &adj, vector<int> &reachable,int s)
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		reachable[s] = 1;
		for(int i=0;i<adj[s].size();i++)
		{
			if(reachable[adj[s][i]]==0)
			q.push(adj[s][i]);
		}
	}	
}
void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  
  distance[s] = 0;
  reachability(adj,reachable,s);

  queue<int> q;
  for(int j=0;j<adj.size();j++)
  for(int u=0;u<adj.size();u++)
  for(int i=0;i<adj[u].size();i++)
  if(distance[u]!=std::numeric_limits<long long>::max() && distance[adj[u][i]] > distance[u] + cost[u][i])
  distance[adj[u][i]] = distance[u] + cost[u][i];

  for(int u=0;u<adj.size();u++)
  for(int i=0;i<adj[u].size();i++)
  if(distance[u]!=std::numeric_limits<long long>::max() && distance[adj[u][i]] > distance[u] + cost[u][i])
  q.push(adj[u][i]);
  	
  	
  while(!q.empty())
  {
  	s = q.front();
  	q.pop();
  	shortest[s] = 0;
	for(int i=0;i<adj[s].size();i++)
	{
		if(shortest[adj[s][i]]==1)
		q.push(adj[s][i]);
	}
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
