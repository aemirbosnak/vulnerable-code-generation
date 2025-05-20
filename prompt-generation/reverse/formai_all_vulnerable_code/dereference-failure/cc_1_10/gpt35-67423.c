//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: rigorous
#include <stdio.h>
#define ROW 5
#define COL 6
 
void printPath(int path[ROW][COL], int row, int col)
{
    if (path[row][col] == -1) {
        printf("(%d, %d) ", row, col);
        return;
    }
 
    printPath(path, row + 1, col - path[row][col]);
    printf("(%d, %d) ", row, col);
}
 
void findRoute(int maze[ROW][COL])
{
    int path[ROW][COL];
 
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1;
        }
    }
 
    path[0][0] = 0;
 
    for (int col = 1; col < COL; col++) {
        if (maze[0][col] == 1) {
            path[0][col] = -1;
        } else {
            path[0][col] = 0;
        }
    }
 
    for (int row = 1; row < ROW; row++) {
        if (maze[row][0] == 1) {
            path[row][0] = -1;
        } else {
            path[row][0] = 0;
        }
    }
 
    for (int row = 1; row < ROW; row++) {
        for (int col = 1; col < COL; col++) {
            if (maze[row][col] == 1) {
                path[row][col] = -1;
            } else {
                if (path[row - 1][col] != -1) {
                    path[row][col] = row - 1;
                } else if (path[row][col - 1] != -1) {
                    path[row][col] = col - path[row][col - 1];
                } else {
                    path[row][col] = -1;
                }
            }
        }
    }
 
    if (path[ROW - 1][COL - 1] == -1) {
        printf("No Route Found!");
    } else {
        printf("Route Found: ");
        printPath(path, ROW - 1, COL - 1);
    }
}
 
int main()
{
    int maze[ROW][COL] = {
        { 0, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0 }
    };
 
    findRoute(maze);
 
    return 0;
}