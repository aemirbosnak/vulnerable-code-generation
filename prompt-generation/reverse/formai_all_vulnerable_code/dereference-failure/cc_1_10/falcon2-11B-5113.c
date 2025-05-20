//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a Bingo card with random numbers
void generate_bingo_card(int card_size, int *card) {
    for (int i = 0; i < card_size; i++) {
        card[i] = rand() % 75 + 1;
    }
}

// Function to check if the user has won by completing a row, column, or diagonal pattern
void check_bingo(int *bingo_card, int bingo_card_size) {
    // Check for a row win
    int rows[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < bingo_card_size; i++) {
        int row = i / 5;
        if (bingo_card[i] == 75) {
            rows[row]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (rows[i] == 5) {
            printf("Bingo! You won the row!\n");
            return;
        }
    }
    // Check for a column win
    for (int i = 0; i < bingo_card_size; i++) {
        int column = i % 5;
        if (bingo_card[i] == 75) {
            printf("Bingo! You won the column!\n");
            return;
        }
    }
    // Check for a diagonal win
    int diagonals[2] = {0, 0};
    for (int i = 0; i < bingo_card_size; i++) {
        int diagonal = i % 2;
        if (bingo_card[i] == 75) {
            diagonals[diagonal]++;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (diagonals[i] == 5) {
            printf("Bingo! You won the diagonal!\n");
            return;
        }
    }
}

// Function to simulate the Bingo game
void bingo_game(int *bingo_card, int bingo_card_size) {
    int draw_number;
    for (int i = 0; i < 25; i++) {
        srand(time(NULL));
        draw_number = rand() % 75 + 1;
        printf("Bingo number: %d\n", draw_number);
        for (int j = 0; j < bingo_card_size; j++) {
            if (bingo_card[j] == draw_number) {
                printf("Marked: %d\n", draw_number);
                bingo_card[j] = 0;
                check_bingo(bingo_card, bingo_card_size);
                return;
            }
        }
    }
    printf("Bingo! You win!\n");
}

int main() {
    int card_size = 5;
    int *bingo_card = (int*)malloc(card_size * sizeof(int));
    generate_bingo_card(card_size, bingo_card);
    bingo_game(bingo_card, card_size);
    free(bingo_card);
    return 0;
}