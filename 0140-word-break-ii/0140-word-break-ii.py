class Solution:   
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        d = set(wordDict)
        # print(d)
        memo={}
        def solve(s,d):
            # print(s)
            if s in memo :
                return memo[s]
            if len(s) == 0:
                return [[]]
            memo[s] = []
            for i in range(len(s)-1,-1,-1):
                if s[i:] in d:
                    l = solve(s[0:i],d)
                    for x in l:
                        # print(x)
                        memo[s]+=[x+[s[i:]]]
            return memo[s]
        a = solve(s,d)
        ans=[]
        for i in a:
            # print(i)
            ans.append(" ".join(i))
        return ans
            
        