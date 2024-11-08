class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, maxLength = 1;

       
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            int length = right - left - 1; // length of the palindrone
            if (length > maxLength) {
                maxLength = length;
                start = left + 1; 
            }
        };

        // Check for all possible centers
        for (int i = 0; i < n; ++i) {
            expandAroundCenter(i, i);     // Odd-length palindrome
            expandAroundCenter(i, i + 1); // Even-length palindrome
        }

        return s.substr(start, maxLength);
    }
};
