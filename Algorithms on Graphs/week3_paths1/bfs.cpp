#include <bits/stdc++.h>

using namespace std;
int distance(vector<vector<int> > &adj, int s, int t) {
  
  int dist[adj.size()];
  memset(dist,-1,sizeof(dist));
  
  queue<int> q;
  
  q.push(s);
  dist[s] = 0;
  
  while(!q.empty())
  {
  	s = q.front();
  	q.pop();
  	for(int i = 0; i<adj[s].size();i++)
  	{
  	   if(dist[adj[s][i]]==-1)
  	   {
  	   	  q.push(adj[s][i]);
  	   	  dist[adj[s][i]] = dist[s] + 1;
	   }
	}
  }
  
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
