class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        // Previous Smaller Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long maxArea = 0;

        for(int i = 0; i < n; i++) {
            long long width = right[i] - left[i] - 1;
            long long area = 1LL * heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};