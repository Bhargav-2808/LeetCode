class Solution {
private:
    void subset(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans)
    {
        ans.push_back(output);
        for(int i = index ; i< nums.size(); i++)
        {
            output.push_back(nums[i]);
            subset(nums,output,i+1,ans);
            output.pop_back();
        }

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        int index = 0;
        subset(nums,output,index,ans);
        return ans;
    }
};