class Solution {
public:

    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() -1;
        int mid = s + (e-s)/2;
        while(s <= e){
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                e = mid -1;
            }else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int e = matrix.size() - 1;
        int mid = s + (e-s)/2;
        int ans = -1;

        while(s <= e){
            if(matrix[mid][0] > target){
                e = mid -1;
            }else if(matrix[mid][matrix[mid].size() -1] < target){
                s = mid + 1;
            }else{
                return search(matrix[mid], target) != -1;
            }
            mid = s + (e-s)/2;
        }
        return false;
        
    }
};
