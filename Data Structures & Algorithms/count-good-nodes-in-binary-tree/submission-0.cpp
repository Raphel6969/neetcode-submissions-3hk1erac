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
    int dfs(TreeNode* root, int compNode){
        bool isGood = false;
        if(root == nullptr) return 0;

        if(root->val >= compNode){
            isGood = true;
        }
        compNode = max(root->val, compNode);
        int left = dfs(root->left, compNode);
        int right = dfs(root->right, compNode);

        return isGood + left + right;
    }
    int goodNodes(TreeNode* root) {
        int compNode = root->val;
        int ans = dfs(root, compNode);
        return ans;
    }
};
