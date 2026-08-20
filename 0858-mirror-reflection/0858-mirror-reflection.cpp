class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        int a = p / g;
        int b = q / g;

        if (a % 2 == 0 && b % 2 == 1) return 2;
        if (a % 2 == 1 && b % 2 == 1) return 1;
        return 0;
    }
};