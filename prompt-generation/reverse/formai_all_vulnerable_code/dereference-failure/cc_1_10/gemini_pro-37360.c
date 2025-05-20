//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// The maze structure
typedef struct {
    int width;
    int height;
    int **cells;
} Maze;

// The path structure
typedef struct {
    int x;
    int y;
    struct Node *next;
} Path;

// The stack structure
typedef struct {
    struct Node *top;
} Stack;

// Create a new maze
Maze *create_maze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

// Free the maze
void free_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Print the maze
void print_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->cells[i][j]);
        }
        printf("\n");
    }
}

// Check if the cell is valid
int is_valid_cell(Maze *maze, int x, int y) {
    return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->cells[y][x] == 0;
}

// Add a cell to the path
void add_cell_to_path(Path **path, int x, int y) {
    Path *new_cell = malloc(sizeof(Path));
    new_cell->x = x;
    new_cell->y = y;
    new_cell->next = *path;
    *path = new_cell;
}

// Remove a cell from the path
void remove_cell_from_path(Path **path) {
    if (*path != NULL) {
        Path *next = (*path)->next;
        free(*path);
        *path = next;
    }
}

// Find the path through the maze
Path *find_path(Maze *maze, int start_x, int start_y, int end_x, int end_y) {
    Stack stack;
    stack.top = NULL;
    Path *path = NULL;
    add_cell_to_path(&path, start_x, start_y);
    while (path != NULL) {
        int x = path->x;
        int y = path->y;
        if (x == end_x && y == end_y) {
            return path;
        }
        maze->cells[y][x] = 1;
        if (is_valid_cell(maze, x + 1, y)) {
            add_cell_to_path(&path, x + 1, y);
        } else if (is_valid_cell(maze, x, y + 1)) {
            add_cell_to_path(&path, x, y + 1);
        } else if (is_valid_cell(maze, x - 1, y)) {
            add_cell_to_path(&path, x - 1, y);
        } else if (is_valid_cell(maze, x, y - 1)) {
            add_cell_to_path(&path, x, y - 1);
        } else {
            remove_cell_from_path(&path);
        }
    }
    return NULL;
}

// Free the path
void free_path(Path *path) {
    while (path != NULL) {
        Path *next = path->next;
        free(path);
        path = next;
    }
}

// Main function
int main() {
    // Create a maze
    Maze *maze = create_maze(10, 10);

    // Set the start and end cells
    int start_x = 0;
    int start_y = 0;
    int end_x = 9;
    int end_y = 9;

    // Find the path through the maze
    Path *path = find_path(maze, start_x, start_y, end_x, end_y);

    // Print the path
    if (path != NULL) {
        printf("Path found!\n");
        Path *current = path;
        while (current != NULL) {
            printf("(%d, %d)\n", current->x, current->y);
            current = current->next;
        }
    } else {
        printf("No path found.\n");
    }

    // Free the maze and path
    free_maze(maze);
    free_path(path);

    return 0;
}