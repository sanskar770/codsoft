#include <iostream>
#include <vector>
#include <string>

// Function to initialize the game board
void initializeBoard(std::vector<std::vector<std::string>>& board) {
    for (int i = 0; i < 3; ++i) {
        std::vector<std::string> row;
        for (int j = 0; j < 3; ++j) {
            row.push_back(" ");
        }
        board.push_back(row);
    }
}

// Function to display the game board
void displayBoard(const std::vector<std::vector<std::string>>& board) {
    for (const auto& row : board) {
        for (const std::string& cell : row) {
            std::cout << "|" << cell;
        }
        std::cout << "|" << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<std::string>>& board, const std::string& player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal from top-left to bottom-right
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal from top-right to bottom-left
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<std::string>>& board) {
    for (const auto& row : board) {
        for (const std::string& cell : row) {
            if (cell == " ") {
                return false; // There is an empty cell, the game is not a draw yet
            }
        }
    }
    return true; // All cells are filled, the game is a draw
}

int main() {
    std::vector<std::vector<std::string>> board;
    initializeBoard(board);

    std::string currentPlayer = "X";
    bool gameOver = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (!gameOver) {
        std::cout << "Current board:" << std::endl;
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
        std::cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != " ") {
            std::cout << "Invalid move. Try again." << std::endl;
        } else {
            board[row - 1][col - 1] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                std::cout << "It's a draw!" << std::endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == "X") ? "O" : "X"; // Switch players
            }
        }
    }

    std::cout << "Final board:" << std::endl;
    displayBoard(board);

    return 0;
}
