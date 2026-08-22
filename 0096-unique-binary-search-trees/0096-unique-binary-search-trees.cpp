class Solution {
public:
    int numTrees(int n) {
        int p = 2 * n;
        long long res = 1;

        int i = p;
        while (i > n) {
            res *= i;
            res /= (p - i + 1);
            i--;
        }

        res /= (n + 1);
        return (int)res;
    }
};