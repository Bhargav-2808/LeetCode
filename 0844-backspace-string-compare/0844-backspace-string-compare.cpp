class Solution {
public:
    stack<char> validstr(string &exp)
    {
        stack<char> st;
        string temp;
       for(char ch : exp)
       {
           if(ch == '#')
           {
               if(!st.empty())
                st.pop();
           }else
           {
               st.push(ch);
           }
       }
    
        return st;
    }
    
    bool backspaceCompare(string s, string t) {
        stack<char> x=validstr(s);
        stack<char> y=validstr(t);
        
        return x==y;
        
    }
};