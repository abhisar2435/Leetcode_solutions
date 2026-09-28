class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hashmap;

        for (auto& key : knowledge) {
            hashmap[key[0]] = key[1];
        }

        stack<int> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }

            else if (s[i] == ')' && !st.empty()) {
                int j = st.top();
                st.pop();

                string temp = s.substr(j + 1, i - j - 1);

                if (hashmap.find(temp) != hashmap.end()) {
                    ans += hashmap[temp];
                }
                else {
                    ans += "?";
                }
            }

            else if (st.empty()) {
                ans += s[i];
            }
        }

        return ans;
    }
};