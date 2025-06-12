class Solution {
public://O(n^2) O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if (prices[j] > prices[i]){
                    profit = max(profit , prices[j]-prices[i]);
                }
            }
        }
        return profit;
    }
};

class Solution {
public:// O(n) O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int mini = prices[0];
        for(int i = 1 ; i < n ; i++){
            if (prices[i] < mini) {
                mini = prices[i];
                continue;
            }
            profit = max(profit , prices[i]-mini);
        }
        return profit;
    }
};