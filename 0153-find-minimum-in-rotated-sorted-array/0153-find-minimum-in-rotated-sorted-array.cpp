class Solution {

public:
    
    int findpivot(vector<int>& nums,int size)
    {
        int s=0;
        int e=size-1;
        int mid= s+(e-s)/2;
        
        while(s<e)
        {
            if(nums[0]<nums[mid])
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
            mid= s+(e-s)/2;
        }
        return s;
    }
    
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid= s+ (e-s)/2;
        
        
        while(s<e)
        {
            if(nums[mid]>nums[e])
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
            mid= s+ (e-s)/2;
        }
        return nums[s];
    }
};