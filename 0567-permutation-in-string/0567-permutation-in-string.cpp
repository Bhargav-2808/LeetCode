class Solution {
public:
    bool check(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
        {
            
            if(a[i]!=b[i])
            {
                return 0;
            }
        }
        return 1;
    }
public:
     bool checkInclusion(string s1, string s2) {
        int c1[26] ={0};
        int c2[26] ={0};
        int window =s1.length();
        for(int i=0;i<s1.length();i++)
        {
            int index =s1[i]-'a';
            c1[index]++;
        }
        
        int i=0;
        while(i<window && i<s2.length())
        {
            int index = s2[i]-'a';
            c2[index]++;
            i++;
        }
         
        if(check(c1,c2))
        {
            return 1;
        }
        while(i<s2.length())
        {
            int newchar = s2[i]-'a';
            c2[newchar]++;
            int oldchar = s2[i-window]-'a';
            c2[oldchar]--;
            i++;

            if(check(c1,c2))
            {
                return 1;
            }
        
        }
        return 0;
        
      
         
    }
};