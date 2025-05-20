//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Declare the main function
int main() {
    // Declare the variables
    int rows, cols, num_pairs;
    char **board;
    int *guesses;
    int i, j, k, l;
    int matches = 0;
    int attempts = 0;
    int first_guess = 1;
    int first_row, first_col, second_row, second_col;

    // Get the input from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of pairs: ");
    scanf("%d", &num_pairs);

    // Allocate memory for the board
    board = (char **)malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        board[i] = (char *)malloc(cols * sizeof(char));
    }

    // Allocate memory for the guesses
    guesses = (int *)malloc(2 * sizeof(int));

    // Initialize the board
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = '.';
        }
    }

    // Place the pairs on the board
    for (i = 0; i < num_pairs; i++) {
        // Get the first random position
        first_row = rand() % rows;
        first_col = rand() % cols;

        // Get the second random position
        do {
            second_row = rand() % rows;
            second_col = rand() % cols;
        } while (first_row == second_row && first_col == second_col);

        // Place the pair on the board
        board[first_row][first_col] = 'A' + i;
        board[second_row][second_col] = 'A' + i;
    }

    // Print the board
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Get the guesses from the user
    while (matches < num_pairs) {
        // Get the first guess
        if (first_guess) {
            printf("Enter the first guess (row, column): ");
            scanf("%d %d", &first_row, &first_col);
            first_guess = 0;
        }

        // Get the second guess
        else {
            printf("Enter the second guess (row, column): ");
            scanf("%d %d", &second_row, &second_col);
            first_guess = 1;
        }

        // Check if the guesses are valid
        if (first_row < 0 || first_row >= rows || first_col < 0 || first_col >= cols || second_row < 0 || second_row >= rows || second_col < 0 || second_col >= cols) {
            printf("Invalid guess. Please enter a valid guess.\n");
            continue;
        }

        // Check if the guesses match
        if (board[first_row][first_col] == board[second_row][second_col]) {
            // Increment the number of matches
            matches++;

            // Print the board
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (i == first_row && j == first_col || i == second_row && j == second_col) {
                        printf("%c ", board[i][j]);
                    } else {
                        printf("%c ", board[i][j]);
                    }
                }
                printf("\n");
            }

            // Increment the number of attempts
            attempts++;
        }

        // Otherwise, print an error message
        else {
            printf("No match. Please try again.\n");

            // Increment the number of attempts
            attempts++;
        }
    }

    // Print the number of attempts
    printf("You matched all the pairs in %d attempts.\n", attempts);

    // Free the memory
    for (i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
    free(guesses);

    return 0;
}