//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 5
#define COL 5
 
// Define structure of nodes in the queue
struct Node {
    int row, col;
    struct Node* next;
};
 
// Add node to the queue
void enqueue(struct Node** front, int row, int col) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->row = row;
    temp->col = col;
    temp->next = NULL;
 
    if (*front == NULL) {
        *front = temp;
        return;
    }
 
    struct Node* rear = *front;
    while (rear->next) {
        rear = rear->next;
    }
    rear->next = temp;
}
 
// Remove node from the queue
void dequeue(struct Node** front) {
    if (*front == NULL) {
        return;
    }
 
    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}
 
// Check if node exists and is not already visited 
int isValid(int row, int col, int visited[ROW][COL], int maze[ROW][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL)
           && (maze[row][col] == 1) && (visited[row][col] == 0);
}
 
// Find route through maze
void bfs(int maze[][COL], int sr, int sc, int tr, int tc) {
    int visited[ROW][COL] = { { 0 } };
    visited[sr][sc] = 1;
    struct Node* front = NULL;
    enqueue(&front, sr, sc);
 
    while (front != NULL) {
        int row = front->row, col = front->col;
        dequeue(&front);
 
        // Check if we have reached the target
        if (row == tr && col == tc) {
            printf("\nRoute found!\n");
            return;
        }
 
        // Check all valid moves from current position
        if (isValid(row - 1, col, visited, maze)) {
            visited[row - 1][col] = 1;
            enqueue(&front, row - 1, col);
        }
        if (isValid(row + 1, col, visited, maze)) {
            visited[row + 1][col] = 1;
            enqueue(&front, row + 1, col);
        }
        if (isValid(row, col - 1, visited, maze)) {
            visited[row][col - 1] = 1;
            enqueue(&front, row, col - 1);
        }
        if (isValid(row, col + 1, visited, maze)) {
            visited[row][col + 1] = 1;
            enqueue(&front, row, col + 1);
        }
    }
    printf("\nRoute not found!\n");
}
 
int main() {
    int maze[ROW][COL] = {
        { 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 1 },
        { 1, 1, 1, 1, 0 },
        { 0, 0, 1, 1, 1 }
    };
    int sr = 0, sc = 0, tr = 4, tc = 4;
    bfs(maze, sr, sc, tr, tc);
    return 0;
}