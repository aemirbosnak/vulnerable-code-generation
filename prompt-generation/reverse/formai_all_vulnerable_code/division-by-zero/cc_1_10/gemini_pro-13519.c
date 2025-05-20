//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 4
#define PAIRS_COUNT (BOARD_SIZE * BOARD_SIZE) / 2
#define BOARD_CELLS_COUNT PAIRS_COUNT * 2

typedef struct {
    int value;
    bool is_open;
    bool is_matched;
} board_cell;

typedef struct {
    board_cell cells[BOARD_CELLS_COUNT];
    int open_cells_count;
    int matched_pairs_count;
} game_board;

void init_board(game_board *board) {
    board->open_cells_count = 0;
    board->matched_pairs_count = 0;

    int values[PAIRS_COUNT];
    for (int i = 0; i < PAIRS_COUNT; i++) {
        values[i] = i;
    }

    srand(time(NULL));

    for (int i = 0; i < BOARD_CELLS_COUNT; i++) {
        int random_index = rand() % (PAIRS_COUNT - i);
        board->cells[i].value = values[random_index];
        values[random_index] = values[PAIRS_COUNT - i - 1];
        board->cells[i].is_open = false;
        board->cells[i].is_matched = false;
    }
}

void print_board(game_board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = i * BOARD_SIZE + j;
            if (board->cells[index].is_open) {
                printf("%2d ", board->cells[index].value);
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
}

bool is_game_over(game_board *board) {
    return board->matched_pairs_count == PAIRS_COUNT;
}

int main() {
    game_board board;
    init_board(&board);

    while (!is_game_over(&board)) {
        print_board(&board);

        int row, col;
        printf("Enter the row and column of the first card (row col): ");
        scanf("%d %d", &row, &col);

        int first_card_index = (row - 1) * BOARD_SIZE + (col - 1);
        board.cells[first_card_index].is_open = true;
        board.open_cells_count++;

        printf("Enter the row and column of the second card (row col): ");
        scanf("%d %d", &row, &col);

        int second_card_index = (row - 1) * BOARD_SIZE + (col - 1);
        board.cells[second_card_index].is_open = true;
        board.open_cells_count++;

        if (board.cells[first_card_index].value == board.cells[second_card_index].value) {
            board.cells[first_card_index].is_matched = true;
            board.cells[second_card_index].is_matched = true;
            board.matched_pairs_count++;
        } else {
            board.cells[first_card_index].is_open = false;
            board.cells[second_card_index].is_open = false;
            board.open_cells_count -= 2;
        }
    }

    print_board(&board);
    printf("Congratulations! You won the game!\n");

    return 0;
}