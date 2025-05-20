//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
// C Bingo Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 75
int generateRandomNumber() {
    return rand() % 75 + 1;
}

// Function to print the bingo card
void printBingoCard(int card[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a line is complete
int checkLine(int card[5][5], int line) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (card[i][line]!= 0) {
            count++;
        }
    }
    return count;
}

// Function to check if the card is complete
int checkCard(int card[5][5]) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        count += checkLine(card, i);
        count += checkLine(card, i + 5);
        count += checkLine(card, i + 10);
        count += checkLine(card, i + 15);
    }
    return count;
}

// Function to generate a random bingo card
void generateBingoCard(int card[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = generateRandomNumber();
        }
    }
}

int main() {
    srand(time(NULL));

    int bingoCard[5][5];
    generateBingoCard(bingoCard);

    printf("Bingo Card:\n");
    printBingoCard(bingoCard);

    int userCard[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Enter number for position [%d][%d]: ", i, j);
            scanf("%d", &userCard[i][j]);
        }
    }

    int userScore = checkCard(userCard);
    printf("\nUser Score: %d\n", userScore);

    return 0;
}