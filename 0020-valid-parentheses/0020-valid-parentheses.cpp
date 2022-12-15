class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        for(int i=0;i<s.length();i++)
        {
            char st = s[i];
            
            if(st == '{' || st == '(' ||  st == '[')
            {
                stc.push(st);
            }
            else
            {
                if(!stc.empty())
                {
                    char top = stc.top();
                     
                    if(  top == '{' && st == '}' || top == '(' && st == ')' || top == '[' && st == ']'  )
                    {
                            stc.pop();

                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            
        }
        if(stc.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};