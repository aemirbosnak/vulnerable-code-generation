//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define RANGE 75

// Function prototypes
void print_card(int card[ROWS][COLS]);
int generate_number(int used_numbers[]);
void mark_number(int card[ROWS][COLS], int number);
int check_bingo(int card[ROWS][COLS]);

int main() {
    int card[ROWS][COLS] = {0}; // Initialize card with zeros
    int used_numbers[RANGE] = {0}; // Keep track of which numbers have been called
    int num_calls = 0;
    int number = 0;
    int bingo = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the bingo card
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            // Generate a unique number for each square
            card[row][col] = generate_number(used_numbers);
        }
    }

    // Print the bingo card
    printf("BINGO CARD:\n");
    print_card(card);

    // Play the game until someone gets bingo
    while (!bingo) {
        // Generate a number that hasn't been called yet
        number = generate_number(used_numbers);
        used_numbers[number] = 1;

        // Mark the number on the card
        mark_number(card, number);

        // Increment the number of calls made
        num_calls++;

        // Check if anyone has bingo
        bingo = check_bingo(card);

        // Print the number called and the updated card
        printf("Number called: %d\n", number);
        printf("Updated card:\n");
        print_card(card);
    }

    // Print the winner and the number of calls made
    printf("BINGO! Winner after %d calls.\n", num_calls);

    return 0;
}

void print_card(int card[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%2d ", card[row][col]);
        }
        printf("\n");
    }
}

int generate_number(int used_numbers[]) {
    int number;
    do {
        number = rand() % RANGE + 1; // Generate a random number between 1 and RANGE (inclusive)
    } while (used_numbers[number]); // Loop until a unique number is found
    return number;
}

void mark_number(int card[ROWS][COLS], int number) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] == number) {
                card[row][col] = -1; // Mark the number as called
                return;
            }
        }
    }
}

int check_bingo(int card[ROWS][COLS]) {
    int bingo = 0;
    int row_sum = 0;
    int col_sum = 0;
    int diag_sum1 = 0;
    int diag_sum2 = 0;

    // Check for diagonal bingo
    for (int i = 0; i < ROWS; i++) {
        diag_sum1 += card[i][i];
        diag_sum2 += card[i][COLS-i-1];
    }
    if (diag_sum1 == -ROWS || diag_sum2 == -ROWS) {
        bingo = 1;
        return bingo;
    }

    // Check for row bingo
    for (int row = 0; row < ROWS; row++) {
        row_sum = 0;
        for (int col = 0; col < COLS; col++) {
            row_sum += card[row][col];
        }
        if (row_sum == -COLS) {
            bingo = 1;
            return bingo;
        }
    }

    // Check for column bingo
    for (int col = 0; col < COLS; col++) {
        col_sum = 0;
        for (int row = 0; row < ROWS; row++) {
            col_sum += card[row][col];
        }
        if (col_sum == -ROWS) {
            bingo = 1;
            return bingo;
        }
    }

    return bingo;
}