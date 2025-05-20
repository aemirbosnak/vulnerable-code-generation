//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void init_game(Cell **cells, int size);
void play_game(Cell **cells, int size);

int main() {
    Cell **cells;
    int size = MAX_SIZE;

    cells = (Cell *)malloc(size * sizeof(Cell));
    init_game(cells, size);
    play_game(cells, size);

    return 0;
}

void init_game(Cell **cells, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].state = 0;
        }
    }
}

void play_game(Cell **cells, int size) {
    int x, y, direction, move_count = 0;

    while (move_count < 10) {
        printf("Enter direction (N/S/E/W): ");
        scanf("%c", &direction);

        switch (direction) {
            case 'N':
                y = cells[0][0].y - 1;
                break;
            case 'S':
                y = cells[0][0].y + 1;
                break;
            case 'E':
                x = cells[0][0].x + 1;
                break;
            case 'W':
                x = cells[0][0].x - 1;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        if (cells[x][y].state == 0) {
            cells[x][y].state = 1;
            move_count++;
            printf("Move %d: (%d, %d)\n", move_count, x, y);
        } else {
            printf("Cell already visited.\n");
        }
    }

    printf("Game over!\n");
}