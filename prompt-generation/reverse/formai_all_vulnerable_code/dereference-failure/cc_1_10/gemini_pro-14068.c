//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Represents a single card on the board
struct Card {
    int value;
    int is_flipped;
};

// Represents the game board
struct Board {
    struct Card cards[BOARD_SIZE][BOARD_SIZE];
};

// Initializes the game board with random values
void initialize_board(struct Board *board) {
    int values[] = {1, 1, 2, 2, 3, 3, 4, 4};
    int shuffled_values[sizeof(values) / sizeof(values[0])];
    int i, j, k;

    // Shuffle the values
    srand(time(NULL));
    for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        k = rand() % (i + 1);
        shuffled_values[i] = values[k];
        values[k] = values[i];
    }

    // Assign the shuffled values to the board
    k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = shuffled_values[k++];
            board->cards[i][j].is_flipped = 0;
        }
    }
}

// Prints the game board to the console
void print_board(const struct Board *board) {
    int i, j;

    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].is_flipped) {
                printf("%2d ", board->cards[i][j].value);
            } else {
                printf("░░ ");
            }
        }
        printf("\n");
    }
}

// Flips a card on the board
void flip_card(struct Board *board, int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("Invalid move. Please enter a valid row and column.\n");
    } else if (board->cards[row][col].is_flipped) {
        printf("That card is already flipped. Please try again.\n");
    } else {
        board->cards[row][col].is_flipped = 1;
    }
}

// Checks if the game is over
int is_game_over(const struct Board *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (!board->cards[i][j].is_flipped) {
                return 0;
            }
        }
    }
    return 1;
}

// Plays the game
void play_game(struct Board *board) {
    int row1, col1, row2, col2;

    initialize_board(board);
    while (!is_game_over(board)) {
        print_board(board);
        printf("Enter the row and column of the first card to flip (e.g. 1 2): ");
        scanf("%d %d", &row1, &col1);
        flip_card(board, row1 - 1, col1 - 1);
        printf("Enter the row and column of the second card to flip (e.g. 2 3): ");
        scanf("%d %d", &row2, &col2);
        flip_card(board, row2 - 1, col2 - 1);

        if (board->cards[row1 - 1][col1 - 1].value == board->cards[row2 - 1][col2 - 1].value) {
            printf("Match!\n");
        } else {
            printf("No match. Try again.\n");
            board->cards[row1 - 1][col1 - 1].is_flipped = 0;
            board->cards[row2 - 1][col2 - 1].is_flipped = 0;
        }
    }
    printf("Congratulations! You won!\n");
}

int main() {
    struct Board board;

    play_game(&board);

    return 0;
}