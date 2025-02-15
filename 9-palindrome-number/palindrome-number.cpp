class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
        {
            return false;
        }
        int original=x;
        long r=0;
        while(x!=0)
         
        {
             
            int d=x%10;//121%10=1
            r=(r*10)+d;//r=0*10+1=1
            x/=10; //x=121/10 
                 
            
        }
        return r==original;
         

        
    }
};