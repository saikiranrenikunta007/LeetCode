class Solution:
    def checkRecord(self, n: int) -> int:
        mod = 1000000007
        def solve(n, mod):
                    dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(n + 1)]
                    for a in range(2):
                        for l in range(3):
                            dp[n][a][l] = 1
                    for i in range(n - 1, -1, -1):
                        for a in range(2):
                            for l in range(3):
                                dp[i][a][l] = dp[i + 1][a][0]
                                if a == 0:
                                    dp[i][a][l] += dp[i + 1][1][0]
                                if l < 2:
                                    dp[i][a][l] += dp[i + 1][a][l + 1]
                                dp[i][a][l] %= mod
                    return dp[0][0][0]
        return solve(n,mod)%mod
            