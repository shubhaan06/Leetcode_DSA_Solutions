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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        inorderHelper(root, ans);
        return ans;
    }

private:
    void inorderHelper(TreeNode* node, vector<int>& ans) 
    {
        if (node != nullptr) 
        {
            inorderHelper(node->left, ans);   // Traverse left subtree
            ans.push_back(node->val);           // Visit the root node
            inorderHelper(node->right, ans);  // Traverse right subtree
        }
    }
};