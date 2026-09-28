class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hashmap;

        for (auto &pair : knowledge) {
            hashmap[pair[0]] = pair[1];
        }

        string ans = "";
        int i = 0, n = s.size();

        while (i < n) {
            if (s[i] == '(') {
                string key = "";
                int j = i + 1;

                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                i = j + 1;

                if (hashmap.find(key) != hashmap.end())
                    ans += hashmap[key];
                else
                    ans += '?';
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};