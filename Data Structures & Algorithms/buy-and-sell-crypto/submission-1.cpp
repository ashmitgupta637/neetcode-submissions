class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0 ; 
        int n = prices.size() ; 
        int left = 0 ; 
        int buy = prices[0] ; 
        for(int right = 1 ; right < n  ; right++){
            if(prices[right] >  prices[left]) {
                int profit = prices[right] - prices[left] ; 
                max_profit = max(max_profit , profit) ; 
            }else{
                left = right ; 
            }

            
        }
        return max_profit  ; 
    }
};
