class Solution {
public: 
    int fOcc(vector<int>& nums, int target)
    {
        int s=0;
        int e=nums.size()-1;
        int mid = s+ (e-s)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(nums[mid]==target)
            {
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }

    public: 
    int lOcc(vector<int>& nums, int target)
    {
        int s=0;
        int e=nums.size()-1;
        int mid = s+ (e-s)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(nums[mid]==target)
            {
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      
        return {fOcc(nums,target),lOcc(nums,target)};
        
        
    }
};