//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBingoCard(int card[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

void printBingoCard(int card[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void playBingo(int card[5][5], int numbers[75]) {
    int won = 0;
    int calledNumbers[75];
    int count = 0;

    srand(time(NULL));
    for (int i = 0; i < 75; i++) {
        calledNumbers[i] = rand() % 75 + 1;
    }

    for (int i = 0; i < 75; i++) {
        printf("%d ", calledNumbers[i]);
        if (card[i / 15][i % 15] == calledNumbers[i]) {
            printf("*");
            won = 1;
        }
    }

    if (won) {
        printf("\nCongratulations! You won!");
    } else {
        printf("\nSorry, you lost.");
    }
}

int main() {
    int card[5][5];
    int numbers[75];

    generateBingoCard(card);
    printBingoCard(card);

    generateBingoCard(numbers);

    playBingo(card, numbers);

    return 0;
}