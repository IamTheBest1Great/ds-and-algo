145. Binary Tree Postorder Traversal

class Solution {
public:
    void eval(TreeNode *root, vector<int> &postorder)
    {
        if(root==NULL)
        {
            return;
        }
        eval(root->left,postorder);
        eval(root->right,postorder);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> postorder;
        eval(root,postorder);
        return postorder;
    }
};

-----------------------------------------------------------------
94. Binary Tree Inorder Traversal

95. class Solution {
public:
    void eval(TreeNode* root, vector<int> &inorder)
    {
        if(root==NULL)
        {
            return;
        }
        eval(root->left, inorder);
        inorder.push_back(root->val);
        eval(root->right,inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> inorder;
        eval(root, inorder);
        return inorder;
    }
};

-------------------------------------------------------------
144. Binary Tree Preorder Traversal

class Solution {
public:
    void eval(TreeNode *root, vector<int> &preorder)
    {
        if(root==NULL)
        {
            return;
        }    
        preorder.push_back(root->val);
        eval(root->left,preorder);
        eval(root->right,preorder);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> preorder;
        eval(root,preorder);

        return preorder;
    }
};
