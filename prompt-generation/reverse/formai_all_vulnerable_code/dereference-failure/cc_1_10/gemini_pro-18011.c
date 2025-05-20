//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random number between 1 and 90
int generate_random_number() {
    return rand() % 90 + 1;
}

// Check if a number is in an array
int check_if_number_in_array(int number, int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

// Generate a unique bingo card
int *generate_unique_bingo_card() {
    int *bingo_card = malloc(sizeof(int) * 25);

    for (int i = 0; i < 25; i++) {
        int number = generate_random_number();

        while (check_if_number_in_array(number, bingo_card, i)) {
            number = generate_random_number();
        }

        bingo_card[i] = number;
    }

    return bingo_card;
}

// Print a bingo card
void print_bingo_card(int *bingo_card) {
    for (int i = 0; i < 25; i++) {
        printf("%d ", bingo_card[i]);

        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

// Check if a bingo card has won
int check_if_bingo_card_has_won(int *bingo_card, int called_numbers[], int size) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        int count = 0;

        for (int j = 0; j < 5; j++) {
            if (check_if_number_in_array(bingo_card[i * 5 + j], called_numbers, size)) {
                count++;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 5; i++) {
        int count = 0;

        for (int j = 0; j < 5; j++) {
            if (check_if_number_in_array(bingo_card[j * 5 + i], called_numbers, size)) {
                count++;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // Check diagonals
    int count_diagonal_1 = 0;
    int count_diagonal_2 = 0;

    for (int i = 0; i < 5; i++) {
        if (check_if_number_in_array(bingo_card[i * 5 + i], called_numbers, size)) {
            count_diagonal_1++;
        }

        if (check_if_number_in_array(bingo_card[i * 5 + 4 - i], called_numbers, size)) {
            count_diagonal_2++;
        }
    }

    if (count_diagonal_1 == 5 || count_diagonal_2 == 5) {
        return 1;
    }

    return 0;
}

// Play a game of bingo
void play_bingo() {
    // Generate a unique bingo card
    int *bingo_card = generate_unique_bingo_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_bingo_card(bingo_card);

    // Generate called numbers
    int called_numbers[90];
    int size = 0;

    while (size < 90) {
        int number = generate_random_number();

        if (!check_if_number_in_array(number, called_numbers, size)) {
            called_numbers[size] = number;
            size++;
        }
    }

    // Check if the bingo card has won
    int has_won = check_if_bingo_card_has_won(bingo_card, called_numbers, size);

    if (has_won) {
        printf("You won!\n");
    } else {
        printf("You lost!\n");
    }

    // Free the allocated memory
    free(bingo_card);
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Play a game of bingo
    play_bingo();

    return 0;
}