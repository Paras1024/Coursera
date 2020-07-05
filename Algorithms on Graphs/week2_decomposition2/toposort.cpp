// https://www.youtube.com/watch?v=AfSk24UTFS8
// Use the above link for the algorithm

#include<bits/stdc++.h>
using namespace std;
void dfs_visit(vector<vector<int> > &adj, int s,int parent[], vector<int> &order)
{
	
	for(int i = 0; i<adj[s].size(); i++ )
	{
		if(parent[adj[s][i]] == -2)
		{
			parent[adj[s][i]] = s;
			
			dfs_visit(adj,adj[s][i],parent,order);
		}	
	}
	order.push_back(s);
}

vector<int> toposort(vector<vector<int> > &adj) 
{
	int parent[adj.size()];
	
	for(int i=0;i<adj.size();i++)
	parent[i] = -2;
	
	vector<int> order;
	
	for(int i=0;i<adj.size();i++)
	{
		if(parent[i]==-2)
		{
			parent[i]=-1;
			dfs_visit(adj,i,parent,order);
		}
	}
	reverse(order.begin(),order.end());
	return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
