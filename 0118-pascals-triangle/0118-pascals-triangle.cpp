class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        if(numRows ==1) 
        {
            ans.push_back({1}); 
        }
        else
        {
          
            ans.push_back({1});
                     


            for(int  j =2; j<=numRows;j++)
            {
                vector<int> temp;
                temp.push_back(1);
                for(int i = 1; i< ans[ans.size()-1].size();i++)
                {

                    temp.push_back(ans[ans.size()-1][i] + ans[ans.size()-1][i-1]);
                }
                temp.push_back(1);
                ans.push_back(temp);

            }
            
        }
        return ans;
    }
};