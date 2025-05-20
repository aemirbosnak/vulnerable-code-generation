//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the maze size
#define ROWS 8
#define COLS 8

// define the maze
int maze[ROWS][COLS] = {
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 1, 0},
};

// define the start and end points
int startRow = 0;
int startCol = 0;
int endRow = 7;
int endCol = 7;

// define a structure to represent a cell in the maze
struct Cell {
    int row;
    int col;
    int distance;
    struct Cell* parent;
};

// define the queue and the visited array
struct Cell* queue[ROWS * COLS];
bool visited[ROWS][COLS] = { false };

// enqueue a cell
void enqueue(struct Cell* cell, int* rear) {
    queue[(*rear)++] = cell;
}

// dequeue a cell
struct Cell* dequeue(int* front) {
    return queue[(*front)++];
}

// check if a cell is within the bounds of the maze
bool isValidCell(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0 && !visited[row][col]);
}

// check if the current cell is the end cell
bool isEndCell(int row, int col) {
    return (row == endRow && col == endCol);
}

// find the shortest path in the maze
void findShortestPath() {
    // define the queue front and rear
    int front = 0;
    int rear = 0;
    
    // create a new starting cell
    struct Cell* startCell = (struct Cell*)malloc(sizeof(struct Cell));
    startCell->row = startRow;
    startCell->col = startCol;
    startCell->distance = 0;
    startCell->parent = NULL;
    
    // enqueue the starting cell
    enqueue(startCell, &rear);
    
    // mark the starting cell as visited
    visited[startRow][startCol] = true;
    
    // initialize the distance
    int distance = -1;
    
    // loop until the queue is empty
    while (front != rear) {
        // dequeue a cell
        struct Cell* currentCell = dequeue(&front);
        
        // check if the current cell is the end cell
        if (isEndCell(currentCell->row, currentCell->col)) {
            // set the distance
            distance = currentCell->distance;
            break;
        }
        
        // explore the neighbors
        int row = currentCell->row;
        int col = currentCell->col;
        
        // up
        if (isValidCell(row - 1, col)) {
            struct Cell* newCell = (struct Cell*)malloc(sizeof(struct Cell));
            newCell->row = row - 1;
            newCell->col = col;
            newCell->distance = currentCell->distance + 1;
            newCell->parent = currentCell;
            enqueue(newCell, &rear);
            visited[row - 1][col] = true;
        }
        
        // down
        if (isValidCell(row + 1, col)) {
            struct Cell* newCell = (struct Cell*)malloc(sizeof(struct Cell));
            newCell->row = row + 1;
            newCell->col = col;
            newCell->distance = currentCell->distance + 1;
            newCell->parent = currentCell;
            enqueue(newCell, &rear);
            visited[row + 1][col] = true;
        }
        
        // left
        if (isValidCell(row, col - 1)) {
            struct Cell* newCell = (struct Cell*)malloc(sizeof(struct Cell));
            newCell->row = row;
            newCell->col = col - 1;
            newCell->distance = currentCell->distance + 1;
            newCell->parent = currentCell;
            enqueue(newCell, &rear);
            visited[row][col - 1] = true;
        }
        
        // right
        if (isValidCell(row, col + 1)) {
            struct Cell* newCell = (struct Cell*)malloc(sizeof(struct Cell));
            newCell->row = row;
            newCell->col = col + 1;
            newCell->distance = currentCell->distance + 1;
            newCell->parent = currentCell;
            enqueue(newCell, &rear);
            visited[row][col + 1] = true;
        }
    }
    
    // print the shortest path
    if (distance != -1) {
        printf("Shortest Path: ");
        struct Cell* currentCell = queue[0];
        while (currentCell != NULL) {
            printf("(%d, %d) ", currentCell->row, currentCell->col);
            currentCell = currentCell->parent;
        }
        printf("\nDistance: %d\n", distance);
    } else {
        printf("No Path Found!\n");
    }
}

// the main function
int main() {
    // find the shortest path
    findShortestPath();
    
    // return
    return 0;
}