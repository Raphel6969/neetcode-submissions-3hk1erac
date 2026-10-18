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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        deque<TreeNode*> q;
        q.push_back(root);

        while(!q.empty()) {
            int qLen = q.size();
            vector<int> lvl;
            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                lvl.push_back(node->val);

                if (node->left != nullptr) q.push_back(node->left);
                if (node->right != nullptr) q.push_back(node->right);
            }
            ans.push_back(lvl);
        }

        return ans;
    }
};
