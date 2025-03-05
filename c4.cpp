#include <iostream>
using namespace std;

class Connect4 {
private:
    char board[6][7]; // 6x7 grid for the game board
    int currentPlayer; // 1 for player 1, 2 for player 2

public:
    Connect4() {
        // Initialize game board to empty spaces
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 1; // Player 1 goes first
    }

    void displayBoard() {
        // Print out the game board
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                cout << "|" << board[i][j];
            }
            cout << "|" << endl;
        }
        cout << " 1 2 3 4 5 6 7" << endl;
    }

    bool makeMove(int column) {
        // Place the current player's piece in the specified column
        if (column < 1 || column > 7) {
            cout << "Invalid column number. Please choose a column between 1 and 7." << endl;
            return false;
        }
        for (int i = 5; i >= 0; i--) {
            if (board[i][column - 1] == ' ') {
                board[i][column - 1] = (currentPlayer == 1 ? 'X' : 'O');
                return true;
            }
        }
        cout << "Column is full. Please choose another column." << endl;
        return false;
    }

    bool checkWin() {
        char piece = (currentPlayer == 1 ? 'X' : 'O');
        
        // Check horizontal
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == piece && board[i][j+1] == piece && board[i][j+2] == piece && board[i][j+3] == piece) {
                    return true;
                }
            }
        }
        // Check vertical
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] == piece && board[i+1][j] == piece && board[i+2][j] == piece && board[i+3][j] == piece) {
                    return true;
                }
            }
        }
        // Check diagonal (top-left to bottom-right)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == piece && board[i+1][j+1] == piece && board[i+2][j+2] == piece && board[i+3][j+3] == piece) {
                    return true;
                }
            }
        }
        // Check diagonal (top-right to bottom-left)
        for (int i = 0; i < 3; i++) {
            for (int j = 3; j < 7; j++) {
                if (board[i][j] == piece && board[i+1][j-1] == piece && board[i+2][j-2] == piece && board[i+3][j-3] == piece) {
                    return true;
                }
            }
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 1 ? 2 : 1);
    }

    void playGame() {
        int column;
        bool moveSuccessful;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter a column number to place your piece: ";
            cin >> column;
            moveSuccessful = makeMove(column);
            if (moveSuccessful) {
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                switchPlayer();
            }
        }
    }
};

int main() {
    Connect4 game;
    game.playGame();
    return 0;
}
