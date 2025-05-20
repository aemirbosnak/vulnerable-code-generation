//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Directions for movement in the maze
int rowDir[] = {0, 1, 0, -1};
int colDir[] = {1, 0, -1, 0};

// Function to check if the given cell is valid for the path
bool isValid(int maze[ROW][COL], bool visited[ROW][COL], int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && 
           (maze[row][col] == 1) && (!visited[row][col]);
}

// Structure to represent a path in the maze
typedef struct {
    int row;
    int col;
    int dist;
    char path[ROW * COL];
} Node;

// Function to find the route through the maze
void findPath(int maze[ROW][COL], int startX, int startY, int endX, int endY) {
    // This array keeps track of visited cells
    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }
    
    // Creating a queue for BFS
    Node *queue = (Node *)malloc(ROW * COL * sizeof(Node));
    int front = 0, rear = 0;

    // Starting point
    visited[startX][startY] = true;
    Node startNode = {startX, startY, 0, ""};
    queue[rear++] = startNode;

    // Grateful message
    printf("Grateful for every step taken in the maze!\n");

    while (front < rear) {
        Node curr = queue[front++];
        
        // Checking if reached the destination
        if (curr.row == endX && curr.col == endY) {
            printf("A path has been found! Thank you, maze!\n");
            printf("Distance: %d\nPath: %s\n", curr.dist, curr.path);
            free(queue);
            return;
        }
        
        // Explore all possible movements
        for (int d = 0; d < 4; d++) {
            int newRow = curr.row + rowDir[d];
            int newCol = curr.col + colDir[d];

            if (isValid(maze, visited, newRow, newCol)) {
                visited[newRow][newCol] = true;

                // Create a new path string that accumulates the characters 'U', 'D', 'L', 'R'
                char newPath[ROW * COL];
                snprintf(newPath, sizeof(newPath), "%s%s", curr.path, 
                         d == 0 ? "R" : d == 1 ? "D" : d == 2 ? "L" : "U");

                Node nextNode = {newRow, newCol, curr.dist + 1, ""};
                strcpy(nextNode.path, newPath);
                queue[rear++] = nextNode;
            }
        }
    }

    printf("No path found! But grateful for the attempt!\n");
    free(queue);
}

// Main function to drive the program
int main() {
    // Gracious thanks for setting up the maze
    printf("Thank you for using the Maze Route Finder!\n");

    // Sample maze representation (1: path, 0: wall)
    int maze[ROW][COL] = {
        {1, 0, 0, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1}
    };

    // Start and End points for the maze
    int startX = 0, startY = 0; // Starting point (0,0)
    int endX = 4, endY = 4; // Ending point (4,4)

    // Finding the path in the maze
    findPath(maze, startX, startY, endX, endY);

    // Closing message
    printf("Thank you for this opportunity to explore a maze! Farewell!\n");
    return 0;
}