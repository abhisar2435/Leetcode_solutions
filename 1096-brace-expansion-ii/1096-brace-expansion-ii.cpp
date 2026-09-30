class Solution {
public:
    set<string>parse(string &s,int &i){
        set<string >result;
        vector<string>current = {""};
        while (i<s.size() && s[i]!='}') {
            if (s[i] == ',') {
                for (string &x:current) result.insert(x);

                current = {""};
                i++;
            }

            else if (s[i]=='{') {
                i++;  // skip '{'
                set<string> nested = parse(s, i);
                vector<string> next;
                for (const auto  &a : current) {
                    for (const auto  &b : nested) {
                        next.push_back(a + b);
                    }
                }

                current = next;
                i++;
            }

            else {
                for (string &x : current)
                    x += s[i];

                i++;
            }
        }
        for (string &x : current)
            result.insert(x);

        return result;
    }
    vector<string> braceExpansionII(string expression) {
        int i=0;
        set<string>result=parse(expression,i);
        return vector<string>(result.begin(),result.end());

    }
};