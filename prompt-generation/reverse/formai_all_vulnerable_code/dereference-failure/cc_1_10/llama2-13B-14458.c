//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRATITUDE_BOARD_ROWS 10
#define GRATITUDE_BOARD_COLS 10

typedef struct gratitude_board_t {
    char **board;
    int row_size;
    int col_size;
} gratitude_board_t;

gratitude_board_t *create_gratitude_board(void) {
    gratitude_board_t *board = malloc(sizeof(gratitude_board_t));
    board->board = calloc(GRATITUDE_BOARD_ROWS, GRATITUDE_BOARD_COLS * sizeof(char));
    board->row_size = GRATITUDE_BOARD_ROWS;
    board->col_size = GRATITUDE_BOARD_COLS;
    return board;
}

void print_gratitude_board(gratitude_board_t *board) {
    for (int i = 0; i < GRATITUDE_BOARD_ROWS; i++) {
        for (int j = 0; j < GRATITUDE_BOARD_COLS; j++) {
            printf("%c", board->board[i * GRATITUDE_BOARD_COLS + j]);
        }
        printf("\n");
    }
}

void add_gratitude_entry(gratitude_board_t *board, char *entry) {
    int row = random() % GRATITUDE_BOARD_ROWS;
    int col = random() % GRATITUDE_BOARD_COLS;
    board->board[row * GRATITUDE_BOARD_COLS + col] = *entry;
}

int main(void) {
    srand(time(NULL));

    gratitude_board_t *board = create_gratitude_board();

    while (1) {
        add_gratitude_entry(board, "I am grateful for this delicious cup of coffee.");
        add_gratitude_entry(board, "I am grateful for the sunshine and fresh air.");
        add_gratitude_entry(board, "I am grateful for my loving family and friends.");

        print_gratitude_board(board);

        char input;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &input);

        if (input == 'n') {
            break;
        }
    }

    free(board);

    return 0;
}