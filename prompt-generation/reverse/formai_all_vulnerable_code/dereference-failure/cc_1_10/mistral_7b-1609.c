//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int value;
    int revealed;
} cell_t;

void print_board(cell_t **board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed)
                printf("%d ", board[i][j].value);
            else
                printf("_ ");
        }
        printf("\n");
    }
}

void shuffle_pairs(int pairs[], int shuffle_seed) {
    int i, j, temp;
    srand(shuffle_seed);
    for (i = 0; i < NUM_PAIRS / 2; i++) {
        j = rand() % (NUM_PAIRS / 2);
        temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }
}

void reveal_cell(cell_t **board, int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && !board[x][y].revealed) {
        board[x][y].revealed = 1;
        if (board[x][y].value == board[x + 1][y].value || board[x][y].value == board[x][y + 1].value ||
            board[x][y].value == board[x - 1][y].value || board[x][y].value == board[x][y - 1].value) {
            board[x + 1][y].revealed = 1;
            board[x][y + 1].revealed = 1;
            board[x - 1][y].revealed = 1;
            board[x][y - 1].revealed = 1;
        }
    }
}

int main() {
    cell_t **board;
    int i, j, pairs[NUM_PAIRS], shuffle_seed;

    board = malloc(BOARD_SIZE * sizeof(cell_t *));
    for (i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(BOARD_SIZE * sizeof(cell_t));
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10 + 1;
            board[i][j].revealed = 0;
        }
    }

    shuffle_seed = time(NULL);
    shuffle_pairs(pairs, shuffle_seed);

    for (i = 0; i < NUM_PAIRS; i += 2) {
        board[pairs[i] / BOARD_SIZE][pairs[i] % BOARD_SIZE].value = board[pairs[i + 1] / BOARD_SIZE][pairs[i + 1] % BOARD_SIZE].value;
    }

    print_board(board);

    while (1) {
        int x, y;
        scanf("%d %d", &x, &y);
        reveal_cell(board, x, y);
        print_board(board);

        int revealed_cells = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].revealed)
                    revealed_cells++;
            }
        }

        if (revealed_cells == BOARD_SIZE * BOARD_SIZE) {
            printf("You won!\n");
            break;
        }
    }

    for (i = 0; i < BOARD_SIZE; i++)
        free(board[i]);
    free(board);

    return 0;
}