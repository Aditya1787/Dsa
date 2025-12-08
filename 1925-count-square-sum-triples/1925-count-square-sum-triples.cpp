class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        vector<int> vec(n + 1);
        for (int i = 0; i <= n; i++) {
            vec[i] = i * i;
        }

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int sum = vec[a] + vec[b];

                int c = sqrt(sum);
                if (c <= n && vec[c] == sum) {
                    count++;
                }
            }
        }

        return count;
    }
};
