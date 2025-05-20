//MISTRAL-7B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_BOARD_SIZE 5
#define BALLS_COUNT 75

typedef struct {
    int number;
    int is_called;
} BingoNumber;

void generate_random_number(int* out) {
    int random_seed = time(NULL);
    srand(random_seed);
    *out = rand() % BALLS_COUNT + 1;
}

BingoNumber* create_bingo_board() {
    int i;
    BingoNumber* board = (BingoNumber*)calloc(BINGO_BOARD_SIZE * BINGO_BOARD_SIZE, sizeof(BingoNumber));

    for (i = 0; i < BINGO_BOARD_SIZE * BINGO_BOARD_SIZE; i++) {
        board[i].number = i + 1;
        board[i].is_called = 0;
    }

    return board;
}

void print_bingo_board(BingoNumber* board) {
    int i, j;

    for (i = 0; i < BINGO_BOARD_SIZE; i++) {
        for (j = 0; j < BINGO_BOARD_SIZE; j++) {
            printf("%2d ", board[i * BINGO_BOARD_SIZE + j].number);
        }
        printf("\n");
    }
}

void mark_number_as_called(BingoNumber* board, int number) {
    int index = number - 1;
    board[index].is_called = 1;
}

int check_bingo(BingoNumber* board) {
    int i, j, bingo = 0;

    for (i = 0; i < BINGO_BOARD_SIZE && !bingo; i++) {
        for (j = 0; j < BINGO_BOARD_SIZE && !bingo; j++) {
            if (!board[i * BINGO_BOARD_SIZE + j].is_called) {
                bingo = 0;
                break;
            }
            if (board[i * BINGO_BOARD_SIZE + j].is_called) {
                bingo++;
            }
        }

        if (bingo == BINGO_BOARD_SIZE) {
            break;
        }

        if (bingo) {
            continue;
        }

        for (j = 0; j < BINGO_BOARD_SIZE && !bingo; j++) {
            if (!board[j * BINGO_BOARD_SIZE + i].is_called) {
                bingo = 0;
                break;
            }
            if (board[j * BINGO_BOARD_SIZE + i].is_called) {
                bingo++;
            }
        }

        if (bingo == BINGO_BOARD_SIZE) {
            break;
        }
    }

    if (bingo == BINGO_BOARD_SIZE) {
        printf("BINGO! YOU WON!\n");
    }
}

int main() {
    int called_number;
    BingoNumber* board;

    srand(time(NULL));

    printf("Welcome to the Bingo Simulator!\n");
    board = create_bingo_board();
    print_bingo_board(board);

    printf("Starting the game...\n");
    for (int i = 0; i < BALLS_COUNT; i++) {
        generate_random_number(&called_number);

        printf("Ball number %d drawn.\n", called_number);
        mark_number_as_called(board, called_number);

        if (i % 5 == 0 && i > 0) {
            printf("\n");
        }

        if (check_bingo(board)) {
            break;
        }
    }

    free(board);

    return 0;
}