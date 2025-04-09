class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // If any value in nums is less than k, it's impossible to make all elements equal to k
        for (int num : nums) {
            if (num < k) return -1;
        }

        // Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());

        int operations = 0;

        // Reduce elements stepwise until all are <= k
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is already <= k, break
            if (nums[i] <= k) break;

            // Perform an operation for each unique value > k
            if (i == 0 || nums[i] != nums[i - 1]) {
                ++operations;
            }
        }

        return operations;
    }
};
