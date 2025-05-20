//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define LIVES 2
#define DEAD 0

typedef struct {
    int x, y;
} point;

point new_life(point p) {
    point n;
    n.x = p.x;
    n.y = p.y;
    return n;
}

void print_board(int **board) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf(board[i][j] & LIVES ? "██" : "  ");
        }
        printf("\n");
    }
}

int count_neighbors(int **board, int x, int y) {
    int count = 0;
    int i, j;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i < 0 || j < 0 || i >= HEIGHT || j >= WIDTH) continue;
            if (i == x && j == y) continue;
            count += board[i][j] & LIVES;
        }
    }

    return count;
}

void next_generation(int **board) {
    int i, j;
    point **new_board = calloc(sizeof(point*), HEIGHT);

    for (i = 0; i < HEIGHT; i++) {
        new_board[i] = calloc(sizeof(point), WIDTH);

        for (j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(board, j, i);
            new_board[i][j].x = j;
            new_board[i][j].y = i;

            if (board[i][j] & LIVES && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j].x = -1;
            } else if (!(board[i][j] & LIVES) && neighbors == 3) {
                new_board[i][j].x = j;
                new_board[i][j].y = i;
            }
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (new_board[i][j].x != -1) {
                board[i][j] = new_life(new_board[i][j]).x | (new_board[i][j].y << 3);
            }
        }
        free(new_board[i]);
    }

    free(new_board);
}

int main() {
    int **board = calloc(sizeof(int*), HEIGHT);
    int i, j;

    srand(time(NULL));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < 5; i++) {
        print_board(board);
        next_generation(board);
        printf("\n");
    }

    free(board);

    return 0;
}