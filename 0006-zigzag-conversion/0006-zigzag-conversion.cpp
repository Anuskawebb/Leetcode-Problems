#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;  // No zigzag needed
        }

        std::vector<std::string> rows(std::min(numRows, (int)s.length())); // Create rows
        int curRow = 0;
        bool goingDown = false;  // Direction flag

        for (char c : s) {
            rows[curRow] += c;  // Place the character in the current row
            if (curRow == 0) {
                goingDown = true;  // Start going down
            } else if (curRow == numRows - 1) {
                goingDown = false; // Start going up
            }
            curRow += goingDown ? 1 : -1; // Change the row index
        }

        // Combine all rows into one string
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
