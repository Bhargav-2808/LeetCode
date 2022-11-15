class Solution {
public:
    void merge(vector<int>& count, vector<pair<int,int>>& ve, int left, int mid, int right)
    {
        vector<pair<int, int>> temp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while(i<=mid && j<=right)
        {
            if(ve[i].first <= ve[j].first)
            {
                temp[k++]=ve[j++];
            }
            else
            {
                count[ve[i].second]+=right-j+1;
                temp[k++]=ve[i++];
            }

        }

        while(i<=mid)
        {
            temp[k++]=ve[i++];
        }

        while(j<=right)
        {
            temp[k++]=ve[j++];
        }

        for(int i = left ; i<=right ; i++)
        {
            ve[i]=temp[i-left];
        }

    }
    void mergeSort(vector<int>& count , vector<pair<int,int>>& ve , int left , int right)
    {
        int mid = left + (right-left)/2;
        if(left>=right)
        {
            return;
        }

        mergeSort(count,ve,left,mid);
        mergeSort(count,ve,mid+1,right);
        merge(count,ve,left,mid,right);
    }

    vector<int> countSmaller(vector<int>& nums) {
       int len  = nums.size();
       vector<pair<int ,int>> ve(len);
       vector<int> count(len,0);

       for(int i= 0; i<len ; i++)
       {
           pair<int , int> p;
           p.first = nums[i];
           p.second = i;
           ve[i] = p;
       }

       mergeSort(count,ve,0,len-1);
       return count;
    }
};