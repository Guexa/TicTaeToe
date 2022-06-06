/* 
 * File:   main.cpp
 * Author: guexa
 *
 * Created on 6 de Junho de 2022, 10:14
 */

#include<iostream>
#include<cstdLib>

using namespace std;

bool turnOfX = false;

char board[][3] = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
};

char win() {

    //Horizontal validation
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    //Vertical validation
    for (int i = 0; i < 3; i++) {
        if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    //Diagonal validation left -> right
    if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    //Diagonal validation right -> left
    if (board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
}

bool draw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                return false;
            }
        }
    }
    return true;
}

void showBoard() {

    char player = turnOfX ? 'X' : 'O';
    int row = 0;
    int column = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board [i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "Turn of: " << player << endl;
    cout << "In which row do you want to play?";
    cin >> row;

    cout << "In which column do you want to play?";
    cin >> column;

    board[row][column] = player;

    char winner = win();

    if (winner != '_') {
        cout << "You win " << winner;
        exit(0);
    }

    if (draw()) {
        cout << "Is a draw " << endl;
        exit(0);
    }
    
    turnOfX = !turnOfX;
}

int main(int argc, char **argv) {

    while (true) {
        showBoard();
    }
}