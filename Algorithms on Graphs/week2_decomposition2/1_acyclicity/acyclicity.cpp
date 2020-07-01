#include<bits/stdc++.h>
using namespace std;


bool dfs_visit(vector<vector<int> > &adj, int v, int color[])
{
	color[v]++;
	for(int i = 0;i<adj[v].size();i++)
	{
		if(color[adj[v][i]]==2)
		continue;
		if(color[adj[v][i]]==1)
		return true;
		if(dfs_visit(adj,adj[v][i],color))
		return true;
	}
	color[v]++;
	return false;
}

int acyclic(vector<vector<int> > &adj) 
{
	int color[adj.size()];
	memset(color,0,sizeof(color));
	for(int i = 0;i<adj.size();i++)
	{
		if(color[i]==0)
		{
			if(dfs_visit(adj,i,color))
			return 1;
		}
	}
	return 0;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
