//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the maze
typedef struct cell {
    int x;
    int y;
    int visited;
} cell;

// Structure to represent the maze
typedef struct maze {
    int width;
    int height;
    cell **cells;
} maze;

// Function to create a new maze
maze *create_maze(int width, int height) {
    maze *m = (maze *)malloc(sizeof(maze));
    m->width = width;
    m->height = height;
    m->cells = (cell **)malloc(sizeof(cell *) * height);
    for (int i = 0; i < height; i++) {
        m->cells[i] = (cell *)malloc(sizeof(cell) * width);
        for (int j = 0; j < width; j++) {
            m->cells[i][j].x = i;
            m->cells[i][j].y = j;
            m->cells[i][j].visited = 0;
        }
    }
    return m;
}

// Function to free the memory allocated for the maze
void free_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cells[i]);
    }
    free(m->cells);
    free(m);
}

// Function to print the maze
void print_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            if (m->cells[i][j].visited) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to find a path through the maze
int find_path(maze *m, int x, int y) {
    if (x < 0 || x >= m->width || y < 0 || y >= m->height) {
        return 0;
    }
    if (m->cells[x][y].visited) {
        return 0;
    }
    m->cells[x][y].visited = 1;
    if (x == m->width - 1 && y == m->height - 1) {
        return 1;
    }
    if (find_path(m, x + 1, y)) {
        return 1;
    }
    if (find_path(m, x - 1, y)) {
        return 1;
    }
    if (find_path(m, x, y + 1)) {
        return 1;
    }
    if (find_path(m, x, y - 1)) {
        return 1;
    }
    m->cells[x][y].visited = 0;
    return 0;
}

// Main function
int main() {
    maze *m = create_maze(10, 10);
    if (find_path(m, 0, 0)) {
        printf("Path found!\n");
        print_maze(m);
    } else {
        printf("No path found.\n");
    }
    free_maze(m);
    return 0;
}