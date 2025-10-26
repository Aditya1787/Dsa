class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> vec;
        for(int num : nums){
            int count = 0;
            for(int i : nums){
                if(num == i){
                    count++;
                }
            }
            if (count == 1){
                vec.push_back(num);
            }
        }
        return vec;
        
    }
};