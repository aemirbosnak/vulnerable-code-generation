//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Structure to represent a cell */
typedef struct{
    int row, col;
} Cell;

/* Function to generate a random number between min and max (inclusive) */
int randomBetween(int min, int max){
    return rand() % (max - min + 1) + min;
}

/* Function to draw the maze */
void drawMaze(char** maze, int rows, int cols){
    printf("\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if a cell is valid */
int isValidCell(Cell cell, int rows, int cols){
    return cell.row >= 0 && cell.row < rows && cell.col >= 0 && cell.col < cols;
}

/* Function to check if a cell is a wall */
int isWall(Cell cell, char** maze){
    return maze[cell.row][cell.col] == '#';
}

/* Function to check if a cell is visited */
int isVisited(Cell cell, char** maze){
    return maze[cell.row][cell.col] == '*';
}

/* Function to check if the maze has been solved */
int isSolved(Cell cell, Cell end){
    return cell.row == end.row && cell.col == end.col;
}

/* Function to mark a cell as visited */
void markVisited(Cell cell, char** maze){
    maze[cell.row][cell.col] = '*';
}

/* Function to mark a cell as part of the route */
void markRoute(Cell cell, char** maze){
    maze[cell.row][cell.col] = '@';
}

/* Function to find a route through the maze */
int findRoute(Cell cell, Cell end, char** maze, int rows, int cols){
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Down, right, up, left
    markVisited(cell, maze);
    if(isSolved(cell, end)){
        return 1;
    }
    for(int i = 0; i < 4; i++){
        int newRow = cell.row + dirs[i][0];
        int newCol = cell.col + dirs[i][1];
        Cell newCell = {newRow, newCol};
        if(isValidCell(newCell, rows, cols) && !isWall(newCell, maze) && !isVisited(newCell, maze)){
            if(findRoute(newCell, end, maze, rows, cols)){
                markRoute(cell, maze);
                return 1;
            }
        }
    }
    return 0;
}

/* Main function */
int main(){
    srand(time(NULL)); // Seed the random number generator
    int rows = 11;
    int cols = 21;
    Cell start = {1, 1};
    Cell end = {rows - 2, cols - 2};
    char** maze = (char**)malloc(sizeof(char*) * rows);
    for(int i = 0; i < rows; i++){
        maze[i] = (char*)malloc(sizeof(char) * cols);
        for(int j = 0; j < cols; j++){
            if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1){
                maze[i][j] = '#'; // Set the border as walls
            } else {
                maze[i][j] = ' '; // Set empty spaces
            }
        }
    }
    // Create a random maze using depth-first search algorithm
    Cell current = start;
    int numVisited = 1;
    while(numVisited < (rows - 2) * (cols - 2)){
        markVisited(current, maze);
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Down, right, up, left
        while(1){
            int randDir = randomBetween(0, 3);
            int newRow = current.row + dirs[randDir][0];
            int newCol = current.col + dirs[randDir][1];
            Cell newCell = {newRow, newCol};
            if(isValidCell(newCell, rows, cols) && !isVisited(newCell, maze)){
                // Knock down the wall
                if(newRow > current.row){
                    maze[current.row + 1][current.col] = ' ';
                } else if(newRow < current.row){
                    maze[current.row - 1][current.col] = ' ';
                } else if(newCol > current.col){
                    maze[current.row][current.col + 1] = ' ';
                } else if(newCol < current.col){
                    maze[current.row][current.col - 1] = ' ';
                }
                current = newCell;
                numVisited++;
                break;
            }
        }
    }
    // Find a route through the maze
    findRoute(start, end, maze, rows, cols);
    // Draw the maze
    drawMaze(maze, rows, cols);
    // Free allocated memory
    for(int i = 0; i < rows; i++){
        free(maze[i]);
    }
    free(maze);
    return 0;
}