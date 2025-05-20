//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for Bingo card
typedef struct {
    int num[5][5];
} BingoCard;

// Function to generate a Bingo card
BingoCard* generateCard() {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    srand(time(NULL)); // Seed random number generator

    // Fill the card with random numbers from 1 to 75
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->num[i][j] = rand() % 75 + 1;
        }
    }

    return card;
}

// Function to check if the card has a Bingo
int isBingo(BingoCard* card) {
    int rowBingo = 0, colBingo = 0;

    // Check rows for Bingo
    for (int i = 0; i < 5; i++) {
        int num = 0;
        for (int j = 0; j < 5; j++) {
            if (card->num[i][j] == 75) {
                num++;
            } else if (card->num[i][j] == 0) {
                break;
            }
        }
        if (num == 5) {
            rowBingo = 1;
        }
    }

    // Check columns for Bingo
    for (int i = 0; i < 5; i++) {
        int num = 0;
        for (int j = 0; j < 5; j++) {
            if (card->num[j][i] == 75) {
                num++;
            } else if (card->num[j][i] == 0) {
                break;
            }
        }
        if (num == 5) {
            colBingo = 1;
        }
    }

    // Check diagonals for Bingo
    if (card->num[0][0] == 75 && card->num[1][1] == 75 && card->num[2][2] == 75 && card->num[3][3] == 75 && card->num[4][4] == 75) {
        return 1;
    } else if (card->num[0][4] == 75 && card->num[1][3] == 75 && card->num[2][2] == 75 && card->num[3][1] == 75 && card->num[4][0] == 75) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard* card = generateCard();
    printf("Card: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->num[i][j]);
        }
        printf("\n");
    }
    printf("Is Bingo: %s\n", isBingo(card)? "Yes" : "No");

    free(card); // Free memory allocated for the card

    return 0;
}