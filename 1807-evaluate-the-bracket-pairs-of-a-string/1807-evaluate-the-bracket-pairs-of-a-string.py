class Solution(object):
    def evaluate(self, s, knowledge):
        """
        :type s: str
        :type knowledge: List[List[str]]
        :rtype: str
        """
        hashmap = {}
        for pair in knowledge:
            hashmap[pair[0]] = pair[1]

        ans = ""
        i,n = 0,len(s)

        while i < n:
            if s[i] == "(":
                key = ""
                j = i+1
                while s[j] != ")":
                    key += s[j]
                    j += 1
                i = j + 1
                if key in hashmap:
                    ans += hashmap[key]

                else:
                    ans += "?"
            else:
                ans += s[i] 
                i += 1

        return ans