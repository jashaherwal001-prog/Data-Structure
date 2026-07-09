class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans;
        int mid;
        if(nums.size()<k){
            return 0;
        }
        while(start<=end){
            mid=(start+end)/2;
            int count=1;
            int min_sum=0;
            for(int i=0;i<nums.size();i++){
                min_sum=min_sum+nums[i];
                if(min_sum>mid){
                    count++;
                    min_sum=nums[i];
                }
            }
                if(count<=k){
                    ans=mid;
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            
        }return ans;
        
    }
};