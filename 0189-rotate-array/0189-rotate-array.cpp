class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0)
        {
            return;
        }
        int len = nums.size();
        int temp[len];

        for(int i = 0; i<len ; i++)
        {
            temp[(i+k)%len]=nums[i];
        }

        for(int i =0;i<len ; i++)
        {
            nums[i] = temp[i];
        }
        
        
    }
};