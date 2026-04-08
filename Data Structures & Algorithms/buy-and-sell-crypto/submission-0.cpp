class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int max_val = 0;

        for(r; r < prices.size(); r++){
            if(prices[l] > prices[r]){
                l = r;
            }
            int w = prices[r] - prices[l];
            max_val = max(w, max_val);
        }
        return max_val;
        
    }
};
