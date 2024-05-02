class Solution {
public:
    bool isValid(unordered_map<char,int>&mp) {
        
        for(auto &a : mp) {
            if(a.second>=2) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(),j=0,ans=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;++i) {
            mp[s[i]]+=1;
            while(j<i && !isValid(mp)){
                mp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};