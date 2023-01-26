class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        
        for(int i=0;i<digits.size();i++)
        {
           if(digits[i] == 9 && i!=digits.size()-1)
           {
               digits[i]=0;
           }
            else if(digits[i] == 9 && i==digits.size()-1)
            {
                digits[i]=0;
               // digits.push_back(0);                
                digits.push_back(1);
                break;

            }
            else
            {
                digits[i]++;
                break;
            }
        }
        reverse(digits.begin(),digits.end());
        return digits;

    }
};