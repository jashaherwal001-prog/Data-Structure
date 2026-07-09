class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax[n];
        int rightMax[n];
        vector<int>ans(n);
        //left max sum
        leftMax[0]=0;
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i-1]);
        }
        //Right Max sum
        rightMax[n-1]=0;
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i+1]);
        }
        //for ans
        int minimum;
        for(int i=0;i<n;i++){
        minimum=(min(leftMax[i],rightMax[i]));
        if(minimum-height[i]>=0){
            ans[i]=minimum-height[i];
        }
        else{
            ans[i]=0;
        }
        }
        int sumOfans=accumulate(ans.begin(),ans.end(),0);

        return sumOfans;

    }
};