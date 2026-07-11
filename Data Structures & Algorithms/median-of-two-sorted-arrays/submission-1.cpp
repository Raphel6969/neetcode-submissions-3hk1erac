class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total / 2;
        vector<int> n1, n2;
        if (nums1.size() <= nums2.size()) {
            n1 = nums1;
            n2 = nums2;
        } else {
            n1 = nums2;
            n2 = nums1;
        }

        int l = -1;
        int r = n1.size() - 1;

        while (true) {
            int m = l + (r - l) / 2;
            int b = half - m - 2;

            int aleft = (m >= 0) ? n1[m] : INT_MIN;
            int aright = (m + 1 < n1.size()) ? n1[m + 1] : INT_MAX;

            int bleft = (b >= 0) ? n2[b] : INT_MIN;
            int bright = (b + 1 < n2.size()) ? n2[b + 1] : INT_MAX;

            if (aleft <= bright && bleft <= aright) {
                if (total % 2 ){
                    return min(aright, bright);
                }
                return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }else if (aleft > bright){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
    }
};
