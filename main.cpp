#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize/reset board
void resetBoard() {
    char cell = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell++;
        }
    }

    currentPlayer = 'X';
}

// Function to display board
void displayBoard() {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << "\n";

        if (i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

// Function to make move
void makeMove() {
    int choice;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << currentPlayer
             << ", enter position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already occupied! Try again.\n";
        } else {
            board[row][col] = currentPlayer;
            validMove = true;
        }
    }
}

// Function to check winner
bool checkWin() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Main diagonal
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    // Secondary diagonal
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main() {
    char playAgain;

    do {
        resetBoard();

        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            makeMove();

            if (checkWin()) {
                displayBoard();
                cout << "Player "
                     << currentPlayer
                     << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "Match Draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer =
                    (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}