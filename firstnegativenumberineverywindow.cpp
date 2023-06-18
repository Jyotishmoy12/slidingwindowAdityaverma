#include<bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	int i=0, j=0;
	vector<int>ans;
	deque<int>q;
	while(j<n){
		if(arr[j]<0){
			q.push_back(arr[j]);
		}
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			if(q.size()==0){
				ans.push_back(0);
			}else{
				ans.push_back(q.front());
				if(arr[i]<0){
					q.pop_front();
				}
			}
			i++;
			j++;
		}
	}
	return ans;
}
