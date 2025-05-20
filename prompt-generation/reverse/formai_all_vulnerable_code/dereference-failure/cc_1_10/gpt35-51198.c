//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15

// Cell structure to represent each cell in the maze
typedef struct {
    int x;
    int y;
    int visited;
    int walls[4]; // Top, Right, Bottom, Left
} Cell;

// Function to create a new Cell
Cell *newCell(int x, int y) {
    Cell *cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->visited = 0;
    for(int i=0; i<4; i++) {
        cell->walls[i] = 1;
    } 
    return cell;
}

// Function to get the index of a cell in the maze
int getIndex(int x, int y) {
    return y*WIDTH + x;
}

// Function to get a random unvisited neighbor of a cell
Cell *getRandomNeighbor(Cell *maze[], int x, int y) {
    Cell *neighbor[4] = {NULL};
    int count = 0;

    // Check top neighbor
    if(y-1 >= 0 && !maze[getIndex(x,y-1)]->visited) {
        neighbor[count++] = maze[getIndex(x,y-1)];
    }

    // Check right neighbor
    if(x+1 < WIDTH && !maze[getIndex(x+1,y)]->visited) {
        neighbor[count++] = maze[getIndex(x+1,y)];
    }

    // Check bottom neighbor
    if(y+1 < HEIGHT && !maze[getIndex(x,y+1)]->visited) {
        neighbor[count++] = maze[getIndex(x,y+1)];
    }

    // Check left neighbor
    if(x-1 >= 0 && !maze[getIndex(x-1,y)]->visited) {
        neighbor[count++] = maze[getIndex(x-1,y)];
    }

    // If there are unvisited neighbors, return a random one
    if(count > 0) {
        int randomIndex = rand() % count;
        return neighbor[randomIndex];
    } else {
        return NULL;
    }
}

// Function to remove the wall between two cells
void removeWall(Cell *cell1, Cell *cell2) {
    int x1 = cell1->x;
    int y1 = cell1->y;
    int x2 = cell2->x;
    int y2 = cell2->y;

    if(x1 == x2 && y1 < y2) {
        cell1->walls[2] = 0;
        cell2->walls[0] = 0;
    } else if(x1 == x2 && y1 > y2) {
        cell1->walls[0] = 0;
        cell2->walls[2] = 0;
    } else if(y1 == y2 && x1 < x2) {
        cell1->walls[1] = 0;
        cell2->walls[3] = 0;
    } else if(y1 == y2 && x1 > x2) {
        cell1->walls[3] = 0;
        cell2->walls[1] = 0;
    }
}

// Function to generate a random maze
void generateMaze(Cell *maze[]) {
    // Choose random cell to start
    int startX = rand() % WIDTH;
    int startY = rand() % HEIGHT;
    Cell *current = maze[getIndex(startX, startY)];
    current->visited = 1;

    // Generate maze using depth-first search algorithm
    while(1) {
        // Get random unvisited neighbor
        Cell *next = getRandomNeighbor(maze, current->x, current->y);
        if(next != NULL) {
            // Mark as visited
            next->visited = 1;
            // Remove wall between current cell and next cell
            removeWall(current, next);
            // Set next cell to current cell
            current = next;
        } else {
            // Backtrack to previous cell
            int prevIndex = getIndex(current->x, current->y);
            current = maze[prevIndex];
            if(current->x == startX && current->y == startY) {
                break;
            }
        }
    }
}

// Function to print the maze to the console
void printMaze(Cell *maze[]) {
    for(int y=0; y<HEIGHT; y++) {
        // Print top walls of each cell
        for(int x=0; x<WIDTH; x++) {
            if(maze[getIndex(x,y)]->walls[0]) {
                printf("+--");
            } else {
                printf("+  ");
            }
        }
        printf("+\n");

        // Print left and right walls of each cell
        for(int x=0; x<WIDTH; x++) {
            if(maze[getIndex(x,y)]->walls[3]) {
                printf("|  ");
            } else {
                printf("   ");
            }
            if(maze[getIndex(x,y)]->walls[1] && x == WIDTH-1) {
                printf("|");
            } else if(x == WIDTH-1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print bottom walls of maze
    for(int x=0; x<WIDTH; x++) {
        printf("+--");
    }
    printf("+\n");
}

int main() {
    // Create maze
    Cell *maze[WIDTH*HEIGHT];
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            maze[getIndex(x,y)] = newCell(x, y);
        }
    }

    // Generate maze
    srand(time(NULL));
    generateMaze(maze);

    // Print maze
    printMaze(maze);

    // Free memory
    for(int i=0; i<WIDTH*HEIGHT; i++) {
        free(maze[i]);
    }

    return 0;
}