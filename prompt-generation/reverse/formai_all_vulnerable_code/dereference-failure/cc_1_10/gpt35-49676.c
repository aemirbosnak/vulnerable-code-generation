//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>

// function to print the tic tac toe board
void print_board(char board[3][3]) {
    printf("----------------\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n----------------\n");
    }
}

// function to check if a player has won
int check_win(char board[3][3], char player) {
    int diag1 = 1, diag2 = 1;
    for(int i = 0; i < 3; i++) {
        int row = 1, col = 1;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != player) // check row
                row = 0;
            if(board[j][i] != player) // check column
                col = 0;
        }
        if(row || col) // player has won
            return 1;
        if(board[i][i] != player) // check diagonal
            diag1 = 0;
        if(board[i][2-i] != player) // check other diagonal
            diag2 = 0;
    }
    if(diag1 || diag2) // player has won
        return 1;
    return 0;
}

// function to get the next move from the player or AI
void get_move(char board[3][3], char player) {
    if(player == 'X')
        printf("Player X's turn!\n");
    else
        printf("Player O's turn!\n");

    if(player == 'X') { // player's turn
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        if(board[row-1][col-1] != ' ') { // spot already taken
            printf("Spot already taken, try again!\n");
            get_move(board, player);
        }
        else // valid move
            board[row-1][col-1] = player;
    }
    else { // AI's turn
        // TODO: implement tic tac toe AI
    }
}

int main() {
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    print_board(board);

    char player = 'X';
    while(!check_win(board, player)) {
        get_move(board, player);
        print_board(board);
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    if(player == 'X')
        printf("Congratulations, player O wins!\n");
    else
        printf("Congratulations, player X wins!\n");

    return 0;
}