#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 5 : Valid Sudoku

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> rows, cols; // Track used digits in rows and columns
        map<pair<int, int>, unordered_set<char>> squares;   // Track used digits in 3x3 sub-boxes

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue; // Skip empty cells

                pair<int, int> squareKey = {r / 3, c / 3}; // Identify the current 3x3 box

                // Check if current number already exists in row, column or box
                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) ||
                    squares[squareKey].count(board[r][c]))
                {
                    return false; // Invalid Sudoku
                }

                // Mark the digit as seen in row, column and box
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }

        return true; // All rules passed
    }
};
