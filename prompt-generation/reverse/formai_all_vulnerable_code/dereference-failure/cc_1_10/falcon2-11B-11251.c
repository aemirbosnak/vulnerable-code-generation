//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int size;
    Point* points;
} BingoBoard;

int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generate_bingo_board(BingoBoard* board, int size) {
    board->size = size;
    board->points = (Point*)malloc(sizeof(Point) * size * size);
    for (int i = 0; i < size * size; i++) {
        board->points[i].x = rand_int(0, size - 1);
        board->points[i].y = rand_int(0, size - 1);
    }
}

void print_bingo_board(BingoBoard* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->points[i * board->size + j].x == j && board->points[i * board->size + j].y == i) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int size = 5;
    BingoBoard board;
    generate_bingo_board(&board, size);

    printf("Bingo Board:\n");
    print_bingo_board(&board);

    return 0;
}