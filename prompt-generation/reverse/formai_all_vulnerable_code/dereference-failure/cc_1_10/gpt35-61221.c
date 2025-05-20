//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display_board(char board[][3]);
char check_win(char board[][3]);
void player_turn(char board[][3], char player);
void computer_turn(char board[][3], char player);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    char winner = ' ';
    int turn_count = 0;

    printf("Welcome to Shape Shifting Tic Tac Toe!\n");
    printf("Enter the position of your move in the following format: row,column\n");
    printf("For example, enter 1,2 for the first row and second column.\n");
    printf("You are X and the computer is O.\n");

    while (winner == ' ' && turn_count < 9) {
        display_board(board);
        if (player == 'X') {
            player_turn(board, player);
        } else {
            computer_turn(board, player);
        }
        winner = check_win(board);
        player = (player == 'X') ? 'O' : 'X';
        turn_count++;
    }

    display_board(board);
    if (winner == ' ') {
        printf("The game is a draw.\n");
    } else {
        printf("%c is the winner!\n", winner);
    }

    return 0;
}

void display_board(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

char check_win(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' ';
}

void player_turn(char board[][3], char player) {
    int row, col;
    printf("Enter your move: ");
    scanf("%d,%d", &row, &col);

    while (board[row - 1][col - 1] != ' ') {
        printf("Invalid move. Enter your move: ");
        scanf("%d,%d", &row, &col);
    }

    board[row - 1][col - 1] = player;
}

void computer_turn(char board[][3], char player) {
    int row, col;
    srand(time(NULL));
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = player;
}