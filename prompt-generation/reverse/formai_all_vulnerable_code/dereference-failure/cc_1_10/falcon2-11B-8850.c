//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    int row;
    int col;
} Point;

typedef struct{
    int size;
    Point **matrix;
} Maze;

Maze* createMaze(int size){
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->size = size;
    maze->matrix = (Point**)malloc(size * sizeof(Point*));
    for(int i=0; i<size; i++){
        maze->matrix[i] = (Point*)malloc(size * sizeof(Point));
        for(int j=0; j<size; j++){
            maze->matrix[i][j].row = i;
            maze->matrix[i][j].col = j;
        }
    }
    return maze;
}

void printMaze(Maze* maze){
    for(int i=0; i<maze->size; i++){
        for(int j=0; j<maze->size; j++){
            printf("%d ", maze->matrix[i][j].row * maze->size + maze->matrix[i][j].col);
        }
        printf("\n");
    }
    printf("\n");
}

bool isWall(Maze* maze, int row, int col){
    if(row < 0 || row >= maze->size || col < 0 || col >= maze->size)
        return true;
    return maze->matrix[row][col].row * maze->size + maze->matrix[row][col].col == 0;
}

void floodFill(Maze* maze, Point start, Point end, int dir){
    if(start.row == end.row && start.col == end.col)
        return;
    if(isWall(maze, start.row, start.col)){
        return;
    }
    maze->matrix[start.row][start.col].row = 0;
    maze->matrix[start.row][start.col].col = 0;
    if(dir == 0)
        maze->matrix[start.row + 1][start.col].row = 0;
    if(dir == 1)
        maze->matrix[start.row][start.col + 1].col = 0;
    if(dir == 2)
        maze->matrix[start.row - 1][start.col].row = 0;
    if(dir == 3)
        maze->matrix[start.row][start.col - 1].col = 0;
    floodFill(maze, start, end, (dir + 1) % 4);
}

int main(){
    int size = 5;
    Maze* maze = createMaze(size);
    Point start = {0, 0};
    Point end = {size-1, size-1};
    printf("Start: (%d, %d)\n", start.row, start.col);
    printf("End: (%d, %d)\n", end.row, end.col);
    floodFill(maze, start, end, 1);
    printMaze(maze);
    return 0;
}