100. Same Tree

https://leetcode.com/problems/same-tree/description/

class Solution {
public:
    void dfs(TreeNode* p, TreeNode* q, bool &ans)
    {
        if(p==NULL && q==NULL)
        {
            return;
        }
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
        {
            ans=false;
            return;
        }
        if(p->val!=q->val)
        {
            ans=false;
            return;
        }
        dfs(p->left,q->left,ans);
        dfs(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=true;
        dfs(p,q,ans);
        return ans;
    }
};
---------------------------------------------------------------------------
