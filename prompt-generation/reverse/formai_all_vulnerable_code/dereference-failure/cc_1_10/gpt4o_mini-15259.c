//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define MAX_NUM 75
#define PLAYERS 2

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void initializeCard(BingoCard *bingoCard);
void printCard(BingoCard *bingoCard);
void drawNumber(int *drawnNumbers, int *count);
int checkWin(BingoCard *bingoCard);
void markNumber(BingoCard *bingoCard, int number);
void displayResult(int player, int winner);

int main() {
    srand(time(NULL));
    BingoCard players[PLAYERS];
    int drawnNumbers[MAX_NUM] = {0};
    int drawnCount = 0;
    int winner = -1;
    
    printf("Welcome to the Bingo Simulator!\n\n");
    
    // Initialize players' bingo cards
    for (int i = 0; i < PLAYERS; i++) {
        initializeCard(&players[i]);
        printf("Player %d's Bingo Card:\n", i + 1);
        printCard(&players[i]);
        printf("\n");
    }
    
    while (drawnCount < MAX_NUM && winner == -1) {
        drawNumber(drawnNumbers, &drawnCount);
        
        for (int i = 0; i < PLAYERS; i++) {
            markNumber(&players[i], drawnNumbers[drawnCount-1]);
            if (checkWin(&players[i])) {
                winner = i;
                break;
            }
        }
    }
    
    displayResult(winner, winner);
    return 0;
}

// Function to initialize bingo card with random numbers
void initializeCard(BingoCard *bingoCard) {
    int nums[BINGO_SIZE][15] = {0}; // 1-15, 16-30, 31-45, 46-60, 61-75
    for (int i = 0; i < 5; i++) {
        int colStart = i * 15 + 1;
        while (nums[i][0] < BINGO_SIZE) {
            int num = rand() % 15 + colStart;
            if (nums[i][num - colStart] == 0) { // Not already used
                nums[i][num - colStart] = num;
                bingoCard->card[nums[i][0]][i] = num;
                nums[i][0]++;
            }
        }
    }
    bingoCard->card[2][BINGO_SIZE / 2] = 0; // Free space
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            bingoCard->marked[i][j] = 0; // Reset marked
        }
    }
}

// Function to print the bingo card
void printCard(BingoCard *bingoCard) {
    printf(" B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (bingoCard->card[i][j] == 0) {
                printf(" *  ");
            } else {
                printf("%2d  ", bingoCard->card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to draw a number and mark it in the drawn numbers list
void drawNumber(int *drawnNumbers, int *count) {
    int number;
    while (1) {
        number = rand() % MAX_NUM + 1;
        if (!drawnNumbers[number - 1]) {
            drawnNumbers[number - 1] = number;
            (*count)++;
            printf("Drawn number: %d\n", number);
            break;
        }
    }
}

// Function to check if a player has won
int checkWin(BingoCard *bingoCard) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (bingoCard->marked[i][0] + bingoCard->marked[i][1] + bingoCard->marked[i][2] +
            bingoCard->marked[i][3] + bingoCard->marked[i][4] == BINGO_SIZE) {
            return 1; // Win found in row
        }
        if (bingoCard->marked[0][i] + bingoCard->marked[1][i] + bingoCard->marked[2][i] +
            bingoCard->marked[3][i] + bingoCard->marked[4][i] == BINGO_SIZE) {
            return 1; // Win found in column
        }
    }

    // Check diagonals
    if (bingoCard->marked[0][0] + bingoCard->marked[1][1] + bingoCard->marked[2][2] +
        bingoCard->marked[3][3] + bingoCard->marked[4][4] == BINGO_SIZE) {
        return 1; // Win found in diagonal
    }
    if (bingoCard->marked[0][4] + bingoCard->marked[1][3] + bingoCard->marked[2][2] +
        bingoCard->marked[3][1] + bingoCard->marked[4][0] == BINGO_SIZE) {
        return 1; // Win found in anti-diagonal
    }

    return 0; // No win found
}

// Function to mark a drawn number on the bingo card
void markNumber(BingoCard *bingoCard, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (bingoCard->card[i][j] == number) {
                bingoCard->marked[i][j] = 1;
                printf("Marked number %d on the card!\n", number);
            }
        }
    }
}

// Function to display the result of the game
void displayResult(int player, int winner) {
    if (winner != -1) {
        printf("Congratulations! Player %d wins Bingo!\n", player + 1);
    } else {
        printf("No winner this time. Better luck next time!\n");
    }
}