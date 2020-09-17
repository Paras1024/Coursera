#include <bits/stdc++.h>
using namespace std;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position 
//       of this character in the sorted array of 
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
void PreprocessBWT(const string& bwt, 
                   map<char, int>& starts, 
                   map<char, vector<int> >& m) {
                   	
                   	
    int n = bwt.length();
    string s = bwt;
    sort(s.begin(),s.end());
 	for(int i=0;i<n;i++)
 	{
 		if(starts.find(s[i])==starts.end())
		 starts.insert({s[i],i});	
	}
	//for(auto i:starts) cout<<i.first<<" "<<i.second<<endl;
	vector<int> v(n+1,0);
	m.insert({'A',v});
	m.insert({'G',v});
	m.insert({'T',v});
	m.insert({'C',v});
	m.insert({'$',v});
	for(auto c:{'A','G','T','C','$'})
	{
		int x=0;
		for(int i=0;i<=n;i++)
		{
			if(i==n)
			m[c][i] = x;
			else
			{
				m[c][i]=x;
				if(bwt[i]==c)
				x++;
			}
		}
	}
	/*	
	for(auto c:m)
	{
		for(auto i:c.second) cout<<i<<" ";
		cout<<endl;
	}
	*/
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string& pattern, 
                     const string& bwt, 
                      map<char, int>& starts, 
                      map<char, vector<int> >& occ_count_before) {
  // Implement this function yourself
  int n = bwt.length();
  int top = 0;
  int bottom  = n-1;
  string p = pattern;
  while(top<=bottom)
  {
  	if(p.length()>0)
  	{
  		char sym = p[p.length()-1];
  		p.pop_back();
  		if(occ_count_before[sym][top] < occ_count_before[sym][bottom+1]){
  			top		=	starts[sym] + occ_count_before[sym][top];
  			bottom 	= 	starts[sym] + occ_count_before[sym][bottom+1]-1;
		}
		else	return 0;  
  		
	}
	else return bottom-top+1;
  }
  
  
  
  
  return 0;
}
     

int main() {
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    printf("%d ", occ_count);
  }
  printf("\n");
  return 0;
}
