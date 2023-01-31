class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26,0);
        
        for(int i=0; i<magazine.size(); i++ )
        {
            a[magazine[i]-'a']++;
        }
        
        for(int i=0; i<ransomNote.size();i++)
        {
            if(a[ransomNote[i]-'a'] <= 0)
                return false;
            else
                a[ransomNote[i]-'a']--;
        }   
        return true;
    }
};