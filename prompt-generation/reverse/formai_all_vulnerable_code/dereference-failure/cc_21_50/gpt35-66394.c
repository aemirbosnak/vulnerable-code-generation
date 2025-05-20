//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main(){
    int row, col, choice;
    int num_matches = (ROWS * COLS) / 2;
    int matches_found = 0;
    int **game_board_pointer;
    int **revealed_card_pointer;
    int *random_list;
    int random_index;
    int input_row1, input_col1, input_row2, input_col2;
    int card1_value, card2_value;

    // Allocate memory for game board and revealed cards
    game_board_pointer = (int**) malloc(ROWS * sizeof(int*));
    revealed_card_pointer = (int**) malloc(ROWS * sizeof(int*));
    for (row = 0; row < ROWS; row++) {
        game_board_pointer[row] = (int*) malloc(COLS * sizeof(int));
        revealed_card_pointer[row] = (int*) malloc(COLS * sizeof(int));
    }

    // Allocate memory for random list
    random_list = (int*) malloc(num_matches * 2 * sizeof(int));
    for (row = 0; row < num_matches * 2; row++) {
        random_list[row] = row % num_matches;
    }

    // Shuffle random list
    srand(time(NULL));
    for (row = num_matches * 2 - 1; row > 0; row--) {
        random_index = rand() % (row + 1);
        int temp = random_list[row];
        random_list[row] = random_list[random_index];
        random_list[random_index] = temp;
    }

    // Assign pairs of values from shuffled list to game board
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            game_board_pointer[row][col] = random_list[row * COLS + col];
            revealed_card_pointer[row][col] = 0;
        }
    }

    // Game loop
    while (matches_found < num_matches) {
        // Print current game board
        printf("\nCurrent game board:\n\n");
        printf("  ");
        for (col = 0; col < COLS; col++) {
            printf(" %d ", col);
        }
        printf("\n");
        for (row = 0; row < ROWS; row++) {
            printf("%d ", row);
            for (col = 0; col < COLS; col++) {
                if (revealed_card_pointer[row][col] == 1) {
                    printf("[%d]", game_board_pointer[row][col]);
                } else {
                    printf("[ ]");
                }
            }
            printf("\n");
        }

        // Get input for card 1
        printf("\nEnter row and column of first card (separated by a space): ");
        scanf("%d %d", &input_row1, &input_col1);
        while (input_row1 < 0 || input_row1 >= ROWS || input_col1 < 0 || input_col1 >= COLS || revealed_card_pointer[input_row1][input_col1]) {
            printf("Invalid input or card already revealed. Enter row and column of first card (separated by a space): ");
            scanf("%d %d", &input_row1, &input_col1);
        }
        card1_value = game_board_pointer[input_row1][input_col1];
        printf("Card 1: [%d]\n", card1_value);

        // Get input for card 2
        printf("Enter row and column of second card (separated by a space): ");
        scanf("%d %d", &input_row2, &input_col2);
        while (input_row2 < 0 || input_row2 >= ROWS || input_col2 < 0 || input_col2 >= COLS || (input_row1 == input_row2 && input_col1 == input_col2) || revealed_card_pointer[input_row2][input_col2]) {
            printf("Invalid input or card already revealed. Enter row and column of second card (separated by a space): ");
            scanf("%d %d", &input_row2, &input_col2);
        }
        card2_value = game_board_pointer[input_row2][input_col2];
        printf("Card 2: [%d]\n", card2_value);

        // Check if cards match
        if (card1_value == card2_value) {
            printf("\nMatch found! Cards will remain revealed.\n");
            revealed_card_pointer[input_row1][input_col1] = 1;
            revealed_card_pointer[input_row2][input_col2] = 1;
            matches_found++;
        } else {
            printf("\nCards do not match. Cards will be covered again.\n");
            revealed_card_pointer[input_row1][input_col1] = 0;
            revealed_card_pointer[input_row2][input_col2] = 0;
        }
    }

    printf("\nCongratulations, you have found all matches!\n");

    // Free memory
    for (row = 0; row < ROWS; row++) {
        free(game_board_pointer[row]);
        free(revealed_card_pointer[row]);
    }
    free(game_board_pointer);
    free(revealed_card_pointer);
    free(random_list);

    return 0;
}