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
921. Minimum Add to Make Parentheses Valid

 https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/solutions/7910301/stack-parantesis-problem-by-shubham_sk70-xq1u/

class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char> stk;
        for(auto x:s)
        {
            if(x=='(')
            {
                stk.push('(');
            }
            else if(stk.size()>0 && x==')' && stk.top()=='(')
            {
                stk.pop();
            }
            else
            {
                stk.push(x);
            }
        }
        return stk.size();
        
    }
};
-----------------------------------------------------------------------------------------------------------------

