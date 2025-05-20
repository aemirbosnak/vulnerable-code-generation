//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Card states
#define CARD_HIDDEN 0
#define CARD_REVEALED 1
#define CARD_MATCHED 2

// Card data structure
typedef struct card {
    int value;
    int state;
} card;

// Game board data structure
typedef struct board {
    card cards[BOARD_SIZE][BOARD_SIZE];
} board;

// Function to create a new game board
board* create_board() {
    board* b = malloc(sizeof(board));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            b->cards[i][j].value = -1;
            b->cards[i][j].state = CARD_HIDDEN;
        }
    }
    return b;
}

// Function to destroy a game board
void destroy_board(board* b) {
    free(b);
}

// Function to shuffle the cards on the game board
void shuffle_cards(board* b) {
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i;
        values[i + NUM_PAIRS] = i;
    }

    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int r = rand() % (NUM_PAIRS * 2);
        int tmp = values[i];
        values[i] = values[r];
        values[r] = tmp;
    }

    int k = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            b->cards[i][j].value = values[k++];
        }
    }
}

// Function to print the game board
void print_board(board* b) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (b->cards[i][j].state == CARD_HIDDEN) {
                printf("  ");
            } else if (b->cards[i][j].state == CARD_REVEALED) {
                printf("%d ", b->cards[i][j].value);
            } else if (b->cards[i][j].state == CARD_MATCHED) {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to get the user's input and reveal the corresponding card
void get_input(board* b) {
    int row, col;
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
        printf("Invalid input\n");
    } else if (b->cards[row - 1][col - 1].state == CARD_REVEALED) {
        printf("Card already revealed\n");
    } else {
        b->cards[row - 1][col - 1].state = CARD_REVEALED;
    }
}

// Function to check if the game is over
int is_game_over(board* b) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (b->cards[i][j].state != CARD_MATCHED) {
                return 0;
            }
        }
    }
    return 1;
}

// Main game loop
int main() {
    srand(time(NULL));

    board* b = create_board();
    shuffle_cards(b);

    while (!is_game_over(b)) {
        print_board(b);
        get_input(b);
    }

    printf("Congratulations! You won the game.\n");

    destroy_board(b);
    return 0;
}