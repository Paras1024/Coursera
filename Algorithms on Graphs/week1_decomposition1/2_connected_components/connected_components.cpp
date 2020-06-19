#include<bits/stdc++.h>
using namespace std;

int number_of_components(vector<vector<int> > &adj) {
	int i,j,k,m,x;
	int res = 0;
	
	//dn = discovered node
  
	bool dn[adj.size()];
	bool visited[adj.size()];
	memset(dn, false, sizeof(dn)); 
	memset(visited, false, sizeof(visited)); 
  
  
	queue <int> q;
  
	for(j=0;j<adj.size();j++)
	{	
		if(dn[j])
		continue;

		x=j;
		res++;
			
		dn[x] = true;
		for(i=0;i<adj[x].size();i++)
		{
			q.push(adj[x][i]);
			dn[adj[x][i]] = true;
		}
		visited[x] = true;
  
		while( !q.empty() )
		{
			int n = q.front();
  	 	    q.pop();
	
  			for(i=0;i<adj[n].size();i++)
  			{
  			
				if(visited[adj[n][i]]||dn[adj[n][i]])
  				continue;
  			
  				q.push(adj[n][i]);
  				dn[adj[n][i]] = true;
			}
			visited[n]=true;
		}
    } 

	return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
