class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(arr[mid]==key){
                return mid;
                break;
            }
            else if(arr[mid]<key){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;

        
    }
};