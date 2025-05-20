//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 30

typedef struct Cell {
    int x, y;
    struct Cell* parent;
    struct Cell** children;
    int num_children;
    int visited;
} Cell;

void create_maze(Cell** maze) {
    srand(time(NULL));
    // Choose a random start cell
    int start_row = rand() % ROW;
    int start_col = rand() % COL;
    Cell* current_cell = &maze[start_row][start_col];
    current_cell->visited = 1;
    // Create a stack to hold cells that we've visited
    Cell** visited_cells = malloc(ROW * COL * sizeof(Cell*));
    int visited_count = 0;
    // Loop until we've visited every cell
    while (visited_count != ROW * COL) {
        // Choose a random unvisited neighbor
        int neighbor_index = rand() % current_cell->num_children;
        Cell* neighbor = current_cell->children[neighbor_index];
        if (neighbor->visited == 0) {
            // Knock down the wall between the current cell and the neighbor
            if (neighbor->x < current_cell->x) {
                current_cell->parent = neighbor;
            } else if (neighbor->x > current_cell->x) {
                neighbor->parent = current_cell;
            } else if (neighbor->y < current_cell->y) {
                current_cell->parent = neighbor;
            } else {
                neighbor->parent = current_cell;
            }
            // Mark the neighbor as visited and push both the neighbor and current cell onto the stack
            visited_cells[visited_count++] = neighbor;
            neighbor->visited = 1;
            visited_cells[visited_count++] = current_cell;
            current_cell = neighbor;
        } else {
            // Choose a different neighbor to visit
            current_cell->children[neighbor_index] = current_cell->children[--current_cell->num_children];
        }
        // If there are no more unvisited neighbors, backtrack to the previous cell
        if (current_cell->num_children == 0) {
            current_cell = current_cell->parent;
        }
    }
    free(visited_cells);
}

void print_maze(Cell** maze) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j].parent == NULL) {
                printf("o ");
            } else if (maze[i][j].x < maze[i][j].parent->x) {
                printf("| ");
            } else if (maze[i][j].x > maze[i][j].parent->x) {
                printf("| ");
            } else if (maze[i][j].y < maze[i][j].parent->y) {
                printf("- ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    Cell** maze = malloc(ROW * sizeof(Cell*));
    for (int i = 0; i < ROW; i++) {
        maze[i] = malloc(COL * sizeof(Cell));
        for (int j = 0; j < COL; j++) {
            Cell cell = { i, j, NULL, NULL, 0, 0 };
            maze[i][j] = cell;
        }
        // Link cells together horizontally
        for (int j = 0; j < COL - 1; j++) {
            Cell* cell = &maze[i][j];
            cell->children = malloc(2 * sizeof(Cell*));
            cell->num_children = 2;
            cell->children[0] = &maze[i][j + 1];
            cell->children[1] = NULL;
            Cell* next_cell = &maze[i][j + 1];
            next_cell->children = malloc(2 * sizeof(Cell*));
            next_cell->num_children = 2;
            next_cell->children[0] = cell;
            next_cell->children[1] = NULL;
        }
        // Link cells together vertically
        if (i != ROW - 1) {
            for (int j = 0; j < COL; j++) {
                Cell* cell = &maze[i][j];
                cell->children = realloc(cell->children, 3 * sizeof(Cell*));
                cell->num_children = 3;
                cell->children[1] = &maze[i + 1][j];
                if (j != 0) {
                    cell->children[0] = &maze[i][j - 1];
                } else {
                    cell->children[0] = NULL;
                }
                if (j != COL - 1) {
                    cell->children[2] = &maze[i][j + 1];
                } else {
                    cell->children[2] = NULL;
                }
            }
        }
    }
    create_maze(maze);
    print_maze(maze);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            free(maze[i][j].children);
        }
        free(maze[i]);
    }
    free(maze);
    return 0;
}