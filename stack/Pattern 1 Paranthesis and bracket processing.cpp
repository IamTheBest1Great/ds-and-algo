Subtype 1. Basic validation

20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        int n=s.size();
        if(n==1)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                if (s[i] == ']' && st.top() != '[') return false;

                st.pop();
            }  

        }
        return st.empty();
    }
};

-------------------------------------------------------------------------------------------------------------------------


