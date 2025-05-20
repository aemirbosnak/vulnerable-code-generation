//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define maze size
#define MAZE_SIZE 10

// Define wall and path characters
#define WALL '#'
#define PATH '.'

// Define structure for maze
typedef struct maze{
    char arr[MAZE_SIZE][MAZE_SIZE];
} Maze;

// Initialize maze
Maze* initMaze(){
    // Allocate memory for maze
    Maze* maze = malloc(sizeof(Maze));
    
    // Set all walls
    for(int i=0; i<MAZE_SIZE; i++){
        for(int j=0; j<MAZE_SIZE; j++){
            maze->arr[i][j] = WALL;
        }
    }
    
    // Set start and finish
    maze->arr[0][0] = PATH;
    maze->arr[MAZE_SIZE-1][MAZE_SIZE-1] = PATH;
    
    return maze;
}

// Print maze
void printMaze(Maze* maze){
    for(int i=0; i<MAZE_SIZE; i++){
        for(int j=0; j<MAZE_SIZE; j++){
            printf("%c ",maze->arr[i][j]);
        }
        printf("\n");
    }
}

// Find route through maze
int findRoute(Maze* maze, int x, int y){
    // Check if we've reached the end
    if(x == MAZE_SIZE-1 && y == MAZE_SIZE-1){
        maze->arr[x][y] = PATH;
        return 1;
    }
    
    // Check if current location is a wall or already visited
    if(maze->arr[x][y] == WALL || maze->arr[x][y] == 'X'){
        return 0;
    }
    
    // Mark current location as visited
    maze->arr[x][y] = 'X';
    
    // Check adjacent locations for viable path
    if(findRoute(maze, x+1, y) || findRoute(maze, x-1, y) || findRoute(maze, x, y+1) || findRoute(maze, x, y-1)){
        maze->arr[x][y] = PATH;
        return 1;
    }
    
    return 0;
}

int main(){
    // Initialize maze
    Maze* maze = initMaze();
    
    // Print starting maze
    printf("Starting Maze:\n");
    printMaze(maze);
    
    // Find route through maze
    if(!findRoute(maze, 0, 0)){
        printf("No route found.\n");
    }
    
    // Print finished maze
    printf("Finished Maze:\n");
    printMaze(maze);
    
    // Free memory
    free(maze);
    
    return 0;
}