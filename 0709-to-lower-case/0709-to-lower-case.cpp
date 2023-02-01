class Solution {
public:
    
    string toLowerCase(string s) {
        string ans="";
        for(char ch : s)
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                
                ans.push_back( ch+32  );
            }
            else
            {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};