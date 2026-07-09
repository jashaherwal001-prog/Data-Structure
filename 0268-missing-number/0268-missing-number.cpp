class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
        int sum=0;
        for(int i=0;i<=n-1;i++){
            sum=nums[i]+sum;
        }
        int ans =n*(n+1)/2;
     ans=ans-sum;
     return ans;
        
    }
};