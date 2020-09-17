#include <bits/stdc++.h>
using namespace std;

vector<int> computePrefixFunction(string p){
	vector<int> s(p.length(),0);
	int border = 0;
	for(int i=1;i<p.length();i++)
	{
		while(border>0 && p[i]!=p[border])
			border = s[border-1];
		if(p[i]==p[border])
			border++;
		else
			border = 0;
		s[i] = border;
	}
	return s;
}

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  string s = pattern + "$" + text;
  vector<int> v(s.length());
  v = computePrefixFunction(s);
 // for(auto i:v) cout<<i<<" ";
  for(int i = pattern.length()+1;i<s.length();i++)
  	if(v[i]==pattern.length())
  		result.push_back(i-2*pattern.length());
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
