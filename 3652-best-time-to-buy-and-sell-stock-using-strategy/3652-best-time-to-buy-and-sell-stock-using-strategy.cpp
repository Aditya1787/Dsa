class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }
        
        vector<long long> prefSP(n + 1, 0);
        vector<long long> prefPrice(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefSP[i + 1] = prefSP[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }
        
        long long bestDelta = 0;
        int half = k / 2;
        
        for (int l = 0; l + k <= n; l++) {
            int mid = l + half;
            int r = l + k;
            
            long long removeBuy = prefSP[mid] - prefSP[l];
            long long addSell = (prefPrice[r] - prefPrice[mid])
                              - (prefSP[r] - prefSP[mid]);
            
            long long delta = -removeBuy + addSell;
            bestDelta = max(bestDelta, delta);
        }
        
        return baseProfit + bestDelta;
    }
};
