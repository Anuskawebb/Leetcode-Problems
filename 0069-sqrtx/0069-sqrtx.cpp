class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; 
        
        int left = 0, right = x, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if ((long long)mid * mid == x) {
                return mid;
            } else if ((long long)mid * mid < x) {
                result = mid; 
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
