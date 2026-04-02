class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0 

        setNums = set(nums)
        longest = 0
        for num in nums:
            if num - 1 not in setNums:
                next_num = num + 1
                length = 1 
                while next_num in setNums:
                    length += 1
                    next_num += 1
                longest = max(length, longest)
        return longest