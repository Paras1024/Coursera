#include <bits/stdc++.h>
using namespace std;

int bipartite(vector<vector<int> > &adj) {

	
	int dist[adj.size()];
	memset(dist,-1,sizeof(dist));
	
	queue<int> q;
	int s = 0;
	for(int k = 0; k<adj.size();k++)
	{
		if(dist[k]!=-1) continue;
		s = k;
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
	}
	int color[adj.size()];
	for(int i=0;i<adj.size();i++)
	{
		color[i] = dist[i]%2;
	}
	
	for(int i = 0; i<adj.size();i++)
	{
		for(int j = 0; j<adj[i].size();j++)
		if(color[i]==color[adj[i][j]])
		return 0;
	}
	
	
	return 1;
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
	std::cout << bipartite(adj);
}
