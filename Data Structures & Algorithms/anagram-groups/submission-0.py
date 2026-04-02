class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        arr = []
        arr2 = []
        for i, word in enumerate(strs):
            Sortedword = sorted(word)
            Varword = "".join(Sortedword)
            if Varword in arr:
                index = arr.index(Varword)
                arr2[index].append(word)
            else:
                arr.append(Varword)
                arr2.append([strs[i]])
        return arr2