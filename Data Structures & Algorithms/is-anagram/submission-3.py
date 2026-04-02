class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        obj1 = {}
        obj2 = {}

        for i in s:
            if i in obj1:
                obj1[i] += 1
            else:
                obj1[i] = 1
        for i in t:
            if i in obj2:
                obj2[i] += 1
            else:
                obj2[i] = 1
        
        if obj1 == obj2:
            return True
        return False
