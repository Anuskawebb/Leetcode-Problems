class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int start = 0;
        unordered_map<char, int> charIndex;

        for (int i = 0; i < s.size(); ++i) {
            if (charIndex.count(s[i]) && charIndex[s[i]] >= start) {
                start = charIndex[s[i]] + 1;
            }
            charIndex[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};
