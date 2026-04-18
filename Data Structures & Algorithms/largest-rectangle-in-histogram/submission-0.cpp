class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = 0, r = 0;
        int h = 0;
        int area_max = 0;

        for(int i = 0; i < heights.size();i++){
            l = i;
            r = i;
            h = heights[i];
            while(l >= 0){
                if(heights[l] < h){
                    break;
                }
                l--;
            }
            while(r < heights.size()){
                if(heights[r] < h){
                    break;
                }
                r++;
            }
            int area = h * (r - l - 1);
            area_max = max(area, area_max);
        }
        return area_max;
    }
};
