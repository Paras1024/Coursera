#include <bits/stdc++.h>
using namespace std;

void updateClasses(int newOrder[],int classes[],int newClasses[],int l,int n){
	newClasses[newOrder[0]] = 0;
	for(int i=1;i<=n-1;i++){
		int cur = newOrder[i];
		int prev = newOrder[i-1];
		int mid = cur+l;
		int midPrev = (prev+l)%n;
		if(classes[cur]!=classes[prev] || classes[mid]!=classes[midPrev])
			newClasses[cur] = newClasses[prev]+1;
		else
			newClasses[cur] = newClasses[prev];
	}
	
}

void sortDoubled(string s,int l,int order[],int classes[],int newOrder[]){
	int count[s.length()];
	memset(count,0,sizeof(count));
	
	for(int i=0;i<s.length();i++)
		count[classes[i]]++;
		
	for(int j=0;j<s.length();j++)
		count[j] += count[j-1];
	
	for(int i=s.length()-1;i>=0;i--){
		int start = order[i] - l + s.length();
		start = start%(s.length());
		
		int cl = classes[start];
		count[cl]--;
		
		newOrder[count[cl]] = start;
	}
}

void computeCharClasses(string s,int order[], int classes[]){
	classes[order[0]] = 0;
	for(int i=1;i<s.length();i++){
		if(s[order[i]] != s[order[i-1]])
			classes[order[i]] = classes[order[i-1]]+1;
		else
			classes[order[i]] = classes[order[i-1]];
	}	
}


void sortCharacters(string s,int order[])
{
	int count[5] = {0,0,0,0,0};
	map<char,int> m;
	m.insert({'$',0});
	m.insert({'A',1});
	m.insert({'C',2});
	m.insert({'G',3});
	m.insert({'T',4});
	
	for(int i=0;i<s.length();i++)
		count[m[s[i]]]++;
		
	for(int j=1;j<=4;j++)
	count[j]+=count[j-1];
	
	for(int i=s.length()-1;i>=0;i--)
	{
		int c = m[s[i]];
		count[c]--;
		order[count[c]] = i;
	}
}
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  
  int order[text.length()],newOrder[text.length()];
  int classes[text.length()],newClasses[text.length()];
  
  sortCharacters(text,order);
  computeCharClasses(text,order,classes);
  
  int l = 1;
  while(l<text.length()){
  	sortDoubled(text,l,order,classes,newOrder);
  	for(int i=0;i<text.length();i++)
  		order[i] = newOrder[i];
  	updateClasses(order,classes,newClasses,l,text.length());
  	for(int i=0;i<text.length();i++)
  		classes[i] = newClasses[i];
  	
  	l*=2;
  }
  for(int i=0;i<text.length();i++)
  		result.push_back(order[i]);
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
