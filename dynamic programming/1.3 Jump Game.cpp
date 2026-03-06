55. Jump Game

https://leetcode.com/problems/jump-game/description/

https://leetcode.com/problems/jump-game/solutions/7630720/1d-dp-by-shubham_sk70-6nm7/

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int goal = nums.size()-1;
       for(int i=nums.size()-2;i>=0;i--)
       {
        if(i + nums[i] >= goal)
        {
            goal=i;
        }
       } 
       if(goal==0)
       {
        return true;
       }
       return false;
    }
};

-----------------------------------------------------------------------------------------------

45. Jump Game II

    https://leetcode.com/problems/jump-game-ii/description/

https://leetcode.com/problems/jump-game-ii/solutions/7630754/1d-dp-by-shubham_sk70-y6n5/

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); 
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            int step=dp[i]+1;
            for(int j=i;j<n && j<=i+nums[i];j++)
            {
                
                dp[j]=min(dp[j],step);
            }
        } 
        return dp[n-1];
    }
};

-----------------------------------------------------------------------------------
1306. Jump Game III
  
  https://leetcode.com/problems/jump-game-iii/description/
  
https://leetcode.com/problems/jump-game-iii/solutions/7630763/1d-dp-by-shubham_sk70-4dl2/



  class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(start);  
        vis[start]=true;
        int length=arr.size();
        if(arr[start]==0)
        {
            return true;
        }
        while(!q.empty())
        {
            int index=q.front();
            q.pop();
                
                if(arr[index]==0)
                {
                    return true;
                }
                int skip=arr[index];
                if(skip+index<length && vis[skip+index]==false)
                {
                    q.push(skip+index);
                    vis[skip+index]=true;
                }
                if(index-skip>=0 && vis[index-skip]==false)
                {
                    q.push(index-skip);
                    vis[index-skip]=true;
                }

        }
        return false;
    }
};

