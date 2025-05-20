//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maze size
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the maze structure
struct Maze {
    int cells[MAZE_WIDTH][MAZE_HEIGHT];
    int startX;
    int startY;
    int endX;
    int endY;
};

// Define the node structure used in breadth-first search algorithm
struct Node {
    int x;
    int y;
    int distance;
    struct Node* prev;
};

// Function to print the maze with the shortest path
void printMaze(struct Maze maze, struct Node* endNode) {
    // Copy the maze cells to a string
    char mazeStr[MAZE_WIDTH * MAZE_HEIGHT + MAZE_HEIGHT + 1];
    int offset = 0;
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (endNode != NULL && endNode->prev != NULL && endNode->prev->x == j && endNode->prev->y == i) {
                mazeStr[offset++] = '*';  // Put an asterisk on the shortest path
            } else {
                mazeStr[offset++] = maze.cells[j][i] ? ' ' : '#';  // Wall or path
            }
        }
        mazeStr[offset++] = '\n';
    }
    mazeStr[offset] = '\0';
    puts(mazeStr);
}

// Function to find the shortest path through the maze
void findShortestPath(struct Maze maze) {
    // Initialize the queue with the starting position
    struct Node* startNode = malloc(sizeof(struct Node));
    startNode->x = maze.startX;
    startNode->y = maze.startY;
    startNode->distance = 0;
    startNode->prev = NULL;
    struct Node* queue = startNode;

    // Initialize the visited matrix
    int visited[MAZE_WIDTH][MAZE_HEIGHT];
    memset(visited, 0, sizeof(visited));
    visited[maze.startX][maze.startY] = 1;

    // Initialize the end node
    struct Node* endNode = NULL;

    // Breadth-first search algorithm
    while (queue != NULL) {
        struct Node* currNode = queue;
        queue = queue->prev;

        // Check if we've reached the end of the maze
        if (currNode->x == maze.endX && currNode->y == maze.endY) {
            endNode = currNode;
            break;
        }

        // Add all unvisited neighbors to the queue
        if (currNode->x > 0 && maze.cells[currNode->x - 1][currNode->y] && !visited[currNode->x - 1][currNode->y]) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode->x = currNode->x - 1;
            newNode->y = currNode->y;
            newNode->distance = currNode->distance + 1;
            newNode->prev = currNode;
            visited[newNode->x][newNode->y] = 1;
            newNode->prev = queue;
            queue = newNode;
        }

        if (currNode->x < MAZE_WIDTH - 1 && maze.cells[currNode->x + 1][currNode->y] && !visited[currNode->x + 1][currNode->y]) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode->x = currNode->x + 1;
            newNode->y = currNode->y;
            newNode->distance = currNode->distance + 1;
            newNode->prev = currNode;
            visited[newNode->x][newNode->y] = 1;
            newNode->prev = queue;
            queue = newNode;
        }

        if (currNode->y > 0 && maze.cells[currNode->x][currNode->y - 1] && !visited[currNode->x][currNode->y - 1]) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode->x = currNode->x;
            newNode->y = currNode->y - 1;
            newNode->distance = currNode->distance + 1;
            newNode->prev = currNode;
            visited[newNode->x][newNode->y] = 1;
            newNode->prev = queue;
            queue = newNode;
        }

        if (currNode->y < MAZE_HEIGHT - 1 && maze.cells[currNode->x][currNode->y + 1] && !visited[currNode->x][currNode->y + 1]) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode->x = currNode->x;
            newNode->y = currNode->y + 1;
            newNode->distance = currNode->distance + 1;
            newNode->prev = currNode;
            visited[newNode->x][newNode->y] = 1;
            newNode->prev = queue;
            queue = newNode;
        }
    }

    // Print the maze with the shortest path
    printMaze(maze, endNode);
}

int main() {
    // Define the maze
    struct Maze maze = {
        .cells = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
            {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        },
        .startX = 1,
        .startY = 1,
        .endX = MAZE_WIDTH - 2,
        .endY = MAZE_HEIGHT - 2
    };

    // Find the shortest path through the maze
    findShortestPath(maze);

    return 0;
}