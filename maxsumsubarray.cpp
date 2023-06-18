class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int N){
        // code here 
        long long i=0, j=0, sum=0;
        long long maxi=INT_MIN;
        while(j<N){
            sum+=Arr[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                maxi=max(maxi, sum);
                sum-=Arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};
