1021. Remove Outermost Parentheses
https://leetcode.com/problems/remove-outermost-parentheses/description/

https://leetcode.com/problems/remove-outermost-parentheses/solutions/7895045/stack-paranthesis-by-shubham_sk70-u6ss/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        int depth=0;
        for(auto x: s)
        {
            if(x=='(')
            {
                if(depth>0)
                {
                    ans.push_back('(');
                }
                depth++;
            }
            else if(x==')')
            {
               
               if(depth > 1)
               {
                    ans.push_back(')');
               }
                depth--;
            }
            
        }
        return ans;
    }
};
