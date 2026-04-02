class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, int s, int e){
        int mid = s + (e-s)/2;
        while(s <= e){
            if(target == nums[mid]){
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
    int findMin(vector<int>& nums) {
            int s = 0; 
            int e = nums.size() -1;
            int mid = s + (e-s)/2;

            while(s < e){
                if(nums[mid] > nums[e]){
                    s = mid + 1;
                }else{
                    e = mid;
                }
                mid = s + (e-s)/2;
            }

            return s;

        }
    int search(vector<int>& nums, int target) {
        int pivot = findMin(nums);
        if(nums[pivot] <= target && target  <= nums[nums.size() -1]){
            return BinarySearch(nums, target, pivot, nums.size() -1);
        }else{
            return BinarySearch(nums, target, 0, pivot -1);
        }
    }
};
