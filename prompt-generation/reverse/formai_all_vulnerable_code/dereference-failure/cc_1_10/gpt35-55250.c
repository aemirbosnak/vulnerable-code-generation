//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

// Function to create a new board
int** create_board() {
    int** board = (int**)malloc(BOARD_SIZE * sizeof(int*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
    }
    return board;
}

// Function to print the current board
void print_board(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if all the cards have been matched
int game_over(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create and initialize the board
    int** board = create_board();
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }

    // Populate the board with pairs of cards
    for (int card = 0; card < BOARD_SIZE * BOARD_SIZE / 2; card++) {
        int found = 0;
        while (!found) {
            int i = rand() % BOARD_SIZE;
            int j = rand() % BOARD_SIZE;
            if (board[i][j] == -1) {
                board[i][j] = card;
                found = 1;
            }
        }
        found = 0;
        while (!found) {
            int i = rand() % BOARD_SIZE;
            int j = rand() % BOARD_SIZE;
            if (board[i][j] == -1) {
                board[i][j] = card;
                found = 1;
            }
        }
    }

    int* card1;
    int* card2;
    int x1, y1, x2, y2;

    while (!game_over(board)) {
        // Print the board
        printf("\n");
        print_board(board);

        // Get the user's guess
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (board[x1][y1] == -1) {
            printf("Card already flipped. Try again.\n");
            continue;
        }
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &x2, &y2);
        if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (board[x2][y2] == -1) {
            printf("Card already flipped. Try again.\n");
            continue;
        }

        // Check if the cards match
        if (board[x1][y1] != board[x2][y2]) {
            printf("Cards do not match. Try again.\n");
            board[x1][y1] = -1;
            board[x2][y2] = -1;
        } else {
            printf("Cards match.\n");
            board[x1][y1] = -2;
            board[x2][y2] = -2;
        }
    }

    // Print the final board
    printf("\n");
    print_board(board);

    printf("Congratulations! You won!\n");

    // Free allocated memory
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}