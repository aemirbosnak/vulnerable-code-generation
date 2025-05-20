//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point p1;
    point p2;
} pair;

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_pair(pair pair) {
    return pair.p1.x == pair.p2.x && pair.p1.y == pair.p2.y;
}

bool is_pair_found(pair pair, char board[BOARD_SIZE][BOARD_SIZE]) {
    return board[pair.p1.x][pair.p1.y] == board[pair.p2.x][pair.p2.y];
}

void flip_cards(pair pair, char board[BOARD_SIZE][BOARD_SIZE]) {
    board[pair.p1.x][pair.p1.y] = '0';
    board[pair.p2.x][pair.p2.y] = '0';
}

bool is_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != '0') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize the game board
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '*';
        }
    }

    // Create the pairs of cards
    pair pairs[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        pairs[i].p1.x = rand() % BOARD_SIZE;
        pairs[i].p1.y = rand() % BOARD_SIZE;
        pairs[i].p2.x = rand() % BOARD_SIZE;
        pairs[i].p2.y = rand() % BOARD_SIZE;
    }

    // Shuffle the pairs of cards
    for (int i = 0; i < NUM_PAIRS; i++) {
        int j = rand() % NUM_PAIRS;
        pair temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

    // Main game loop
    while (!is_game_over(board)) {
        // Print the game board
        print_board(board);

        // Get the player's input
        pair input;
        printf("Enter the coordinates of two cards to flip (e.g. 1 2 3 4): ");
        scanf("%d %d %d %d", &input.p1.x, &input.p1.y, &input.p2.x, &input.p2.y);

        // Flip the cards
        flip_cards(input, board);

        // Check if the cards are a match
        if (is_pair_found(input, board)) {
            printf("You found a match!\n");
        } else {
            printf("Not a match. Try again.\n");
        }
    }

    // Game over
    printf("Congratulations! You won the game!\n");

    return 0;
}