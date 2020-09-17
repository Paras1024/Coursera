#include<bits/stdc++.h>
using namespace std;
typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  edges root;
  t.push_back(root);
  int n = 0;
  for(const auto & i:patterns){
    int x = 0;
    for(const auto & j:i)
	{
      if(t[x].find(j)!=t[x].end())
	  x = t[x][j];
	  else
	  {
	  	n++;
		t[x][j] = n;
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
	int n = s.length();
	for(int i = 0;i<n;i++)
	{
		int j,x = 0;
		for( j=i;j<n;++j)
		{

			if(t[x].empty() || x>=t.size())
			{
				cout<<i<<" ";
				break;
			}
			if(t[x].find(s[j])== t[x].end())
				break;
			else
				x = t[x][s[j]];
		}
		if(j==n && t[x].empty())
		cout<<i<<" ";
		
	}
}

int main() {
  size_t n;
  string s2;
  cin>>s2;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) 
  {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  trie_matching(t,s2);
  return 0;
}
