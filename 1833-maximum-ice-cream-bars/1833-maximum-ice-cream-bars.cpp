class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        int sum =  coins;
        for(int i = 0 ; i < costs.size(); i++)
        {
            sum-=costs[i];
            if(sum < 0) break;

            
            count++;
            
        }
        return count;
    }
};