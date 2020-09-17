#include<bits/stdc++.h>
using namespace std;
typedef map<char, pair<int,bool> > edges;
typedef vector<edges> trie;

trie build_trie(vector<edges> &t, vector<string> & patterns) {
  
  edges root;
  t.push_back(root);
  int n = 0;
  for(const auto & i:patterns){
    int x = 0;
    for(int j = 0;j<i.length();j++)
	{
      if(t[x].find(i[j])!=t[x].end())
	  {
	  	if(j == i.length()-1)
	  	t[x][i[j]].second = true;
	  	x = t[x][i[j]].first;
	  	
	  }
	  else
	  {
	  	n++;
		t[x][i[j]].first = n;
		t[x][i[j]].second = false;
		edges e;
		t.push_back(e);
		x = n;
      }
    }
  }
  return t;
}
void trie_matching(vector<edges> &t,string s)
{
	vector<int> v;
	int n = s.length();
	for(int i = 0;i<n;i++)
	{
		int j,x = 0;
		for( j=i;j<n;++j)
		{

			if(t[x].empty() || x>=t.size())
			{
				v.push_back(i);
				break;
			}
			
			if(t[x].find(s[j])== t[x].end())
				break;
			else
				if(t[x][s[j]].second)
				v.push_back(i);
				x = t[x][s[j]].first;
		}
		if(j==n && t[x].empty())
		v.push_back(i);
		
	}
	n = v.size();
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		if(i!=0 && v[i] == v[i-1])
		continue;
		cout<<v[i]<<" ";
	}
}

int main() {
  size_t n;
  string s2;
  cin>>s2;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

	trie t;
	build_trie(t,patterns);
	build_trie(t,patterns);
	trie_matching(t,s2);
	return 0;
}
