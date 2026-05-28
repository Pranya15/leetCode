class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int,int> mp;

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--) {

            // Remove smaller elements
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            // If stack empty -> no greater element
            if(st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }

            // Push current element
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Get answers for nums1
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};