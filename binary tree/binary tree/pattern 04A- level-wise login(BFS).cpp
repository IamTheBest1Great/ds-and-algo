102. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
            
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        } 
        return ans;    
    }
};
---------------------------------------------------------------------
993. Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/description/

class Solution {
public:
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root==NULL)
        {
            return false;
        }    
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            //int ans=0;
            int n=q.size();
            bool foundx=false;
            bool foundy=false;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if(temp->val==x)
                {
                    foundx=true;
                }
                if(temp->val==y)
                {
                    foundy=true;
                }
                //found in same parent
                if(temp->left && temp->right)
                {
                    int l=temp->left->val;
                    int r=temp->right->val;
                    
                    if(l==x && r==y || l==y &&r==x)
                    {
                        return false;
                    }
                }
                
                //checks both value present comes to this after checking if they do not belong to the same parent
                if(foundx && foundy)
                {
                    return true;
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
        return false;
    }
};

---------------------------------------------------------------------------------------

637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        vector<double> average;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            double sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            average.push_back(sum/n);
        }
        return average;
    }
};
-------------------------------------------------------------------

199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/description/

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
--------------------------------------------------------------------------

Left View of Binary Tree
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

class Solution {
  public:
    vector<int> leftView(Node *root) {
        
        // code here
        if(root==NULL)
        {
            return {};
        }
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(i==0)
                {
                    ans.push_back(temp->data);
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
-----------------------------------------------------------------------

116. Populating Next Right Pointers in Each Node
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                Node *node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
                if(i!=n-1)
                {
                    node->next=q.front();
                }
            }
            
        }
        return root;
    }
};
----------------------------------------------------------------------
