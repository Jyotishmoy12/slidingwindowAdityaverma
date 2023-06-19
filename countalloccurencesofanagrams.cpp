class Solution{
public:
	int search(string p, string s) {
	    int k=p.size();
	   unordered_map<char, int>mp;
      for(auto &x:p){
          mp[x]++;
      }
      int ans=0;
      int i=0, j=0;
      int count=mp.size();
      while(j<s.size()){
          if(mp.find(s[j])!=mp.end()){
              mp[s[j]]--;
              if(mp[s[j]]==0){
                  count--;
              }
          }
          if(j-i+1<k){
              j++;
          }
         else if(j-i+1==k){
             if(count==0){
                 ans++;
             }
             if(mp.find(s[i])!=mp.end()){
                 mp[s[i]]++;
                 if(mp[s[i]]==1){
                     count++;
                 }
             }
             i++;
             j++;
         }
      }
      return ans;
	}

};

