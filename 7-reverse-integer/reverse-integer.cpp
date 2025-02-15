class Solution {
public:
    int reverse(int x) 
    {
        long reversed=0;
         while(x!=0)
        {
             
            int digit=x%10; //d=3
            reversed=reversed*10+digit;//r=0*10+3=3
            x/=10;//x=123/10=120

        } 
        if(reversed>INT_MAX || reversed<INT_MIN) 
        return 0;
       return reversed; 
        
    }
};