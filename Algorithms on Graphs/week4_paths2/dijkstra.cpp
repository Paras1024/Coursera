#include <bits/stdc++.h>

using namespace std;

int extract_min(int dist[],int n,bool in_set[])
{
	int min_value = 99999999;
	
	for(int i=0;i<n;i++)
	if(min_value>dist[i] && !in_set[i])
	min_value = dist[i];
	
	for(int i=0;i<n;i++)
	if(min_value==dist[i] && !in_set[i])
	return i;
}

bool full(bool in_set[],int n)
{
	for(int i =0;i<n;i++)
	if(!in_set[i])
	return false;
	return true;
}


int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  
  int dist[adj.size()];
  for(int i=0;i<adj.size();i++)
  dist[i] = 99999999;
  
  bool in_set[adj.size()];
  memset(in_set,false,sizeof(in_set));
  
  dist[s] = 0;
  while( !full(in_set,adj.size()))
  {
  	int u = extract_min(dist,adj.size(),in_set);
  	in_set[u] = true;
  	for(int i=0;i<adj[u].size();i++)
  		if(dist[adj[u][i]] > dist[u] + cost[u][i])
  		dist[adj[u][i]] = dist[u] + cost[u][i];
  }
  if(dist[t]<99999999)
  return dist[t];
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
