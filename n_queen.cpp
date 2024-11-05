#include <iostream>
#include <vector>
using namespace std;

#define N 8  // You can change N to any number

// Function to print the board configuration
void printBoard(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col) {
    // Check this column on upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to solve N-Queen problem using backtracking
bool solveNQueensUtil(vector<vector<int>> &board, int row) {
    // If all queens are placed, return true
    if (row >= N)
        return true;

    // Try placing queen in all columns one by one for this row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, row + 1))
                return true;

            // If placing queen here leads to a solution failure, backtrack
            board[row][col] = 0;
        }
    }

    // If queen cannot be placed in any column for this row, return false
    return false;
}

// Function to solve the N-Queen problem
bool solveNQueens() {
    vector<vector<int>> board(N, vector<int>(N, 0));  // Initialize an N x N board

    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist." << endl;
        return false;
    }

    // Print the solution
    printBoard(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}
