class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n,0);

        
        for(int i = n-1 ; i >=0 ;i-- )
        {
            int element  =  temperatures[i];
            int count =0;
            
            while(!st.empty() && temperatures[st.top()] <= element)
            {
                st.pop();
            }
            
            if(!st.empty())
            {
                ans[i] = st.top()-i;
            }
            
            st.push(i);
      
            
            
            
        }
        return ans;
        
    } 
};