class Solution:

    def encode(self, strs: List[str]) -> str:
        x = ""
        for char in strs:
            length = len(char)
            x += str(length) + "#" + char 
        return x
    def decode(self, s: str) -> List[str]:
        arr = []
        i = 0
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            length = int(s[i:j])
            arr.append(s[j + 1 : j + 1 + length])
            i = j + 1 + length
        return arr