//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 5

void printCard(int bingoCard[ROWS][COLUMNS]);
int generateNumber(int usedNumbers[75]);
int checkBingo(int bingoCard[ROWS][COLUMNS]);

int main() {
    int bingoCard[ROWS][COLUMNS] = {{0}};
    int usedNumbers[75] = {0};
    int currentNumber;
    int totalNumbers = ROWS * COLUMNS;
    int bingo = 0;

    // Initialize Random Seed
    srand(time(0));

    // Generate Bingo Card
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            bingoCard[i][j] = generateNumber(usedNumbers);
        }
    }

    // Print Bingo Card
    printCard(bingoCard);

    // Play Bingo
    while(!bingo) {
        // Generate Random Number
        currentNumber = generateNumber(usedNumbers);

        printf("The number is: %d\n", currentNumber);

        // Check Bingo Card
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLUMNS; j++) {
                if(bingoCard[i][j] == currentNumber) {
                    bingoCard[i][j] = -1;
                }
            }
        }

        // Check Bingo
        bingo = checkBingo(bingoCard);
    }

    // Print Bingo!
    printf("Bingo!!!\n");

    return 0;
}

void printCard(int bingoCard[ROWS][COLUMNS]) {
    printf("+---+---+---+---+---+\n");
    for(int i = 0; i < ROWS; i++) {
        printf("|");
        for(int j = 0; j < COLUMNS; j++) {
            if(bingoCard[i][j] == -1) {
                printf(" X |");
            } else {
                printf(" %2d|", bingoCard[i][j]);
            }
        }
        printf("\n+---+---+---+---+---+\n");
    }
}

int generateNumber(int usedNumbers[75]) {
    int number = (rand() % 75) + 1;

    while(usedNumbers[number] != 0) {
        number = (rand() % 75) + 1;
    }

    usedNumbers[number] = 1;

    return number;
}

int checkBingo(int bingoCard[ROWS][COLUMNS]) {
    int bingo = 0;

    // Check Rows
    for(int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for(int j = 0; j < COLUMNS; j++) {
            rowSum += bingoCard[i][j];
        }
        if(rowSum == -5) {
            bingo = 1;
        }
    }

    // Check Columns
    for(int i = 0; i < COLUMNS; i++) {
        int columnSum = 0;
        for(int j = 0; j < ROWS; j++) {
            columnSum += bingoCard[j][i];
        }
        if(columnSum == -5) {
            bingo = 1;
        }
    }

    // Check Diagonals
    int diagonalSum = 0;
    for(int i = 0; i < ROWS; i++) {
        diagonalSum += bingoCard[i][i];
    }
    if(diagonalSum == -5) {
        bingo = 1;
    }
    diagonalSum = 0;
    for(int i = 0; i < ROWS; i++) {
        diagonalSum += bingoCard[i][COLUMNS - i - 1];
    }
    if(diagonalSum == -5) {
        bingo = 1;
    }

    return bingo;
}