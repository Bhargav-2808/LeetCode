class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int a = 0; 
        int b = n;
        
        for(int i=0 ;i<nums.size();i++)
        {
            if(i&1)
            {
                ans.push_back(nums[b++]);
            }
            else
            {
                ans.push_back(nums[a++]);
            }
        }
        return ans;
    }
};