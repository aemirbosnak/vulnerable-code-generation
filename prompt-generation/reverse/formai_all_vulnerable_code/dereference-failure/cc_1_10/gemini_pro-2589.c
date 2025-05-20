//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

char **createMaze(int rows, int cols){
    char **maze = (char**)malloc(sizeof(char*) * rows);
    for(int i = 0; i < rows; i++){
        maze[i] = (char*)malloc(sizeof(char) * (cols + 1));
        for(int j = 0; j < cols; j++)
            maze[i][j] = '#';
        maze[i][cols] = '\0';
    }
    return maze;
}
void freeMaze(char **maze, int rows){
    for(int i = 0; i < rows; i++)
        free(maze[i]);
    free(maze);
}
void printMaze(char **maze, int rows, int cols){
    for(int i = 0; i < rows; i++)
        printf("%s\n", maze[i]);
}
bool isValid(char **maze, int rows, int cols, int x, int y){
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != '#');
}
bool findPath(char **maze, int rows, int cols, int x, int y, int *path[], int pathLen){
    if(x == rows - 1 && y == cols - 1){
        path[pathLen++] = maze[x][y];
        return true;
    }
    if(isValid(maze, rows, cols, x, y)){
        path[pathLen++] = maze[x][y];
        if(findPath(maze, rows, cols, x + 1, y, path, pathLen) || findPath(maze, rows, cols, x, y + 1, path, pathLen))
            return true;
        pathLen--;
    }
    return false;
}
int main(){
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    char **maze = createMaze(rows, cols);
    printMaze(maze, rows, cols);
    int pathLen = 0;
    int *path[MAX_SIZE];
    if(findPath(maze, rows, cols, 0, 0, path, pathLen)){
        printf("Path found: ");
        for(int i = 0; i < pathLen; i++)
            printf("%c ", path[i]);
        printf("\n");
    }else
        printf("No path found.\n");
    freeMaze(maze, rows);
    return 0;
}