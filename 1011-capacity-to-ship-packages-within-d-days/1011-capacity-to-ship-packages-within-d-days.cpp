class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(),weights.end());
        int end=accumulate(weights.begin(),weights.end(),0);
        int mid;
        int ans;
        if(weights.size()<days){
            return 0;
        }
        while(start<=end){
            mid=(start+end)/2;
            int packages=0;
            int count=0;
            for(int i=0;i<weights.size();i++){
               packages=packages+weights[i];
               if(packages>mid){
                count++;
                packages=weights[i];
               }
            }
            if(count<days){
                ans=mid;
               end=mid-1; 
            }
            else{
                start=mid+1;
            }
            

        } return ans;
        
    }
};