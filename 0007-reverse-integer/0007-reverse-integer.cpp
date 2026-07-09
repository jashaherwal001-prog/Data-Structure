class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int num=x;
        int rem;
           while(num!=0){
           rem=num%10;
           num=num/10;
           if(ans>INT_MAX/10||ans<INT_MIN/10){
            return 0;
           }
           ans=rem+ans*10;
       }return ans;
    }
};