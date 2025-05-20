//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cost function for A* algorithm
int cost(int x1, int y1, int x2, int y2) {
    return ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

// Heuristic function for A* algorithm
int heuristic(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// A* algorithm
int** aStar(int** grid, int sizeX, int sizeY, int startX, int startY, int endX, int endY) {
    // Initialize the priority queue
    int** queue = (int**)malloc(sizeof(int*) * sizeX * sizeY);
    int front = 0;
    int rear = 0;
    for (int i = 0; i < sizeX * sizeY; i++) {
        queue[i] = (int*)malloc(sizeof(int) * 2);
        queue[i][0] = i;
        queue[i][1] = grid[i][0];
    }

    // Set the start node as the first element in the queue
    queue[startX * sizeY + startY][1] = startX;
    queue[startX * sizeY + startY][0] = cost(startX, startY, endX, endY);

    // Set the end node as the last element in the queue
    queue[endX * sizeY + endY][1] = endX;
    queue[endX * sizeY + endY][0] = cost(endX, endY, startX, startY);

    // Add the start node to the queue
    rear = (rear + 1) % sizeX * sizeY;
    queue[rear][1] = startX;
    queue[rear][0] = cost(startX, startY, endX, endY);

    // Loop until the queue is empty
    while (front!= rear) {
        // Get the node with the lowest cost
        int minCost = queue[front][0];
        int minCostIndex = front;
        for (int i = front + 1; i < sizeX * sizeY; i++) {
            if (queue[i][0] < minCost) {
                minCost = queue[i][0];
                minCostIndex = i;
            }
        }

        // If the current node is the goal node, return the path
        if (minCostIndex == endX * sizeY + endY) {
            int** path = (int**)malloc(sizeof(int*) * (endX - startX + 1));
            int pathLength = 0;
            int currentX = endX;
            int currentY = endY;
            while (currentX!= startX || currentY!= startY) {
                path[pathLength] = (int*)malloc(sizeof(int) * 2);
                path[pathLength][0] = currentX;
                path[pathLength][1] = currentY;
                currentX = queue[currentX * sizeY + currentY][1];
                currentY = queue[currentX * sizeY + currentY][0];
                pathLength++;
            }
            path[pathLength][0] = startX;
            path[pathLength][1] = startY;
            return path;
        }

        // Remove the current node from the queue
        front = (front + 1) % sizeX * sizeY;
        queue[front][1] = queue[minCostIndex][1];
        queue[front][0] = queue[minCostIndex][0];

        // Add the neighbors of the current node to the queue
        for (int i = 0; i < 8; i++) {
            int newX = queue[minCostIndex][1] + (i & 1? 1 : -1);
            int newY = queue[minCostIndex][0] + (i & 2? 1 : -1);
            if (newX >= 0 && newX < sizeX && newY >= 0 && newY < sizeY) {
                int newCost = cost(newX, newY, endX, endY);
                queue[rear][1] = newX;
                queue[rear][0] = newCost;
                rear = (rear + 1) % sizeX * sizeY;
            }
        }
    }
    return NULL;
}

int main() {
    int sizeX = 20;
    int sizeY = 20;
    int startX = 10;
    int startY = 10;
    int endX = 19;
    int endY = 19;

    // Create the grid
    int** grid = (int**)malloc(sizeof(int*) * sizeX);
    for (int i = 0; i < sizeX; i++) {
        grid[i] = (int*)malloc(sizeof(int) * sizeY);
        for (int j = 0; j < sizeY; j++) {
            grid[i][j] = rand() % 10 + 1;
        }
    }

    // Call the A* algorithm
    int** path = aStar(grid, sizeX, sizeY, startX, startY, endX, endY);

    // Print the path
    if (path!= NULL) {
        for (int i = 0; i < endX - startX + 1; i++) {
            printf("%d %d ", path[i][0], path[i][1]);
        }
        printf("%d\n", path[endX - startX][0]);
    } else {
        printf("No path found\n");
    }

    return 0;
}