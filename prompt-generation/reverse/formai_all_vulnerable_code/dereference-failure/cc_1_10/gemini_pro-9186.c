//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo cards to generate
#define NUM_CARDS 5

// Define the range of numbers to use for bingo
#define MIN_NUM 1
#define MAX_NUM 75

// Create a bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = malloc(CARD_SIZE * sizeof(int*));
    for (int i = 0; i < CARD_SIZE; i++) {
        card[i] = malloc(CARD_SIZE * sizeof(int));
    }

    // Initialize the card with random numbers
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card[i][j] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
        }
    }

    // Return the card
    return card;
}

// Print a bingo card
void print_card(int** card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Check if a bingo card has won
int check_card(int** card, int* numbers) {
    // Check each row
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            for (int k = 0; k < 5; k++) {
                if (card[i][j] == numbers[k]) {
                    count++;
                }
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    // Check each column
    for (int j = 0; j < CARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < CARD_SIZE; i++) {
            for (int k = 0; k < 5; k++) {
                if (card[i][j] == numbers[k]) {
                    count++;
                }
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    // Check each diagonal
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int k = 0; k < 5; k++) {
            if (card[i][i] == numbers[k]) {
                count1++;
            }
            if (card[i][CARD_SIZE - 1 - i] == numbers[k]) {
                count2++;
            }
        }
    }
    if (count1 == 5 || count2 == 5) {
        return 1;
    }

    // No bingo
    return 0;
}

// Generate a random set of numbers
int* generate_numbers() {
    // Allocate memory for the numbers
    int* numbers = malloc(5 * sizeof(int));

    // Initialize the numbers with random numbers
    for (int i = 0; i < 5; i++) {
        numbers[i] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    }

    // Return the numbers
    return numbers;
}

// Play a game of bingo
void play_bingo() {
    // Create the bingo cards
    int*** cards = malloc(NUM_CARDS * sizeof(int**));
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = create_card();
    }

    // Print the bingo cards
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("Card %d:\n", i + 1);
        print_card(cards[i]);
        printf("\n");
    }

    // Generate a random set of numbers
    int* numbers = generate_numbers();

    // Print the numbers
    printf("Numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Check each card for a bingo
    for (int i = 0; i < NUM_CARDS; i++) {
        if (check_card(cards[i], numbers)) {
            printf("Card %d has won!\n", i + 1);
        }
    }

    // Free the memory
    for (int i = 0; i < NUM_CARDS; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            free(cards[i][j]);
        }
        free(cards[i]);
    }
    free(cards);
    free(numbers);
}

int main() {
    //srand(time(NULL));
    play_bingo();
    return 0;
}