class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        int mid;
        int ans=arr[0];
        while(start<=end){
            mid=(start+end)/2;
            if(arr[0]<=arr[mid]){
                start=mid+1;
            }
            else{
                ans=arr[mid];
                end=mid-1;
            }
        }return ans;
        
    }
};