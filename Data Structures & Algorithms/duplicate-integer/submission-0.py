class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        setNum = set(nums)
        if len(nums) != len(setNum):
            return True
        else:
            return False