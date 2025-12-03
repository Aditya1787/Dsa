class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;

        // slope → list of edges (pairs of indices)
        unordered_map<long long, vector<pair<int,int>>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];

                long long g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize slope: force dx > 0 or handle vertical lines
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                if (dx == 0) dy = 1;       // vertical lines => slope = INF
                if (dy == 0) dx = 1;       // horizontal lines => slope = 0

                long long key = (dx << 32) ^ (dy & 0xffffffff);
                mp[key].push_back({i, j});
            }
        }

        long long ans = 0;

        for (auto &entry : mp) {
            auto &edges = entry.second;
            int m = edges.size();
            if (m < 2) continue;

            long long total = 1LL * m * (m - 1) / 2; // total pairs

            // Count invalid pairs (sharing a point)
            unordered_map<int, int> cnt;
            for (auto &e : edges) {
                cnt[e.first]++;
                cnt[e.second]++;
            }

            long long invalid = 0;
            for (auto &p : cnt) {
                long long c = p.second;
                if (c >= 2) invalid += 1LL * c * (c - 1) / 2;
            }

            ans += total - invalid;
        }

        return ans;
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }
};
