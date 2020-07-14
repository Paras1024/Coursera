#include <bits/stdc++.h>
using namespace std;

void union1( int Arr[ ], int N, int A, int B)
{
    int TEMP = Arr[ A ];
    for(int i = 0; i < N;i++)
    {
        if(Arr[ i ] == TEMP)
        Arr[ i ] = Arr[ B ]; 
    }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int i,j,n = x.size();
  vector<double> distance;
  vector<int> u,v;

  for(i=0;i<n;i++)
  for(j=i+1;j<n;j++)
  {
  	distance.push_back(sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
  	u.push_back(i);
  	v.push_back(j);
  }
  pair<double, pair<int,int> > p[distance.size()];  
  for(i=0;i<distance.size();i++)
  {
  	p[i].first = distance[i];
  	p[i].second.first = u[i];
  	p[i].second.second = v[i];
  }
  n = distance.size();
  sort(p,p+n);
  
  
  int A[x.size()];
  for(i=0;i<x.size();i++)
  A[i] = i;
  
  vector<pair<int,int> > vp;
  pair<int,int> px;
  
  for(i=0;i<n;i++)
  {
  	if(!(A[p[i].second.first] == A[p[i].second.second]))
  	{
  		px.first = p[i].second.first;
  		px.second = p[i].second.second;
  		vp.push_back(px);
  		union1(A,x.size(),px.first,px.second);
	}
  	
  }
  for(int k=0;k<vp.size();k++)
  {
  	i = vp[k].first;
  	j = vp[k].second;
  	result+= sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
  }
  
  
  
  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
