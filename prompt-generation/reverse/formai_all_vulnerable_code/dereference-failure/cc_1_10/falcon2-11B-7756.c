//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int x;
    int y;
} Point;

bool isPointInGrid(Point* point, int gridSize) {
    return point->x >= 0 && point->x < gridSize &&
           point->y >= 0 && point->y < gridSize;
}

int heuristic(Point* point1, Point* point2, int gridSize) {
    return abs(point1->x - point2->x) + abs(point1->y - point2->y);
}

bool isValidMove(Point* current, Point* goal, int gridSize) {
    int dx = goal->x - current->x;
    int dy = goal->y - current->y;
    return dx >= 0 && dy >= 0 && dx < gridSize && dy < gridSize;
}

bool isGoal(Point* current, Point* goal, int gridSize) {
    return current->x == goal->x && current->y == goal->y;
}

int main() {
    int gridSize = MAX_SIZE;
    int startX = 0;
    int startY = 0;
    int goalX = 3;
    int goalY = 3;
    Point start = (Point){startX, startY};
    Point goal = (Point){goalX, goalY};

    Point* current = (Point*)malloc(sizeof(Point));
    *current = start;

    int* visited = (int*)malloc(gridSize * gridSize * sizeof(int));
    for (int i = 0; i < gridSize * gridSize; i++) {
        visited[i] = -1;
    }

    int* path = (int*)malloc(gridSize * gridSize * sizeof(int));
    int pathLength = 0;

    visited[start.x * gridSize + start.y] = 0;

    while (true) {
        int minDistance = MAX_SIZE;
        int minDistanceIndex = -1;
        for (int i = 0; i < gridSize * gridSize; i++) {
            if (visited[i] == -1 && isValidMove(current, &goal, gridSize)) {
                int distance = heuristic(current, &goal, gridSize) + visited[i];
                if (distance < minDistance) {
                    minDistance = distance;
                    minDistanceIndex = i;
                }
            }
        }
        if (minDistanceIndex == -1) {
            break;
        }
        visited[minDistanceIndex] = 0;
        path[pathLength++] = minDistanceIndex / gridSize;
        current->x += path[pathLength - 1];
        current->y += path[pathLength - 1];
        path[pathLength++] = minDistanceIndex % gridSize;
    }

    printf("Path length: %d\n", pathLength);
    for (int i = 0; i < pathLength; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    return 0;
}