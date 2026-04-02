112. Path Sum
https://leetcode.com/problems/path-sum/description/

class Solution {
public:
    void dfs(TreeNode *root, int temp, vector<int> &sum)
    {
        if(root==NULL)
        {
            return;
        }
        temp+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum.push_back(temp);
            return;
        }
        dfs(root->left,temp,sum);
        dfs(root->right,temp,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int temp=0;
        vector<int> sum;
        dfs(root,temp,sum);
        for(int i=0;i<sum.size();i++)
        {
            if(sum[i]==targetSum)
            {
                return true;
            }
        }
        return false;
    }
};

-------------------------------------------------------------------------------

113. Path Sum II
https://leetcode.com/problems/path-sum-ii/description/

class Solution {
public:
    void dfs(TreeNode *root, vector<int> temp, vector<vector<int>> &sum,int target)
    {
        if(root==NULL)
        {
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            int x=0;
            for(int i=0;i<temp.size();i++)
            {
                x+=temp[i];
            }
            if(x==target)
            {
                sum.push_back(temp);
            }
            
        }
        dfs(root->left,temp,sum,target);
        dfs(root->right,temp,sum,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
            vector<int> temp;
            vector<vector<int>> sum;
            dfs(root,temp,sum,targetSum);
            return sum;
    }
};

--------------------------------------------------------------------------
129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

class Solution {
public:
    void dfs(TreeNode *root, int sum, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        sum=sum*10+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            ans+=sum;
        }
        dfs(root->left, sum, ans);
        dfs(root->right,sum, ans);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int ans=0;
        dfs(root,sum,ans);
        return ans;
    }
};
---------------------------------------------------------
