class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = 0;
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0); 

        for(int i = 0; i < height.size(); i++){
            int j = height.size() - i - 1;
            left[i] = l;
            right[j] = r;

            l = max(l, height[i]);
            r = max(r, height[j]);
        }

        int summ = 0;
        for(int i  = 0; i < height.size(); i++){
            int pot = min(left[i], right[i]);
            summ += max(0, pot - height[i]);
        }

        return summ;
    }
};
