//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    return cell;
}

void destroyCell(Cell* cell) {
    free(cell);
}

int main() {
    int rows = 10;
    int cols = 10;
    int startX = 0;
    int startY = 0;
    int endX = 0;
    int endY = 0;

    Cell* start = createCell(startX, startY);
    Cell* end = createCell(endX, endY);

    Cell* maze[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = createCell(i, j);
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    Cell* current = start;
    int steps = 0;
    while (current!= end) {
        Cell* neighbors[4];
        for (int i = 0; i < 4; i++) {
            neighbors[i] = createCell(current->x + dx[i], current->y + dy[i]);
        }

        for (int i = 0; i < 4; i++) {
            if (neighbors[i]!= end && maze[neighbors[i]->y][neighbors[i]->x]!= 1) {
                maze[neighbors[i]->y][neighbors[i]->x] = 1;
                current = neighbors[i];
                break;
            }
        }

        destroyCell(current);
        current = neighbors[0];
        steps++;
    }

    printf("Generated maze after %d steps:\n", steps);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == start) {
                printf("S");
            } else if (maze[i][j] == end) {
                printf("E");
            } else if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    destroyCell(start);
    destroyCell(end);

    return 0;
}