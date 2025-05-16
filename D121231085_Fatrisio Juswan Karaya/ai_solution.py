class Solution:
    def findCenter(self, edges):
        a, b = edges[0]
        c, d = edges[1]
        
        # Cek node yang muncul di kedua edge
        if a == c or a == d:
            return a
        else:
            return b

sol = Solution()
print(sol.findCenter([[1,2], [2,3], [4,2]]))  # Output: 2
print(sol.findCenter([[1,2], [5,1], [1,3], [1,4]]))  # Output: 1