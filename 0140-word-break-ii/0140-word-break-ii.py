class Solution:   
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        d = set(wordDict)
        memo={}
        def solve(s,d):
            if s in memo :
                return memo[s]
            if len(s) == 0:
                return []
            memo[s] = []
            for i in range(len(s)-1,-1,-1):
                if s[i:] in d:
                    l = solve(s[0:i],d)
                    # print("l=",l)
                    l2=[]
                    for x in l:
                        ash = x+" "+s[i:]
                        l2.append(ash)
                    if(len(l2)==0 and i==0):
                        l2 = [s[i:]]
                    memo[s]+=l2
            return memo[s]
        return solve(s,d)
            
        