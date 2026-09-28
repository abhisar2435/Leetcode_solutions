class Solution(object):
    def evaluate(self, s, knowledge):
        """
        :type s: str
        :type knowledge: List[List[str]]
        :rtype: str
        """
        hashmap = {}
        for key in knowledge:
            hashmap[key[0]] = key[1] 
        
        st = []
        
        ans = ""
        for i in range(len(s)):
            if s[i] ==  "(":
                st.append(i)
            elif s[i] == ")" and st :
                j = st.pop()
                temp = s[j+1:i] 
                if temp in hashmap:
                    ans += hashmap[temp]
                else:
                    ans += "?"
            elif not st:
                ans += s[i]

        return ans 