class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n;i++)v[i]=i;
        for(int i=0;i<n;i++)if(v[i]!=nums[i])return v[i];
        return v[n];
    }
};