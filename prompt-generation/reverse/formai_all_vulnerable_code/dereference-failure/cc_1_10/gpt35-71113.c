//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Maze structure
typedef struct Maze {
    int rows;
    int cols;
    int startX;
    int startY;
    int endX;
    int endY;
    char **grid;
} Maze;

// Node structure for the linked list
typedef struct Node {
    int x;
    int y;
    struct Node *next;
} Node;

// Function to initialize a maze
void initMaze(Maze *maze, char grid[][COLS+1], int rows, int cols, int startX, int startY, int endX, int endY) {
    maze->rows = rows;
    maze->cols = cols;
    maze->startX = startX;
    maze->startY = startY;
    maze->endX = endX;
    maze->endY = endY;
    maze->grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            maze->grid[i][j] = grid[i][j];
        }
    }
}

// Function to print a maze
void printMaze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%c ", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid
bool isValidCell(Maze *maze, int x, int y) {
    if (x < 0 || x >= maze->rows || y < 0 || y >= maze->cols || maze->grid[x][y] != ' ') {
        return false;
    }
    return true;
}

// Function to find a path in the maze using DFS
bool findPathDFS(Maze *maze, int x, int y, Node **path) {
    // Mark the current cell as visited
    maze->grid[x][y] = '#';

    // Create a new node and add it to the path linked list
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = *path;
    *path = node;

    // Check if we have reached the end point
    if (x == maze->endX && y == maze->endY) {
        return true;
    }

    // Check adjacent cells
    if (isValidCell(maze, x-1, y) && findPathDFS(maze, x-1, y, path)) {
        return true;
    }
    if (isValidCell(maze, x+1, y) && findPathDFS(maze, x+1, y, path)) {
        return true;
    }
    if (isValidCell(maze, x, y-1) && findPathDFS(maze, x, y-1, path)) {
        return true;
    }
    if (isValidCell(maze, x, y+1) && findPathDFS(maze, x, y+1, path)) {
        return true;
    }

    // If we reach here, then backtrack
    *path = (*path)->next;
    free(node);
    return false;
}

// Function to find a path in the maze using BFS
bool findPathBFS(Maze *maze, Node **path) {
    // Create a visited array to keep track of visited cells
    bool visited[maze->rows][maze->cols];
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            visited[i][j] = false;
        }
    }

    // Create a queue for BFS
    Node *queue = malloc(sizeof(Node));
    queue->x = maze->startX;
    queue->y = maze->startY;
    queue->next = NULL;

    // Enqueue the start cell
    visited[maze->startX][maze->startY] = true;

    // BFS loop
    while (queue != NULL) {
        // Dequeue a cell from the queue
        Node *node = queue;
        queue = queue->next;

        // Check if we have reached the end point
        if (node->x == maze->endX && node->y == maze->endY) {
            // Create a new node and add it to the path linked list
            node->next = *path;
            *path = node;
            return true;
        }

        // Check adjacent cells
        if (isValidCell(maze, node->x-1, node->y) && !visited[node->x-1][node->y]) {
            visited[node->x-1][node->y] = true;
            Node *newNode = malloc(sizeof(Node));
            newNode->x = node->x-1;
            newNode->y = node->y;
            newNode->next = queue;
            queue = newNode;
        }
        if (isValidCell(maze, node->x+1, node->y) && !visited[node->x+1][node->y]) {
            visited[node->x+1][node->y] = true;
            Node *newNode = malloc(sizeof(Node));
            newNode->x = node->x+1;
            newNode->y = node->y;
            newNode->next = queue;
            queue = newNode;
        }
        if (isValidCell(maze, node->x, node->y-1) && !visited[node->x][node->y-1]) {
            visited[node->x][node->y-1] = true;
            Node *newNode = malloc(sizeof(Node));
            newNode->x = node->x;
            newNode->y = node->y-1;
            newNode->next = queue;
            queue = newNode;
        }
        if (isValidCell(maze, node->x, node->y+1) && !visited[node->x][node->y+1]) {
            visited[node->x][node->y+1] = true;
            Node *newNode = malloc(sizeof(Node));
            newNode->x = node->x;
            newNode->y = node->y+1;
            newNode->next = queue;
            queue = newNode;
        }
    }

    // If we reach here, then there is no path
    return false;
}

int main() {
    char grid[ROWS][COLS+1] = {
        "##########",
        "#        #",
        "# ###### #",
        "# #    # #",
        "# # ## # #",
        "# # ## # #",
        "#      # #",
        "###### # #",
        "#      # #",
        "##########"
    };
    Maze maze;
    initMaze(&maze, grid, ROWS, COLS, 1, 1, 8, 8);
    printf("Maze:\n");
    printMaze(&maze);

    Node *path = NULL;
    if (findPathDFS(&maze, maze.startX, maze.startY, &path)) {
        printf("DFS Path:\n");
        while (path != NULL) {
            printf("(%d,%d)\n", path->x, path->y);
            path = path->next;
        }
        printf("\n");
    } else {
        printf("No path found using DFS\n\n");
    }

    path = NULL;
    if (findPathBFS(&maze, &path)) {
        printf("BFS Path:\n");
        while (path != NULL) {
            printf("(%d,%d)\n", path->x, path->y);
            path = path->next;
        }
        printf("\n");
    } else {
        printf("No path found using BFS\n\n");
    }

    return 0;
}