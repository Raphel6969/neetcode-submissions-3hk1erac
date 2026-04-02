class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i,num in enumerate(nums):
            rain = target - num
            if rain in hash_map:
                return [hash_map[rain], i]
            hash_map[num] = i
        