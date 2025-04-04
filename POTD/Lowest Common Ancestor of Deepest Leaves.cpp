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
        pair<int, TreeNode*> helper(TreeNode* node) {
            if (!node) return {0, nullptr};
            
            auto [ld, ln] = helper(node->left);
            auto [rd, rn] = helper(node->right);
            
            if (ld > rd) return {ld + 1, ln};
            if (ld < rd) return {rd + 1, rn};
            return {ld + 1, node};
        }
        
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return helper(root).second;
        }
    };
    