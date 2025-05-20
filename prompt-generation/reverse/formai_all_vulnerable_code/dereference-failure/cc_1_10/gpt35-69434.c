//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

// Defining a constant for maximum size of maze
#define MAX_SIZE 20

// Defining a constant to represent the wall and empty space
#define WALL 1
#define PATH 0

// Defining a structure to represent coordinates of a cell in the maze
typedef struct {
    int x;
    int y;
} Point;

// Function to read the maze from the file
void readMaze(int maze[][MAX_SIZE], int size, FILE *file) {
    int i, j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            fscanf(file, "%d", &maze[i][j]);
        }
    }
}

// Function to print the maze
void printMaze(int maze[][MAX_SIZE], int size) {
    int i, j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find the path in the maze
int findPath(int maze[][MAX_SIZE], int size, Point start, Point end) {
    // Creating a queue to store the path
    Point queue[MAX_SIZE*MAX_SIZE];
    int front = 0, rear = -1;
    
    // Marking the starting point as visited
    maze[start.x][start.y] = PATH;
    
    // Adding the starting point to the queue
    queue[++rear] = start;
    
    // Array to store the directions
    Point direction[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // Loop until the queue is empty
    while(front<=rear) {
        Point current = queue[front++];
        
        // If the end point is reached, return 1 
        if(current.x==end.x && current.y==end.y) {
            return 1;
        }
        
        // Loop for all the directions
        int i;
        for(i=0;i<4;i++) {
            Point next = {current.x + direction[i].x, current.y + direction[i].y};
            
            // Checking if the next point is valid
            if(next.x>=0 && next.x<size && next.y>=0 && next.y<size && maze[next.x][next.y]==PATH) {
                
                // Marking the next point as visited and adding it to the queue
                maze[next.x][next.y] = maze[current.x][current.y] + 1;
                queue[++rear] = next;
            }
        }
    }
    
    // If the end point is not reached, return 0
    return 0;
}

int main() {
    int maze[MAX_SIZE][MAX_SIZE];
    int size, i, j;
    Point start, end;
    
    // Opening the file to read the maze
    FILE *file = fopen("maze.txt", "r");
    if(file==NULL) {
        printf("Error opening file");
        exit(0);
    }
    
    // Reading the size of the maze
    fscanf(file, "%d", &size);
    
    // Reading the maze from the file
    readMaze(maze, size, file);
    
    // Printing the maze
    printf("Maze:\n");
    printMaze(maze, size);
    
    // Reading the starting and ending points
    printf("Enter the starting point coordinates (x, y): ");
    scanf("%d %d", &start.x, &start.y);
    
    printf("Enter the ending point coordinates (x, y): ");
    scanf("%d %d", &end.x, &end.y);
    
    // Checking if the starting and ending points are valid
    if(start.x<0 || start.x>=size || start.y<0 || start.y>=size || end.x<0 || end.x>=size || end.y<0 || end.y>=size) {
        printf("Invalid starting/ending point coordinates");
        exit(0);
    }
    
    // Finding the path in the maze
    if(findPath(maze, size, start, end)) {
        printf("Path found\n");
        printf("Minimum number of steps required: %d", maze[end.x][end.y]);
    }
    else {
        printf("Path not found");
    }
    
    // Closing the file
    fclose(file);
    return 0;
}