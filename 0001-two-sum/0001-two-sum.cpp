class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
       
        
        for(int i =0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                 if(target == (nums[i]+nums[j]))
                {
                    ans.insert(ans.end(),{i,j});
                     break;
                }
            }
            
        }
        /*
        
        while(i<nums.size()-1)
        {
            while(j<nums.size()-1)
            {
                 if(target == (nums[i]+nums[j]))
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
                j++;
            }
            i++;
           
        }
          */
        return ans;
      
        
    }
};

