//FormAI DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

void print_board(char board[][COLUMNS]) {
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void shuffle_board(char board[][COLUMNS]) {
    srand(time(NULL));
    char temp;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            int randomI = rand() % ROWS;
            int randomJ = rand() % COLUMNS;

            temp = board[i][j];
            board[i][j] = board[randomI][randomJ];
            board[randomI][randomJ] = temp;
        }
    }
}

void initialize_board(char board[][COLUMNS]) {
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    int index = 0;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            board[i][j] = letters[index];
            index++;

            if(index == 16) {
                return;
            }
        }
    }
}

void play_game(char board[][COLUMNS], char tempBoard[][COLUMNS], int x1, int y1, int x2, int y2, int playerPoints) {
    print_board(board);

    if(board[x1][y1] == board[x2][y2]) {
        printf("MATCH\n");
        tempBoard[x1][y1] = ' ';
        tempBoard[x2][y2] = ' ';
        playerPoints += 2;

        if(playerPoints == 16) {
            printf("YOU WIN!\n");
            return;
        }
    }
    else {
        printf("NO MATCH\n");
    }

    printf("PLAYER POINTS: %d\n", playerPoints);

    printf("Enter first card position (x y): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter second card position (x y): ");
    scanf("%d %d", &x2, &y2);

    play_game(board, tempBoard, x1, y1, x2, y2, playerPoints);
}

int main() {
    char board[ROWS][COLUMNS];
    char tempBoard[ROWS][COLUMNS];

    int x1, y1, x2, y2;
    int playerPoints = 0;

    initialize_board(board);
    initialize_board(tempBoard);
    shuffle_board(board);

    printf("MEMORY GAME\n");
    printf("-----------------------\n");
    printf("Instructions:\n");
    printf("Enter the row and column number of the two cards you think will match.\n");
    printf("For example, if you want to select the card in the first row and the second column, enter 1 2 and press enter.\n");
    printf("Match all 16 cards to win the game!\n");
    printf("-----------------------\n");

    play_game(board, tempBoard, x1, y1, x2, y2, playerPoints);

    return 0;
}