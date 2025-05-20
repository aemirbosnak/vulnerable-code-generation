//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 10
#define MAX_Y 10

#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int startX;
    int startY;
    int endX;
    int endY;
} Path;

int isInBounds(int x, int y) {
    return x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y;
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int aStarPathfinding(int startX, int startY, int endX, int endY) {
    int startRow = startY / 5;
    int startCol = startX / 5;
    int endRow = endY / 5;
    int endCol = endX / 5;

    int cost = 0;
    Path path = {startRow, startCol, endRow, endCol};

    if (startX == endX && startY == endY) {
        return cost;
    }

    if (!isInBounds(startRow, startCol) ||!isInBounds(endRow, endCol)) {
        return -1;
    }

    int* grid = (int*)malloc(MAX_X * MAX_Y * sizeof(int));
    for (int i = 0; i < MAX_X * MAX_Y; i++) {
        grid[i] = -1;
    }

    grid[startRow * MAX_X + startCol] = 0;

    while (path.startX!= path.endX || path.startY!= path.endY) {
        int currentRow = path.startY / 5;
        int currentCol = path.startX / 5;
        int targetRow = path.endY / 5;
        int targetCol = path.endX / 5;

        if (grid[currentRow * MAX_X + currentCol] == -1 &&
            grid[targetRow * MAX_X + targetCol] == -1) {
            int distance = manhattanDistance(currentRow, currentCol, targetRow, targetCol);
            if (distance < MAX_X * MAX_Y) {
                grid[targetRow * MAX_X + targetCol] = distance + grid[currentRow * MAX_X + currentCol];
                path.startX = currentCol;
                path.startY = currentRow;
                path.endX = targetCol;
                path.endY = targetRow;
            }
        }

        if (grid[currentRow * MAX_X + currentCol] == -1 ||
            grid[targetRow * MAX_X + targetCol] == -1) {
            grid[currentRow * MAX_X + currentCol] = -1;
            grid[targetRow * MAX_X + targetCol] = -1;
        } else {
            grid[currentRow * MAX_X + currentCol] = -1;
            grid[targetRow * MAX_X + targetCol] = -1;
        }
    }

    if (grid[endRow * MAX_X + endCol] == -1) {
        return -1;
    }

    printf("The path to reach the destination is:\n");
    printf("(StartX: %d, StartY: %d, EndX: %d, EndY: %d)\n", path.startX, path.startY, path.endX, path.endY);

    return grid[endRow * MAX_X + endCol];
}

int main() {
    int startX = 4;
    int startY = 5;
    int endX = 8;
    int endY = 3;

    printf("The cost of the path from (%d, %d) to (%d, %d) is: %d\n", startX, startY, endX, endY, aStarPathfinding(startX, startY, endX, endY));

    return 0;
}