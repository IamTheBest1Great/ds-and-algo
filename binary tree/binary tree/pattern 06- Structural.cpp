617. Merge Two Binary Trees

https://leetcode.com/problems/merge-two-binary-trees/description/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
        {
            return root2;
        }
        if(!root2)
        {
            return root1;
        }
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left, root2->left);
        root1->right=mergeTrees(root1->right, root2->right);
        return root1;
    }
};

---------------------------------------------------------------------------------------
226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode *temp = new TreeNode;
        temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
