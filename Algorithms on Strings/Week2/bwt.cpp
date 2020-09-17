#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
    string result = "";
    string s2 = text;
	vector<string> v;
	int n = s2.length();
	for(int i=0;i<n;i++)
		v.push_back(s2.substr(i,n-i)+s2.substr(0,i));
	sort(v.begin(),v.end());
  	for(auto i:v)
  	result+=i[n-1];

  	return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
