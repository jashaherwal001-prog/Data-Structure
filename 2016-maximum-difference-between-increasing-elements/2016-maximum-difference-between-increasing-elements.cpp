class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int suffix_max=INT_MIN;
        int n=nums.size();
        int suffix_arr[n];
        int ans;
        for(int i=n-1;i>=0;i--){
            suffix_arr[i]=max(nums[i],suffix_max);
            suffix_max=suffix_arr[i];
        }
        // for arr[i] int ans= suffix[i+1]
        int ans_max=-1;
        for(int i=0;i<n-1;i++){
        if(nums[i]<suffix_arr[i+1]){
          ans=suffix_arr[i+1]-nums[i];
          ans_max=max(ans_max,ans);
            }
        }
        return ans_max;
    }
};