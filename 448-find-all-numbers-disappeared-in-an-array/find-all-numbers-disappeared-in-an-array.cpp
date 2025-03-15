class Solution {
    public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) { // number missing
                ans.push_back(i);
            }
        }
        return ans;
    }
};