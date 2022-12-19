class Solution {
public:
      vector<int> nextSmaller(vector<int>& heights,int n)
    {
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i =n-1 ; i>=0;i--)
        {
            int curr = heights[i];
            
            while(s.top()!=-1 && heights[s.top()] >= curr )
            {
                s.pop();
                
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    vector<int> prevsmaller(vector<int>& heights,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = 0;i<n;i++)
        {
            int curr = heights[i];
            
            while(s.top()!=-1 && heights[s.top()]>=curr)
            {
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
        
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        int n  = heights.size();
        int area = INT_MIN;
        vector<int> next(n);
        vector<int> prev(n);
        
        next = nextSmaller(heights,n);
        prev = prevsmaller(heights,n);
       
        for(int i =0 ;i<n ;i++)
        {
            int h = heights[i];
            
            
            
            if(next[i] == -1)
            {
                next[i] =n;    
            }
            int b = next[i] -prev[i]-1;
            
            
            int maxArea = h*b;
            area = max(area,maxArea);
        }
        
        return area;
        
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxiArea = 0; 
        int n = matrix.size(); 
        int m = matrix[0].size();
        vector<int> height(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == '1') 
                    height[j]++;
                else 
                    height[j] = 0;
            }   
           
            maxiArea = max(maxiArea,largestRectangleArea(height));
        }
        return maxiArea;
    }

};