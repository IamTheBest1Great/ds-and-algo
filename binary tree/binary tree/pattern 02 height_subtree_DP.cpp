Remove Half Nodes
https://www.geeksforgeeks.org/problems/remove-half-nodes/1

class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root==NULL)
        {
            return NULL;
        }
        root->left = RemoveHalfNodes(root->left);
        root->right= RemoveHalfNodes(root->right);
        if(root->left==NULL && root->right!=NULL)
        {
            return root->right;
        }
        else if(root->right==NULL && root->left!=NULL)
        {
            return root->left;
        }
        return root;
    }
};

---------------------------------------------------------------
110. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/description/

class Solution {
public:
    int eval(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left= eval(root->left);
        int right = eval(root->right);
        if(abs(left-right)>1)
        {
            return -1;
        }
        //wherever the height differnce more than 1 detected from there the failed state must be propogated to the root which will eventually be returned.
        if(left==-1 || right==-1)
        {
            return -1;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(eval(root)==-1)
        {
            return false;
        }
        return true;

    }
};
----------------------------------------------------------------------
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
    int dfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=dfs(root->left);
        int right=dfs(root->right);
        return 1+max(left,right);
    }
    int maxDepth(TreeNode* root) 
    {
        return dfs(root);
    }
};
----------------------------------------------------------------------------
543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/description/
class Solution {
public:
    int dfs(TreeNode *root, int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);
        ans= max(ans,left+right+1);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int ans=0;
        dfs(root,ans);
        return ans-1;
    }
};
------------------------------------------------------------------------------
222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/description/
class Solution {
public:
    void count(TreeNode *root, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        count(root->left,ans);
        ans++;
        count(root->right,ans);
    }
    int countNodes(TreeNode* root) 
    {
        int ans=0;
        count(root,ans);
        return ans;
    }
};
------------------------------------------------------------------------------
111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
class Solution {
public:
    int helper(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        if(root->left==NULL)
        {
            return 1+helper(root->right);
        }
        if(root->right==NULL)
        {
            return 1+helper(root->left);
        }
        int left=helper(root->left);
        int right=helper(root->right);
        return min(left,right)+1;

    }
    int minDepth(TreeNode* root) 
    {
        return helper(root);
    }
};
-------------------------------------------------------------------

