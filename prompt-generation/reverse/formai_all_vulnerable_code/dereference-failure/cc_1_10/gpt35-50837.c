//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 5
#define MAX_NUMBER 25
#define MIN_NUMBER 1

typedef struct {
    int **board;
    int *numbers;
    int *calledNumbers;
} BingoGame;

static void generateNumbers(BingoGame *game) {
    game->numbers = (int *) malloc(sizeof(int) * MAX_NUMBER);
    for (int i=0; i<MAX_NUMBER; i++) {
        game->numbers[i] = i+1;
    }
}

static void printBoard(BingoGame *game) {
    for (int i=0; i<ROW_SIZE; i++) {
        for (int j=0; j<COLUMN_SIZE; j++) {
            printf("%d\t", game->board[i][j]);
        }
        printf("\n");
    }
}

static void generateBoard(BingoGame *game) {
    game->board = (int **) malloc(sizeof(int *) * ROW_SIZE);
    for (int i=0; i<ROW_SIZE; i++) {
        game->board[i] = (int *) malloc(sizeof(int) * COLUMN_SIZE);
    }
    for (int i=0; i<ROW_SIZE; i++) {
        for (int j=0; j<COLUMN_SIZE; j++) {
            game->board[i][j] = 0;
        }
    }
}

static void shuffleNumbers(BingoGame *game) {
    srand(time(NULL));
//shuffle the numbers array using Fisher-Yates shuffle algorithm
    for (int i=MAX_NUMBER-1; i>=1; i--) {
        int j = rand() % (i+1);
        int tempNumber = game->numbers[i];
        game->numbers[i] = game->numbers[j];
        game->numbers[j] = tempNumber;
    }
}

static void callNumber(BingoGame *game) {
    srand(time(NULL));
    int calledNumberIndex = rand() % MAX_NUMBER;
    game->calledNumbers[calledNumberIndex] = game->numbers[calledNumberIndex];
    printf("Called number: %d\n", game->numbers[calledNumberIndex]);
}

static void markBoard(BingoGame *game, int calledNumber) {
    for (int i=0; i<ROW_SIZE; i++) {
        for (int j=0; j<COLUMN_SIZE; j++) {
            if (game->board[i][j] == calledNumber) {
                game->board[i][j] = -1;
            }
        }
    }
}

static int checkDiagonal(BingoGame *game) {
    int count = 0;
    for (int i=0; i<ROW_SIZE; i++) {
        if (game->board[i][i] == -1) {
            count++;
        }
    }
    if (count == ROW_SIZE) {
        return 1;
    }

    count = 0;
    for (int i=0; i<ROW_SIZE; i++) {
        if (game->board[i][ROW_SIZE-1-i] == -1) {
            count++;
        }
    }
    if (count == ROW_SIZE) {
        return 1;
    }
    return 0;
}

static int checkRow(BingoGame *game) {
    for (int i=0; i<ROW_SIZE; i++) {
        int count = 0;
        for (int j=0; j<COLUMN_SIZE; j++) {
            if (game->board[i][j] == -1) {
                count++;
            }
        }
        if (count == ROW_SIZE) {
            return 1;
        }
    }
    return 0;
}

static int checkColumn(BingoGame *game) {
    for (int i=0; i<COLUMN_SIZE; i++) {
        int count = 0;
        for (int j=0; j<ROW_SIZE; j++) {
            if (game->board[j][i] == -1) {
                count++;
            }
        }
        if (count == COLUMN_SIZE) {
            return 1;
        }
    }
    return 0;
}

static int checkAll(BingoGame *game) {
    if (checkRow(game) == 1 || checkColumn(game) == 1 || checkDiagonal(game) == 1) {
        return 1;
    }
    return 0;
}

static void playGame(BingoGame *game) {
    while(1) {
        callNumber(game);
        markBoard(game, game->calledNumbers[MAX_NUMBER-1]);

        if (checkAll(game) == 1) {
            printf("BINGO!!!");
            break;
        }
    }
}

int main() {
    BingoGame game;
    game.calledNumbers = (int *) malloc(sizeof(int) * MAX_NUMBER);

    generateNumbers(&game);
    shuffleNumbers(&game);
    generateBoard(&game);
    printBoard(&game);

    playGame(&game);

    return 0;
}