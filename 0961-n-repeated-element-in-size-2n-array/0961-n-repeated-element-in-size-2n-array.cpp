class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i: nums){
            for(int j: nums){
                if(i==j){
                    count++;
                }
            }
        if(count>=2){
            return i;
        }
        }
        return 0;
        
    }
};