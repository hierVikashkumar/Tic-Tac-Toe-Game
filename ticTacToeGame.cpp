#include <iostream>
using namespace std;

void displayBoard(const char board[3][3]);
void playerMove(char board[3][3], char currentPlayer);
bool checkWin(const char board[3][3], char currentPlayer);
bool checkDraw(const char board[3][3]);
void switchPlayer(char &currentPlayer);

int main() {
    char board[3][3];
    char currentPlayer;
    bool gameWon = false;
    bool gameDraw = false;
    char playAgain;

    do {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }

        currentPlayer = 'X';  
        gameWon = false;
        gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard(board);
            playerMove(board, currentPlayer);
            gameWon = checkWin(board, currentPlayer);
            if (!gameWon) {
                gameDraw = checkDraw(board);
                if (!gameDraw) {
                    switchPlayer(currentPlayer);
                }
            }
        }

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (gameDraw) {
            cout << "The game is a draw!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;
    return 0;
}

void displayBoard(const char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
}

void playerMove(char board[3][3], char currentPlayer) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << currentPlayer << ", enter your move (row and column: 1 2 3): ";
        cin >> row >> col;
        row--;  
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            validMove = true;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

bool checkWin(const char board[3][3], char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}