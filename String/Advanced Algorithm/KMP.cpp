bool repeatedSubstringPattern(string s) {
  //KMP ALGORITHM
  int n = s.size();    
  vector<int> lps(n,0);
  for(int i=1,j=0;i<n;){
      if(s[i]==s[j]){
        lps[i++] = ++j; //incase there is a match, increment j pointer to check the next index in the next iteration 
      }
      else if(j>0){
          j = lps[j-1]; //smart skipping
      }
      else{
          lps[i++] = 0; 
      }
  }
  int last = lps[n-1]; //for valid repeating pattern, last must be equal to (n-1)
  return (last>0)&&(n%(n-last)==0);
}
