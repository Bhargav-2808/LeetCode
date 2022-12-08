class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i= 0;
        int j = nums.size()-1;
        int pivot = 0;
        
        while(pivot<=j)
        {
            if(nums[pivot] == 0)
            {
                swap(nums[i++],nums[pivot++]);
            }
            else if(nums[pivot] == 1 )
            {
                pivot++;
            }
            else if(nums[pivot] == 2)
            {
                swap(nums[j--],nums[pivot]);
            }
        }
    }
};