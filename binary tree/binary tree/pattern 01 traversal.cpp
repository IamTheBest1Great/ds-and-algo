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

-----------------------------------------------------------------
101. Symmetric Tree
    https://leetcode.com/problems/symmetric-tree/description/
    

class Solution {
public:
    bool helper(TreeNode *root1, TreeNode *root2)
    {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if((root1==NULL && root2!=NULL)|| (root1!=NULL && root2==NULL))
        {
            return false;
        }
        if(root1!=root2)
        {
            return false;
        }
        return helper(root1->left,root2->right)&&helper(root1->right && root2->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return false;
        }    
        return helper(root1,root2);
    }
};
---------------------------------------------------------------

Invert Binary Tree
    https://leetcode.com/problems/invert-binary-tree/description/
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

------------------------------------------------------------
Binary Tree Right Side View
    
https://leetcode.com/problems/binary-tree-right-side-view/submissions/1881737947/

    class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }    
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(i==n-1)
                {
                    ans.push_back(temp->val);
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};

---------------------------------------------------------------------------------
    
