//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Maze
{
    int x;
    int y;
    int width;
    int height;
    int *matrix;
};

struct Maze createMaze(int width, int height)
{
    struct Maze maze;
    maze.x = 0;
    maze.y = 0;
    maze.width = width;
    maze.height = height;
    maze.matrix = (int *)malloc(width * height * sizeof(int));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze.matrix[i * height + j] = 0;
        }
    }
    return maze;
}

int isWall(int x, int y, int width, int height, int *matrix)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return 1;
    return matrix[y * width + x];
}

void setWall(int x, int y, int width, int height, int *matrix)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return;
    matrix[y * width + x] = 1;
}

int main()
{
    int width = 10;
    int height = 10;
    struct Maze maze = createMaze(width, height);
    int *matrix = maze.matrix;
    
    int startX = 5;
    int startY = 5;
    int endX = 9;
    int endY = 9;
    
    setWall(startX, startY, width, height, matrix);
    setWall(endX, endY, width, height, matrix);
    
    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            if (isWall(j, i, width, height, matrix)) {
                printf("%d ", j);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}