class Solution {
public:
    int minSwaps(string s) {
        int a=0,b=0;
        stack<char> st;
        
        if(s.length()%2 == 1)
        {
            return -1;
        }
            
        for(int i=0 ; i<s.length(); i++)
        {
            char ch  = s[i];
            
            if(ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            
            
        }
        
        
        while(!st.empty())
        {
            if(st.top() == '[')
            {
                a++;
            }
            else
            {
                b++;
            }
            st.pop();
        }
        
        
        int ans = (a+b+2)/4;
        
        return ans;
    }
};