class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for the sign
        bool isNegative = false;
        if (i < n && s[i] == '-') {
            isNegative = true;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }
        
        // Step 3: Read digits and convert to integer
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;
            
            // Step 4: Check for overflow
            if (result > INT_MAX) {
                return isNegative ? INT_MIN : INT_MAX;
            }
        }
        
        // Step 5: Apply the sign
        if (isNegative) {
            result = -result;
        }
        
        // Step 6: Return the result as an integer
        return (int)result;
    }
};
