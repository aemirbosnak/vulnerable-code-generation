//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a cell in the table
typedef struct {
    char value; // Value of the cell
    char color; // Color of the cell (red or green)
} cell_t;

// Function to initialize the table with random values
void init_table(cell_t **table) {
    int i, j;
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            // Assign a random value to each cell
            table[i][j].value = '0' + (rand() % 2);
            // Set the color of the cell based on its value
            if (table[i][j].value == '0') {
                table[i][j].color = 'G';
            } else {
                table[i][j].color = 'R';
            }
        }
    }
}

// Function to print the table
void print_table(cell_t **table) {
    int i, j;
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            printf("%c%c", table[i][j].color, table[i][j].value);
        }
        printf("\n");
    }
}

// Function to get the winner of the game
char get_winner(cell_t **table) {
    int i, j;
    char winner = 'N'; // Initialize the winner as 'N'
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            // Check if any row or column has all 'R' or all 'G' values
            if (table[i][j].value == 'R' && table[i][j+1].value == 'R' && table[i][j+2].value == 'R') {
                winner = 'R'; // If a row has all 'R' values, set the winner to 'R'
                break;
            } else if (table[i][j].value == 'G' && table[i][j+1].value == 'G' && table[i][j+2].value == 'G') {
                winner = 'G'; // If a row has all 'G' values, set the winner to 'G'
                break;
            }
        }
        if (winner != 'N') {
            break; // If a winner is found, break out of the loop
        }
    }
    return winner; // Return the winner
}

int main() {
    cell_t **table; // Create a 2D array to represent the table
    int rows, cols;

    // Ask the user for the number of rows and columns in the table
    printf("Enter the number of rows and columns in the table (separate by a space): ");
    scanf("%d%d", &rows, &cols);

    // Create the table with the given number of rows and columns
    table = malloc(rows * sizeof(cell_t *));
    for (int i = 0; i < rows; i++) {
        table[i] = malloc(cols * sizeof(cell_t));
    }

    // Initialize the table with random values
    init_table(table);

    // Print the table
    print_table(table);

    // Get the winner of the game
    char winner = get_winner(table);

    // Print the winner
    printf("The winner is %c!\n", winner);

    // Free the memory used by the table
    for (int i = 0; i < rows; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}