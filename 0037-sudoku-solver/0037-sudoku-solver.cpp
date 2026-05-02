class Solution {
    bool isSafe(int row, int col, char ch, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) return false; // row check
            if(board[i][col] == ch) return false; // column check

            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if(board[boxRow][boxCol] == ch) return false; // 3x3 box check
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    for(char ch = '1'; ch <= '9'; ch++) {

                        if(isSafe(i, j, ch, board)) {
                            board[i][j] = ch;

                            if(solve(board)) return true;

                            board[i][j] = '.'; // backtrack
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};