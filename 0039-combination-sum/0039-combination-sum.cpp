class Solution {
public:
    
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans) {
        
        // Base Case
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Traverse all candidates starting from idx
        for (int i = idx; i < candidates.size(); i++) {

            // If current number is greater than target, skip
            if (candidates[i] > target)
                continue;

            // Choose current element
            temp.push_back(candidates[i]);

            // Recur with same index because element can be reused
            solve(i, candidates, target - candidates[i], temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};