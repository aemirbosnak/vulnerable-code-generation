//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MIN_VAL 1
#define MAX_VAL 10

typedef struct {
    int row;
    int col;
} position_t;

position_t generate_random_position(void) {
    int row = rand() % ROWS;
    int col = rand() % COLS;
    return (position_t) {row, col};
}

void print_table(position_t** table) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    position_t** table = calloc(ROWS, sizeof(position_t*));
    for (int i = 0; i < ROWS; i++) {
        table[i] = calloc(COLS, sizeof(position_t));
    }

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = generate_random_position();
        }
    }

    print_table(table);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (table[i][j].row == i && table[i][j].col == j) {
                printf("You win! Congratulations! \n");
                break;
            }
        }
    }

    return 0;
}