class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            x = 1 / x;
            n = -(long long)n;
        }
        double result = 1;
        while (n) {
            if (n % 2) result *= x;
            x *= x;
            n /= 2;
        }
        return result;
    }
};
