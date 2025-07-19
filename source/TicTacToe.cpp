// TicTacToe.cpp
#include "TicTacToe.h"
#include <iostream>
#include <limits>
using namespace std;

const int PLAYER = -1;  // Human
const int AI = +1;      // Computer

TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void TicTacToe::printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

int TicTacToe::evaluate() {
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'O') return +1;
            if (board[row][0] == 'X') return -1;
        }
    }
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'O') return +1;
            if (board[0][col] == 'X') return -1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') return +1;
        if (board[0][0] == 'X') return -1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'O') return +1;
        if (board[0][2] == 'X') return -1;
    }
    return 0;
}

bool TicTacToe::isMovesLeft() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return true;
    return false;
}

int TicTacToe::minimax(int depth, int turn) {
    int score = evaluate();
    if (score == 1 || score == -1)
        return score;
    if (!isMovesLeft())
        return 0;

    int best;
    if (turn == AI) {
        best = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = max(best, minimax(depth + 1, PLAYER));
                    board[i][j] = ' ';
                }
            }
        }
    } else {
        best = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = min(best, minimax(depth + 1, AI));
                    board[i][j] = ' ';
                }
            }
        }
    }
    return best;
}

void TicTacToe::aiMove() {
    int bestVal = -1000;
    int row = -1, col = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveVal = minimax(0, PLAYER);
                board[i][j] = ' ';
                if (moveVal > bestVal) {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    board[row][col] = 'O';
    cout << "\nAI placed O at position: (" << row+1 << ", " << col+1 << ")\n";
}

void TicTacToe::playerMove() {
    int x, y;
    do {
        cout << "Enter row and column (1-3): ";
        cin >> x >> y;
    } while (x < 1 || x > 3 || y < 1 || y > 3 || board[x-1][y-1] != ' ');
    board[x-1][y-1] = 'X';
}

void TicTacToe::play() {
    cout << "Tic-Tac-Toe AI using Minimax\nYou are X, AI is O\n";
    printBoard();
    while (true) {
        playerMove();
        printBoard();
        if (evaluate() == -1) {
            cout << "\nYou win!\n";
            break;
        } else if (!isMovesLeft()) {
            cout << "\nIt's a draw!\n";
            break;
        }

        aiMove();
        printBoard();
        if (evaluate() == 1) {
            cout << "\nAI wins!\n";
            break;
        } else if (!isMovesLeft()) {
            cout << "\nIt's a draw!\n";
            break;
        }
    }
}


// main.cpp
#include "TicTacToe.h"

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
