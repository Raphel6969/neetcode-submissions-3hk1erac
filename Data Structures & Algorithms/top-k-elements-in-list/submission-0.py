class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hosh = {}
        for num in nums:
            if num in hosh:
                hosh[num] += 1
            else:
                hosh[num] = 1
        arr = sorted(hosh, key=hosh.get, reverse=False)[-k:]
        return arr