class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=1;
        int n=nums.size();
        int end=n-1;
        int mid;
        int ans;
        if(nums.size()==1){
            ans=nums[0];
            return ans;
        }
        if(nums[0]!=nums[1]){
            ans=nums[0];
            return ans;
        }
        if(nums[n-1]!=nums[n-2]){
            ans=nums[n-1];
            return ans;
        }
        while(start<=end){
        mid=(start+end)/2;
        if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
            ans=nums[mid];
            return ans;
        }
        if((nums[mid]==nums[mid-1] && (mid%2!=0))||(nums[mid]==nums[mid+1]&&(mid%2==0))){
            start=mid+1;
        }
        else{
            end=mid-1;
        }


        } return -1;
        
        
        }
};