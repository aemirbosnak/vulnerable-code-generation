//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define CELL_COUNT (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} Point;

void print_board(bool **board) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(board[y][x] ? "#" : ".");
        }
        printf("\n");
    }
}

int count_neighbors(bool **board, int x, int y) {
    int count = 0;
    for (int ny = y - 1; ny <= y + 1; ny++) {
        for (int nx = x - 1; nx <= x + 1; nx++) {
            if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT)
                continue;
            if (nx == x && ny == y)
                continue;
            count += board[ny][nx];
        }
    }
    return count;
}

void next_generation(bool **board) {
    bool new_board[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(board, x, y);
            new_board[y][x] = (neighbors == 3 || (neighbors == 2 && board[y][x]));
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = new_board[y][x];
        }
    }
}

int main() {
    bool **board = malloc(sizeof(bool *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        board[i] = calloc(WIDTH, sizeof(bool));
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = (x < 5 || x > WIDTH - 5 || y < 5 || y > HEIGHT - 5) ? true : false;
        }
    }

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int x, y;
        do {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        } while (board[y][x]);
        board[y][x] = true;
    }

    print_board(board);

    for (int i = 0; i < 10; i++) {
        next_generation(board);
        print_board(board);
        sleep(1);
    }

    for (int y = 0; y < HEIGHT; y++) {
        free(board[y]);
    }
    free(board);

    return 0;
}