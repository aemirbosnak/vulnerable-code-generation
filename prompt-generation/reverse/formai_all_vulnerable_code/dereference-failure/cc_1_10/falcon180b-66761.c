//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10
#define M 20

//Structure for Maze
typedef struct{
    int **maze;
    int startX, startY, endX, endY;
    int path[N][M];
}Maze;

//Function to create Maze
void createMaze(Maze *maze){
    int i, j;
    maze->maze = (int **)malloc(N*sizeof(int *));
    for(i=0; i<N; i++){
        maze->maze[i] = (int *)malloc(M*sizeof(int));
        for(j=0; j<M; j++){
            maze->maze[i][j] = rand()%2;
        }
    }
    maze->startX = 0;
    maze->startY = 0;
    maze->endX = N-1;
    maze->endY = M-1;
}

//Function to solve Maze
void solveMaze(Maze *maze){
    int i, j, x, y, count=0;
    memset(maze->path, -1, sizeof(maze->path));
    maze->path[0][0] = 0;
    while(count<N*M){
        x = rand()%N;
        y = rand()%M;
        if(maze->path[x][y]==-1){
            if(x==maze->startX && y==maze->startY){
                maze->path[x][y] = 0;
            }else if(x==maze->endX && y==maze->endY){
                maze->path[x][y] = 2;
            }else{
                maze->path[x][y] = 1;
            }
            count++;
        }
    }
}

//Function to print Maze
void printMaze(Maze *maze){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(maze->maze[i][j]==1){
                printf("  ");
            }else{
                printf("██");
            }
        }
        printf("\n");
    }
}

//Function to print Path
void printPath(Maze *maze){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(maze->path[i][j]==0){
                printf(" ");
            }else if(maze->path[i][j]==1){
                printf("*");
            }else{
                printf("E");
            }
        }
        printf("\n");
    }
}

int main(){
    Maze maze;
    createMaze(&maze);
    solveMaze(&maze);
    printMaze(&maze);
    printPath(&maze);
    return 0;
}