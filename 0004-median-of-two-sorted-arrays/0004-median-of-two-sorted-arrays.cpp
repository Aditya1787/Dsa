class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        double sum;
        for(int num: nums1){
            vec.push_back(num);
        }
        for(int num: nums2){
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());

        int n = vec.size();
        if (n % 2 == 0) {

            return (vec[n/2 - 1] + vec[n/2]) / 2.0;
        } else {
            return vec[n/2];
        }
        
    }
};