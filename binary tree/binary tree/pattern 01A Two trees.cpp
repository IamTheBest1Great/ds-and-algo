872. Leaf-Similar Trees
https://leetcode.com/problems/leaf-similar-trees/

class Solution {
public:
    void dfs(TreeNode *root, vector<int> &list)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            list.push_back(root->val);
        }
        dfs(root->left,list);
        dfs(root->right,list);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;

        dfs(root1,list1);
        dfs(root2,list2);
        if(list1.size()!=list2.size())
        {
            return false;
        }
        for(int i=0;i<list1.size();i++)
        {
            if(list1[i]!=list2[i])
            {
                return false;
            }
        }
        return true;
    }
};
----------------------------------------------------------
Isomorphic Trees
https://www.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
  
class Solution {
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2) {
        // add code here.
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
        {
            return false;
        }
        if(root1->data != root2->data)
        {
            return false;   
        }
        return isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right, root2->left)
            || isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right, root2->right);
    }
};
  ----------------------------------------------------
Two Mirror Trees
https://www.geeksforgeeks.org/problems/two-mirror-trees/1

  class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        if(!a && !b)
        {
            return true;
        }
        if(!a  || !b)
        {
            return false;
        }
        if(a->data!=b->data)
        {
            return false;
        }
        return areMirror(a->right,b->left) && areMirror(a->left,b->right);
    }
};
-----------------------------------------------------------------------
  
572. Subtree of Another Tree
https://leetcode.com/problems/subtree-of-another-tree/
  
class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        if(root==NULL && subRoot!=NULL || root!=NULL && subRoot==NULL)
        {
            return false;
        }
        if(root->val!=subRoot->val)
        {
            return false;
        }
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL)
        {
            return false;
        }
        if(subRoot==NULL)
        {
            return true;
        }
        if(root->val==subRoot->val)
        {
            bool isIdentical= check(root,subRoot);
            if(isIdentical)
            {
                return true;
            }

        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};

--------------------------------------------------------------------------------
