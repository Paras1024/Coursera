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

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
