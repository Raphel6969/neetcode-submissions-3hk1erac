class Solution:
    def isPalindrome(self, s: str) -> bool:
        alphanumeric = list("".join(char for char in s if char.isalnum()).lower())
        if not alphanumeric:
            return True
        if len(alphanumeric) == 1:
            return True
        right = len(alphanumeric) - 1
        if len(alphanumeric) % 2 == 0:
            for left in range(len(alphanumeric) // 2):
                if alphanumeric[left] != alphanumeric[right]:
                    return False
                    break  
                right -= 1 
            return True
        else:
            for left in range((len(alphanumeric) // 2) + 1):
                if alphanumeric[left] != alphanumeric[right]:
                    return False
                    break  
                right -= 1 
            return True