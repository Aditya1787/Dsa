class Solution {
public:
    static const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> freq; 
        // freq[y] = count of points with this y

        for (auto &p : points) {
            long long y = p[1];
            freq[y]++;
        }

        vector<long long> seg;
        for (auto &it : freq) {
            long long k = it.second;
            if (k >= 2) {
                long long s = (k * (k - 1) / 2) % MOD;
                seg.push_back(s);
            }
        }

        long long ans = 0;
        long long prefix = 0;

        // Compute sum of all pairs seg[i] * seg[j], i < j
        for (long long s : seg) {
            ans = (ans + prefix * s) % MOD;
            prefix = (prefix + s) % MOD;
        }

        return ans % MOD;
    }
};
