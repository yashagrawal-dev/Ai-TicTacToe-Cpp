// TicTacToe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();
    void printBoard();
    void playerMove();
    void aiMove();
    bool isMovesLeft();
    int evaluate();
    void play();

private:
    char board[3][3];
    int minimax(int depth, int turn);
};

#endif // TICTACTOE_H
