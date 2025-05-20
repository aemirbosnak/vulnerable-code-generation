//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A struct to represent a node in the grid
struct Node {
    int x;
    int y;
    int cost;
};

// A struct to represent the A* algorithm
struct AStar {
    struct Node* grid;
    int width;
    int height;
    int startX;
    int startY;
    int goalX;
    int goalY;
    int startCost;
    int goalCost;
};

// A function to initialize the A* algorithm
void initAStar(struct AStar* astar, int width, int height, int startX, int startY, int goalX, int goalY, int startCost, int goalCost) {
    astar->width = width;
    astar->height = height;
    astar->startX = startX;
    astar->startY = startY;
    astar->goalX = goalX;
    astar->goalY = goalY;
    astar->startCost = startCost;
    astar->goalCost = goalCost;
    astar->grid = (struct Node*) malloc(width * height * sizeof(struct Node));
}

// A function to print the grid
void printGrid(struct AStar* astar) {
    int i, j;
    for (i = 0; i < astar->height; i++) {
        for (j = 0; j < astar->width; j++) {
            printf("%d ", astar->grid[i * astar->width + j].cost);
        }
        printf("\n");
    }
}

// A function to find the next node in the grid
struct Node* findNextNode(struct AStar* astar, struct Node* currentNode) {
    int i, j;
    struct Node* nextNode = NULL;
    int minCost = astar->grid[currentNode->x * astar->width + currentNode->y].cost + 1;
    for (i = 0; i < astar->height; i++) {
        for (j = 0; j < astar->width; j++) {
            if (i == astar->goalY && j == astar->goalX) {
                nextNode = astar->grid + i * astar->width + j;
                break;
            }
            if (astar->grid[i * astar->width + j].cost + 1 < minCost) {
                minCost = astar->grid[i * astar->width + j].cost + 1;
                nextNode = astar->grid + i * astar->width + j;
            }
        }
    }
    return nextNode;
}

// A function to run the A* algorithm
struct Node* runAStar(struct AStar* astar, struct Node* startNode) {
    struct Node* currentNode = startNode;
    struct Node* nextNode = NULL;
    while (true) {
        if (currentNode->x == astar->goalX && currentNode->y == astar->goalY) {
            return currentNode;
        }
        nextNode = findNextNode(astar, currentNode);
        if (nextNode == NULL) {
            break;
        }
        currentNode = nextNode;
    }
    return NULL;
}

// A function to free the memory allocated for the grid
void freeAStar(struct AStar* astar) {
    free(astar->grid);
}

int main() {
    int width = 10;
    int height = 10;
    int startX = 4;
    int startY = 5;
    int goalX = 7;
    int goalY = 8;
    int startCost = 0;
    int goalCost = 10;
    struct AStar* astar = (struct AStar*) malloc(sizeof(struct AStar));
    initAStar(astar, width, height, startX, startY, goalX, goalY, startCost, goalCost);
    struct Node* startNode = astar->grid + startX * astar->width + startY;
    printf("Start: (%d, %d)\n", startNode->x, startNode->y);
    printf("Goal: (%d, %d)\n", astar->goalX, astar->goalY);
    printGrid(astar);
    struct Node* path = runAStar(astar, startNode);
    if (path == NULL) {
        printf("No path found.\n");
    } else {
        printf("Path found.\n");
        printf("Path cost: %d\n", path->cost);
        printf("Path: ");
        int i = 0;
        while (path!= NULL) {
            printf("%d, ", path->x);
            path = astar->grid + path->x * astar->width + path->y;
            i++;
        }
        printf("\n");
    }
    freeAStar(astar);
    return 0;
}