class Solution:
    def firstUniqChar(self, s: str) -> int:
        memo = {}
        for c in s:
            if c not in memo:
                memo[c] = 0
            memo[c] += 1
        
        for i, c in enumerate(s):
            if memo[c] < 2:
                return i
        
        return -1
