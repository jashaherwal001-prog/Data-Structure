class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start;
        int end;
        int mid;
        int x;
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
            start=i+1;
            end=nums.size()-1;
            x=target-nums[i];
        
            while(start<=end){
                mid=(start+end)/2;
                if(nums[mid]==x){
                    x=nums[mid];
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    break;
                }
               
                else if(nums[mid]>x){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }

            }
        } return ans;
        
    }
};