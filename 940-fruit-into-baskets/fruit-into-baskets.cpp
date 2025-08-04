class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int i=0,j=0,n=fruits.size(),maxi=0;
        unordered_map<int,int>m;
        while(j<n)
        {
            m[fruits[j]]++;
            while(m.size()>2){
                if(--m[fruits[i]]==0)m.erase(fruits[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
        
    }
};