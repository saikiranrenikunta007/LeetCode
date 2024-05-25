class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> d(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<vector<string>>> memo;

        // Define the solve function as a lambda
        function<vector<vector<string>>(string)> solve = [&](string s) -> vector<vector<string>> {
            if (memo.find(s) != memo.end()) {
                return memo[s];
            }
            if (s.empty()) {
                return {{}};
            }
            memo[s] = {};
            for (int i = s.length() - 1; i >= 0; --i) {
                string suffix = s.substr(i);
                if (d.find(suffix) != d.end()) {
                    vector<vector<string>> l = solve(s.substr(0, i));
                    for (auto& x : l) {
                        x.push_back(suffix);
                        memo[s].push_back(x);
                    }
                }
            }
            return memo[s];
        };

        vector<vector<string>> a = solve(s);
        vector<string> ans;
        for (auto& i : a) {
            string sentence;
            for (size_t j = 0; j < i.size(); ++j) {
                if (j > 0) {
                    sentence += " ";
                }
                sentence += i[j];
            }
            ans.push_back(sentence);
        }
        return ans;
    }
};