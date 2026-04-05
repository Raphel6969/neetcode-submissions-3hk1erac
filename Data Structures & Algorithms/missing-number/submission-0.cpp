class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ref = 0;
        for(int i = 0; i < nums.size() + 1; i++){
            ref ^= i;
        }

        for(int i =0 ; i < nums.size(); i++){
            ref ^= nums[i];
        }

        return ref;
    }
};
