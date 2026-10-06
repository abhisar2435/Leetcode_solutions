class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int len = words[0].size();

        unordered_map<string, int> need;

        for (string word : words) {
            need[word]++;
        }

        vector<int> ans;

        for (int offset = 0; offset < len; offset++) {
            int left = offset;
            int right = offset;
            int cnt = 0;

            unordered_map<string, int> have;

            while (right + len <= n) {
                string word = s.substr(right, len);
                right += len;

                if (need.count(word)) {
                    have[word]++;
                    cnt++;

                    while (have[word] > need[word]) {
                        string removeWord = s.substr(left, len);
                        have[removeWord]--;
                        left += len;
                        cnt--;
                    }

                    if (cnt == m) {
                        ans.push_back(left);

                        // Move window forward
                        string removeWord = s.substr(left, len);
                        have[removeWord]--;
                        left += len;
                        cnt--;
                    }
                }
                else {
                    have.clear();
                    cnt = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};