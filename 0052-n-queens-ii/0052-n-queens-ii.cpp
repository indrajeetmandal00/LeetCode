#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Optimized safety check (Only inspects upper rows)
    bool CheckAttackORnot(vector<string>& Board, int Row, int Col, int n) {
        // 1) Vertical Check (Upper direction only)
        for (int r = 0; r < Row; r++) {
            if (Board[r][Col] == 'Q') return false;
        }

        // 2) Upper-Left Diagonal Check
        for (int r = Row - 1, c = Col - 1; r >= 0 && c >= 0; r--, c--) {
            if (Board[r][c] == 'Q') return false;
        }

        // 3) Upper-Right Diagonal Check
        for (int r = Row - 1, c = Col + 1; r >= 0 && c < n; r--, c++) {
            if (Board[r][c] == 'Q') return false;
        }

        return true;
    }

    void CallAttackQueen(vector<string>& Board, int Row, int n, int& count) {
        // Base Case: All n queens placed successfully
        if (Row == n) {
            count++;
            return;
        }

        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {
            if (CheckAttackORnot(Board, Row, col, n)) {
                Board[Row][col] = 'Q';                  // Place Queen
                CallAttackQueen(Board, Row + 1, n, count); // Recurse
                Board[Row][col] = '.';                  // Backtrack
            }
        }
    }

    int totalNQueens(int n) {
        int count = 0;
        vector<string> Board(n, string(n, '.'));
        CallAttackQueen(Board, 0, n, count);
        return count;
    }
};