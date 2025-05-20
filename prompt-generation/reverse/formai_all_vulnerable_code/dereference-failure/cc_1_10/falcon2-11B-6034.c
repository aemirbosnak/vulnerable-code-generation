//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define WALL '#'
#define PATH '.'
#define START 'S'
#define END 'E'

typedef struct node {
    int x;
    int y;
    char direction;
} Node;

typedef struct maze {
    int rows;
    int cols;
    Node** grid;
} Maze;

void init_maze(Maze* maze, int rows, int cols) {
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = (Node**)malloc(rows * sizeof(Node*));
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = (Node*)malloc(cols * sizeof(Node));
        for (int j = 0; j < cols; j++) {
            maze->grid[i][j].x = j;
            maze->grid[i][j].y = i;
            maze->grid[i][j].direction = WALL;
        }
    }
}

void print_maze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->grid[i][j].direction == START) {
                printf("%c ", START);
            } else if (maze->grid[i][j].direction == END) {
                printf("%c ", END);
            } else if (maze->grid[i][j].direction == WALL) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void find_path(Maze* maze) {
    Node* current = &maze->grid[0][0];
    current->direction = START;
    Node* visited[100];
    for (int i = 0; i < 100; i++) {
        visited[i] = NULL;
    }
    visited[current->x * maze->cols + current->y] = current;
    int x = current->x;
    int y = current->y;
    while (current->direction!= END) {
        Node* neighbor = &maze->grid[x][y];
        if (neighbor->direction!= WALL &&!visited[neighbor->x * maze->cols + neighbor->y]) {
            visited[neighbor->x * maze->cols + neighbor->y] = neighbor;
            if (neighbor->direction == PATH) {
                current = neighbor;
                x = current->x;
                y = current->y;
            }
        }
        neighbor = &maze->grid[x - 1][y];
        if (neighbor->direction!= WALL &&!visited[neighbor->x * maze->cols + neighbor->y]) {
            visited[neighbor->x * maze->cols + neighbor->y] = neighbor;
            if (neighbor->direction == PATH) {
                current = neighbor;
                x = current->x;
                y = current->y;
            }
        }
        neighbor = &maze->grid[x + 1][y];
        if (neighbor->direction!= WALL &&!visited[neighbor->x * maze->cols + neighbor->y]) {
            visited[neighbor->x * maze->cols + neighbor->y] = neighbor;
            if (neighbor->direction == PATH) {
                current = neighbor;
                x = current->x;
                y = current->y;
            }
        }
        neighbor = &maze->grid[x][y - 1];
        if (neighbor->direction!= WALL &&!visited[neighbor->x * maze->cols + neighbor->y]) {
            visited[neighbor->x * maze->cols + neighbor->y] = neighbor;
            if (neighbor->direction == PATH) {
                current = neighbor;
                x = current->x;
                y = current->y;
            }
        }
        neighbor = &maze->grid[x][y + 1];
        if (neighbor->direction!= WALL &&!visited[neighbor->x * maze->cols + neighbor->y]) {
            visited[neighbor->x * maze->cols + neighbor->y] = neighbor;
            if (neighbor->direction == PATH) {
                current = neighbor;
                x = current->x;
                y = current->y;
            }
        }
    }
    printf("Path found!\n");
    Node* last = current;
    while (last!= &maze->grid[0][0]) {
        Node* neighbor = &maze->grid[last->x][last->y];
        if (neighbor->direction == START) {
            printf("%c ", START);
        } else if (neighbor->direction == END) {
            printf("%c ", END);
        } else if (neighbor->direction == WALL) {
            printf("# ");
        } else {
            printf(". ");
        }
        last = neighbor;
    }
}

int main() {
    Maze maze;
    init_maze(&maze, 10, 10);
    print_maze(&maze);
    find_path(&maze);
    return 0;
}