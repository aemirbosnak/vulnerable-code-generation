//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define WIDTH 40
#define HEIGHT 22
#define CELL_SIZE 2
#define BOARD_SIZE (WIDTH * HEIGHT)
#define FILE_NAME "game_of_life.txt"
typedef struct {
    int x;
    int y;
} cell;
cell board[WIDTH][HEIGHT];
bool alive[WIDTH][HEIGHT];
void print_board() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (alive[j][i])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}
void init_board() {
    int i, j;
    FILE *fp;
    char line[CELL_SIZE + 1];
    fp = fopen(FILE_NAME, "r");
    for (i = 0; i < HEIGHT; i++) {
        fgets(line, CELL_SIZE + 1, fp);
        for (j = 0; j < WIDTH; j++) {
            if (line[j] == '#') {
                alive[j][i] = true;
                board[j][i].x = j;
                board[j][i].y = i;
            }
        }
    }
    fclose(fp);
}
bool count_neighbors(int x, int y) {
    int i, j, count = 0;
    for (i = y - 1; i <= y + 1; i++) {
        for (j = x - 1; j <= x + 1; j++) {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH && !(i == y && j == x)) {
                if (alive[j][i])
                    count++;
            }
        }
    }
    return count;
}
void next_generation() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (alive[j][i]) {
                if (count_neighbors(j, i) < 2 || count_neighbors(j, i) > 3) {
                    alive[j][i] = false;
                }
            } else {
                if (count_neighbors(j, i) == 3) {
                    alive[j][i] = true;
                }
            }
        }
    }
}
int main() {
    init_board();
    int generation = 0;
    do {
        next_generation();
        print_board();
        printf("Generation %d\n", generation++);
    } while (true);
    return 0;
}