//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

typedef struct node {  // represents a cell in the grid
    int row, col;
    int distance;  // distance of this cell from the source cell
    struct node* parent;  // to keep track of the path taken
} Node;

int isValid(int row, int col) {  // checks if given (row, col) is a valid index for the grid
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

int isBlocked(int grid[ROW][COL], int row, int col) {  // checks if given (row, col) cell is blocked
    return grid[row][col] == 1;
}

void printPath(Node* node) {  // prints the path taken from source to destination
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d,%d) ", node->row, node->col);
}

void shortestPath(int grid[ROW][COL], int sourceRow, int sourceCol, int destRow, int destCol) {
    if (!isValid(sourceRow, sourceCol) || !isValid(destRow, destCol)) {  // cannot find path if either source or destination are invalid
        printf("Invalid source/destination indices.");
        return;
    }
    if (isBlocked(grid, sourceRow, sourceCol) || isBlocked(grid, destRow, destCol)) {  // cannot find path if either source or destination are blocked
        printf("Source or destination cell is blocked.");
        return;
    }

    int visited[ROW][COL] = {0};  // keeps track of visited cells
    int rowMoves[] = {-1, 0, 1, 0};  // possible moves from current cell
    int colMoves[] = {0, 1, 0, -1};

    Node* source = (Node*)malloc(sizeof(Node));  // create node for source cell
    source->row = sourceRow;
    source->col = sourceCol;
    source->distance = 0;
    source->parent = NULL;

    visited[sourceRow][sourceCol] = 1;  // mark source as visited

    Node* queue[ROW*COL];  // create a queue to keep track of cells to visit next
    int front = 0, rear = 0;  // initialize queue
    queue[rear++] = source;

    while (front != rear) {  // keep looping while there are still cells to visit
        Node* curr = queue[front++];  // get the next cell to visit from queue
        
        if (curr->row == destRow && curr->col == destCol) {  // if we reached the destination cell, print the path taken and return
            printPath(curr);
            return;
        }
        
        for (int i = 0; i < 4; i++) {  // visit all possible moves from current cell
            int newRow = curr->row + rowMoves[i];
            int newCol = curr->col + colMoves[i];
            if (isValid(newRow, newCol) && !isBlocked(grid, newRow, newCol) && !visited[newRow][newCol]) {  // if new cell is valid to visit, mark as visited and add to queue
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->row = newRow;
                newNode->col = newCol;
                newNode->distance = curr->distance + 1;  // distance of next cell is 1 more than distance of current cell
                newNode->parent = curr;
                visited[newRow][newCol] = 1;
                queue[rear++] = newNode;
            }
        }
    }
}

int main() {
    int grid[ROW][COL] = {{0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 1},
                          {0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0}};  // sample grid with obstacles indicated by 1s
    int sourceRow = 0, sourceCol = 0;
    int destRow = 4, destCol = 4;

    printf("Shortest path from source (%d,%d) to destination (%d,%d) is: ", sourceRow, sourceCol, destRow, destCol);
    shortestPath(grid, sourceRow, sourceCol, destRow, destCol);  // call function to find shortest path

    return 0;
}