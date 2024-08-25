/**
 * //Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 **/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }

private:
    void postorderHelper(TreeNode* node, vector<int>& ans) 
    {
        if (node != nullptr) 
        {
            postorderHelper(node->left, ans);   // Traverse left subtree
            postorderHelper(node->right, ans);  // Traverse right subtree
            ans.push_back(node->val);           // Visit the root node
        }
    }
};