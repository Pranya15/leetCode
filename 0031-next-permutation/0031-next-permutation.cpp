class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find break point
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If break point exists
        if (i >= 0) {
            int j = n - 1;
            
            // Find just greater element
            while (nums[j] <= nums[i]) {
                j--;
            }
            
            // Step 3: Swap
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse right part
        reverse(nums.begin() + i + 1, nums.end());
    }
};