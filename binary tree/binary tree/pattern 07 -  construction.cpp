Construct Binary Tree from Parent Array

https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
        int n=parent.size();
        vector<Node*> node(n);
        for(int i=0;i<n;i++)
        {
            node[i] = new Node(i);
        }
        Node *root = NULL;
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                root= node[i];
            }
            else
            {
                Node *p= node[parent[i]];
                if(!p->left)
                {
                    p->left=node[i];
                }
                else if(!p->right)
                {
                    p->right=node[i];
                }
            }
            
        }
        return root;
    }
};
---------------------------------------------------------------------------------
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    //we are using index because we don't know which root will come next at what index
    int index=0;
    unordered_map<int,int> mp;

    TreeNode *construct(vector<int> preorder, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        //picking the first preorder array and fixing it to root because in preorder first one is root
        TreeNode *root = new TreeNode(preorder[index++]);
        //finding the index of inorder mid to know how many are in left subtree and hw many are in right subtree
        int mid = mp[root->val];

        //creating the tree
        root->left = construct(preorder, start,mid-1);
        root->right = construct(preorder, mid+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        
        // we are storing inorder index in map to know how many are in left and right so that we can pass that number in preorder
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        return construct(preorder,0,inorder.size()-1);
    }
};

----------------------------------------------------------------------------------------------------

  106. Construct Binary Tree from Inorder and Postorder Traversal
  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    unordered_map<int,int> mp;
    int postIndex;
    TreeNode *construct(vector<int> &postorder, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        //for each time this function is called we only add 1 value that we know is the last one because in postorder it is L,R,Root.
        int rootVal = postorder[postIndex--];
        //creating root for last value that we know is root
        TreeNode *root = new TreeNode(rootVal);
        //we find mid to know how many are left and how many are right
        int mid = mp[rootVal];
        root->right = construct(postorder,mid+1,end);
        root->left = construct(postorder,start,mid-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=inorder.size();
         for(int i=0;i<n;i++)
         {
            mp[inorder[i]]=i;
         }
         postIndex = n-1;
         return construct(postorder,0, n-1);
    }
};
