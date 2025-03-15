class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            for(int j=0;j<nums.size();j++){
                if(i!=j && nums[j]<element){
                    count++;
                }
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};