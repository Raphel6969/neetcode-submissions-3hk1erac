class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (k > nums.size()){
            return ans;
        }
        map<int, int> m;

        for(int i = 0; i < k; i++){
            m[nums[i]]++;
        }
        ans.push_back(m.rbegin()->first);

        int l = 0;
        int r = k;
        for(r; r < nums.size(); r++){
            m[nums[l]]--;
            if (m[nums[l]] == 0){
                m.erase(nums[l]);
            }
            m[nums[r]]++;
            ans.push_back(m.rbegin()->first);
            l++;
        }

        return ans;
    }
};
