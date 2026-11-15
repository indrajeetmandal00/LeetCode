class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n= len(arr)
        res, tot, i= n+1,0,0

        dp=[n]*(n+1)

        for j in range(n):
            tot+=arr[j]

            while tot>target:
                tot-=arr[i]
                i+=1

            dp[j+1]=dp[j]

            if tot==target:
                    res= min(res,j-i+1+dp[i])
                    dp[j+1]=min(dp[j], j-i+1)
        return -1 if res==n+1 else res            