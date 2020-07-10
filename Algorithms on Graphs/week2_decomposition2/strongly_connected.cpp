#include <bits/stdc++.h>

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

void explore(int x, vector<vector<int> > &adj, bool visited[])
{
	queue<int> q;
	int i,k;
	q.push(x);
	
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		visited[x] = true;
		for(i=0;i<adj[x].size();i++)
		{
			if(!visited[adj[x][i]])
			q.push(adj[x][i]);
		}
	}
}



int number_of_strongly_connected_components(vector<vector<int> > adj,vector<vector<int> > adjt) {
  int result = 0;
  vector <int> order;
  order = toposort(adjt);
  
  bool visited[adj.size()];
  memset(visited,false,sizeof(visited));
  
  for(int i=0;i<adj.size();i++)
  {
  	if(visited[order[i]]) continue;
  	
  	result++;
  	explore(order[i],adj,visited);
  		
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>()),adjt(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjt[y -1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj,adjt);
}  
