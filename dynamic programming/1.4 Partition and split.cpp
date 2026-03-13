139. Word Break
 https://leetcode.com/problems/word-break/description/
https://leetcode.com/problems/word-break/solutions/7645771/dp-1d-partition-split-by-shubham_sk70-i1rn/



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n= s.size();
        int maxSize=0;
        for(int i=0;i<wordDict.size();i++)
        {
            maxSize=max(maxSize, (int)wordDict[i].size());
        }
        vector<bool> dp(n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=max(i-maxSize,0); j--)
            {
                if(dp[j]==true && st.count(s.substr(j, i-j)))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        if(dp[n])
        {
            return true;
        }
        return false;
        
    }
};
