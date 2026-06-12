/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {

            int currSize = q.size();

            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for (int i = 0; i < currSize; i++) {

                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                unsigned long long idx = curr.second - stIdx;

                if (node->left) {
                    q.push({node->left, 2 * idx + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
        }

        return maxWidth;
    }
};