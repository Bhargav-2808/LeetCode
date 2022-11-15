/*class Solution {
public:
    void merge(vector<int>& nums,int s, int e)
    {
        int mid = s + (e-s)/2;
        int l1 = mid-s+1;
        int l2 = e-mid;
        int tempIndex = 0; 
        int i1 = 0;
        int i2 = 0;

        int* first = new int[l1];
        int* second = new int[l2];
        vector<int> temp;
        
        tempIndex=s;
        for(int i =0 ; i< l1 ; i++)
        {
            first[i]=nums[tempIndex++];
        }

        
        tempIndex=mid+1;
        for(int i =0 ; i< l2 ; i++)
        {
            second[i]=nums[tempIndex++];
        }

        
        tempIndex =s;
        while(i1<l1 && i2<l2)
        {
            if(first[i1]<second[i2])
            {
                nums[tempIndex++] = first[i1++];
            }
            else
            {
                nums[tempIndex++] = second[i2++];
            }
        }
        while(i1<l1)
        {
            nums[tempIndex++] = first[i1++];
        }

        while(i2<l2)
        {
            nums[tempIndex++] = second[i2++];
        }
    
    }

    void mergeSort(vector<int>& nums,int s, int e)
    {
        if(s>=e)
        {
            return;
        }

        int mid = s + (e-s)/2;
        
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};*/
class Solution{
    public:
        void merge(vector<int>& nums, int l1, int r1, int l2, int r2, vector<int> &temp){
        int index = 0, startl = l1;
        while(l1 <= r1 && l2 <= r2){
            if(nums[l1] < nums[l2]) temp[index++] = nums[l1++]; 
            else temp[index++] = nums[l2++];
        }
        while(l1 <= r1) temp[index++] = nums[l1++];
        while(l2 <= r2) temp[index++] = nums[l2++]; 
        for(int i = 0; i<index; i++) nums[startl+i] = temp[i];
    }

    void mergeSort(vector<int>& nums, int l, int r, vector<int> &temp){
        if(l >= r) return;
        int m = l + (r - l) / 2; 
        mergeSort(nums, l, m, temp);
        mergeSort(nums, m + 1, r, temp);
        merge(nums, l, m, m+1, r, temp);
    }

    vector<int> sortArray(vector<int> &nums){
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};
