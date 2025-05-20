//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
// Memory Game in the Spirit of Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define N 4  // Board size (NxN)
#define PAIRS (N*N)/2  // Number of pairs to match

// Enumerations
enum {
    X = 0,  // Hidden card
    O = 1  // Matched card
};

// Function Prototypes
int** init_board();
void print_board(int**, int);

// Main Function
int main() {
    // Generate random seed
    srand(time(NULL));

    // Initialize board
    int** board = init_board();

    // Game Loop
    while (1) {
        // Print board
        print_board(board, N);

        // Get player input
        int x1, y1, x2, y2;
        printf("Enter coordinates (row, col) for two cards to flip: ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Flip cards
        board[x1][y1] = X;
        board[x2][y2] = X;

        // Check for match
        if (board[x1][y1] == board[x2][y2]) {
            // Matched
            board[x1][y1] = O;
            board[x2][y2] = O;
            printf("Match found!\n");

            // Check for game end
            int matched_count = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == O) {
                        matched_count++;
                    }
                }
            }

            if (matched_count == PAIRS) {
                // All pairs matched
                print_board(board, N);
                printf("Congratulations, you won!\n");
                break;
            }
        } else {
            // No match
            board[x1][y1] = X;
            board[x2][y2] = X;
            printf("No match found.\n");
        }
    }

    return 0;
}

// Function to initialize the board with random pairs
int** init_board() {
    // Allocate memory for board
    int** board = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        board[i] = (int*)malloc(N * sizeof(int));
    }

    // Create a list of pairs
    int pairs[PAIRS];
    for (int i = 0; i < PAIRS; i++) {
        pairs[i] = i;
    }

    // Randomly shuffle the pairs list
    for (int i = 0; i < PAIRS; i++) {
        int j = rand() % PAIRS;
        int tmp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = tmp;
    }

    // Place pairs on the board
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = pairs[k++];
        }
    }

    return board;
}

// Function to print the board
void print_board(int** board, int size) {
    printf("   ");
    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
        for (int j = 0; j < size; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}