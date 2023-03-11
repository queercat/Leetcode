class Solution(object):
    def __init__(self):
        self.dict = {}

    def traverse(self, depth, target):
        if depth == target:
            return 1

        if depth > target:
            return 0

        total = 0        

        if depth + 1 not in self.dict:
            self.dict[depth + 1] = self.traverse(depth + 1, target)

        if depth + 2 not in self.dict:
            self.dict[depth + 2] = self.traverse(depth + 2, target) 

        total += self.dict[depth + 1]
        total += self.dict[depth + 2]

        return total

    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        return self.traverse(0, n)