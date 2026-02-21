class Solution {
 public:
  int countPrimeSetBits(int left, int right) {
    
    constexpr int 
    int ans = 0;

    for (unsigned num = left; num <= right; ++num)
      if (magic >> popcount(num) & 1)
        ++ans;

    return ans;
  }
};