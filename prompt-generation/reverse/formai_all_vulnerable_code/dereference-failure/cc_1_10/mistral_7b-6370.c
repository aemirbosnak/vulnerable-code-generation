//MISTRAL-7B DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_CARD_SIZE 5
#define BINGO_CARD_WIDTH 5

// Function to generate a random number between 1 and 75
int random_number_generator(void) {
    return rand() % 75 + 1;
}

// Function to print a random number and mark its corresponding position on a bingo card
void call_bingo_number(int number, int bingo_card[BINGO_CARD_SIZE][BINGO_CARD_WIDTH]) {
    printf("Number called: %d\n", number);
    bingo_card[number % BINGO_CARD_SIZE][number / BINGO_CARD_SIZE] = number;
}

// Function to check if a bingo card is full
int is_bingo_card_full(int bingo_card[BINGO_CARD_SIZE][BINGO_CARD_WIDTH]) {
    int i, j;
    for (i = 0; i < BINGO_CARD_SIZE; i++) {
        for (j = 0; j < BINGO_CARD_WIDTH; j++) {
            if (bingo_card[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print a bingo card
void print_bingo_card(int bingo_card[BINGO_CARD_SIZE][BINGO_CARD_WIDTH]) {
    int i, j;
    printf("-----------------------------------------\n");
    for (i = 0; i < BINGO_CARD_SIZE; i++) {
        printf("| ");
        for (j = 0; j < BINGO_CARD_WIDTH; j++) {
            if (bingo_card[i][j] > 0) {
                printf("%2d ", bingo_card[i][j]);
            } else {
                printf(" _ ");
            }
        }
        printf("|\n");
    }
    printf("-----------------------------------------\n");
}

// Function to simulate a game of bingo
void play_bingo(void) {
    int bingo_card[BINGO_CARD_SIZE][BINGO_CARD_WIDTH], i, j, number;
    srand(time(NULL));

    // Initialize bingo card with zeros
    for (i = 0; i < BINGO_CARD_SIZE; i++) {
        for (j = 0; j < BINGO_CARD_WIDTH; j++) {
            bingo_card[i][j] = 0;
        }
    }

    printf("Your bingo card:\n");
    print_bingo_card(bingo_card);

    while (!is_bingo_card_full(bingo_card)) {
        number = random_number_generator();
        call_bingo_number(number, bingo_card);
        print_bingo_card(bingo_card);
    }

    printf("\nCongratulations! You've won BINGO!\n");
}

int main(void) {
    play_bingo();
    return 0;
}