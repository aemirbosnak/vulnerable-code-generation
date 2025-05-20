//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// node structure for the linked list
typedef struct node {
    int row, col;
    struct node* next;
} Node;

// function to create and return a new node
Node* createNode(int row, int col) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

// function to add a new node at the end of the linked list
void addToEnd(Node** head, int row, int col) {
    Node* newTail = createNode(row, col);
    if (*head == NULL) {
        *head = newTail;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTail;
    }
}

// function to remove the first node from the linked list and return it
Node* removeHead(Node** head) {
    if (*head == NULL) {
        return NULL;
    }
    else {
        Node* oldHead = *head;
        *head = oldHead->next;
        oldHead->next = NULL;
        return oldHead;
    }
}

// function to check if the given row and column indices are within the bounds of the grid
int isValid(int row, int col) {
    return (row >= 0 && row < ROW) && (col >= 0 && col < COL);
}

// function to check if the given row and column indices are valid and the corresponding cell contains a 1
int isSafe(int grid[ROW][COL], int row, int col, int visited[ROW][COL]) {
    return isValid(row, col) && grid[row][col] && !visited[row][col];
}

// recursive function to find a path from the starting point to the ending point
int findPath(int grid[ROW][COL], int startRow, int startCol, int endRow, int endCol, int visited[ROW][COL], Node** path) {
    if (!isSafe(grid, startRow, startCol, visited)) {
        return 0;
    }
    addToEnd(path, startRow, startCol);
    visited[startRow][startCol] = 1;
    if (startRow == endRow && startCol == endCol) {
        return 1;
    }
    if (findPath(grid, startRow + 1, startCol, endRow, endCol, visited, path)) {
        return 1;
    }
    if (findPath(grid, startRow, startCol + 1, endRow, endCol, visited, path)) {
        return 1;
    }
    if (findPath(grid, startRow - 1, startCol, endRow, endCol, visited, path)) {
        return 1;
    }
    if (findPath(grid, startRow, startCol - 1, endRow, endCol, visited, path)) {
        return 1;
    }
    Node* removedNode = removeHead(path);
    visited[removedNode->row][removedNode->col] = 0;
    free(removedNode);
    return 0;
}

int main() {
    // example grid with 0s and 1s
    int grid[ROW][COL] = {{1, 0, 0, 0, 0},
                          {1, 1, 1, 0, 1},
                          {0, 0, 1, 0, 0},
                          {0, 1, 1, 1, 0},
                          {0, 0, 0, 1, 1}};
    
    // starting and ending points
    int startRow = 0, startCol = 0;
    int endRow = 4, endCol = 4;
    
    // visited and path arrays
    int visited[ROW][COL] = {0};
    Node* path = NULL;
    
    // find the path and print it
    if (findPath(grid, startRow, startCol, endRow, endCol, visited, &path)) {
        printf("Path found:\n");
        Node* temp = path;
        while (temp != NULL) {
            printf("(%d, %d)\n", temp->row, temp->col);
            temp = temp->next;
        }
    }
    else {
        printf("No path found.\n");
    }
    
    return 0;
}