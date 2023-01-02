class Solution {
public:
    bool detectCapitalUse(string word) {
        int count1 = 0;
        int count2 = 0;
        for(char i : word)
        {
            if(isupper(i) )
            {
                count1++;
            }
          
            
        }
        

        
        if(count1 == word.length() || count1 == 0 || (count1 == 1 && isupper(word[0])) )return true;
        return false;
    }
};