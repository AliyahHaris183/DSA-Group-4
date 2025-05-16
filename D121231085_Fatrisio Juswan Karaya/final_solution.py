class Solution:
    def findCenter(self,edges):
        if not edges or len(edges) < 2:
            return -1
        a,b = edges[0]
        c,d = edges[1]


        if a == c or a == d:
            return a
        else:
            return b
        
edges1 = [[1,2],[1,3],[1,4]]
edges2 = [[2,4],[2,8],[3,2]]

sol = Solution()
print(sol.findCenter(edges1))
print(sol.findCenter(edges2))