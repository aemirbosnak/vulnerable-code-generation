//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(char board[9]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int checkWin(char board[9]) {
    if (board[0] == board[1] && board[1] == board[2])
        return 1;
    else if (board[3] == board[4] && board[4] == board[5])
        return 1;
    else if (board[6] == board[7] && board[7] == board[8])
        return 1;
    else if (board[0] == board[3] && board[3] == board[6])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] == board[4] && board[4] == board[6])
        return 1;
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' 
            && board[3] != '4' && board[4] != '5' && board[5] != '6' 
            && board[6] != '7' && board[7] != '8' && board[8] != '9')
        return 0;
    else
        return -1;
}

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int choice, player = 1, winner, i;
    char mark;
    srand(time(NULL));

    printf("\n ~~~~~~ WELCOME TO THE TIC-TAC-TOE GAME ~~~~~~ \n\n");

    printf("You will be playing against a robot-made of code, Good Luck! \n\n");

    printf("The flow of the game is as follows: \n\n");

    printf("1 | 2 | 3 \n");
    printf("--|---|--\n");
    printf("4 | 5 | 6 \n");
    printf("--|---|--\n");
    printf("7 | 8 | 9 \n");

    printf("\n");

    while(1) {
        if (player % 2 != 0) {
          printf("Player 1, enter a number between 1 to 9: ");
          scanf("%d", &choice);
          if (board[choice-1] == 'X' || board[choice-1] == 'O') {
            printf("This cell is already marked! Choose another one.\n\n");
            continue;
          } else {
            mark = 'X';
            board[choice-1] = mark;
          }
        } else {
          printf("Robot is thinking...\n\n");
          sleep(1);
          choice = (rand() % 9) + 1;
          if (board[choice-1] == 'X' || board[choice-1] == 'O') {
            continue;
          } else {
            mark = 'O';
            board[choice-1] = mark;
          }
        }

        display(board);

        winner = checkWin(board);

        if (winner == 1) {
            printf(" CONGRATULATIONS!! PLAYER %d WINS!!\n\n", player);
            break;
        } else if (winner == 0) {
            printf(" It's a DRAW! \n\n");
            break;
        }

        player++;
    }

    return 0;
}