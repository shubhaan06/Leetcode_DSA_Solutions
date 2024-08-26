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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        preorderHelper(root, ans);
        return ans;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& ans) 
    {
        if (node != nullptr) 
        {
            ans.push_back(node->val);           // Visit the root node
            preorderHelper(node->left, ans);   // Traverse left subtree
            preorderHelper(node->right, ans);  // Traverse right subtree
        }
    }
};