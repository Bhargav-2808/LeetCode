class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int remainingGas = 0;
        int capacity = 0;
        int rear = 0 ;
        
        for(int i=0;i<gas.size();i++)
        {
            capacity = capacity + gas[i] - cost[i];
            
            if(capacity < 0)
            {
                start = i+1;
                remainingGas += capacity;
                capacity = 0;
                
            }
        }
        
        
        if(remainingGas + capacity >= 0)
        {
            return start;
        }
        return -1;
    }
};