class Solution {
public:
    bool isMatch(string s, string p) {

        // 1 Based Indexing
        int i = s.length();
        int j = p.length();

        vector<int> prev(j + 1, false);
        vector<int> curr(j + 1, false);

        // Base Case
        prev[0] = true;

        // When s is empty, p must contain only '*'
        for (int m = 1; m <= j; m++) {
            bool flag = true;

            for (int k = 1; k <= m; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            prev[m] = flag;
        }

        for (int n = 1; n <= i; n++) {

            curr[0] = false;

            for (int m = 1; m <= j; m++) {

                if (p[m - 1] == s[n - 1] || p[m - 1] == '?') {
                    curr[m] = prev[m - 1];
                }

                else if (p[m - 1] == '*') {
                    curr[m] = prev[m] | curr[m - 1];
                }

                // Else if string not matched && p[m - 1] != '*' OR '?'
                // return false
                else {
                    curr[m] = false;
                }
            }

            prev = curr;
        }

        return prev[j];
    }
};