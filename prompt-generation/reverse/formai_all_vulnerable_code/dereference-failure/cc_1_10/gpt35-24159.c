//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int grid[ROW][COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0}
};

bool visited[ROW][COL];

int start[2] = {0, 0}; 
int end[2] = {ROW-1, COL-1};

struct node {
    int x, y;
    struct node* parent;
};

struct node* getNode(int x, int y, struct node* parent) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->x = x; 
    newNode->y = y;
    newNode->parent = parent;

    return newNode;
}

bool isValid(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL || visited[x][y] || grid[x][y] == 1) {
        return false;
    }
    return true;
}

void printPath(struct node* node) {
    printf("Path: ");
    while (node != NULL) {
        printf("(%d,%d) ", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

void aStarSearch() {
    int xDir[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int yDir[8] = {0, 1, 0, -1, -1, 1, -1, 1};

    struct node* startNode = getNode(start[0], start[1], NULL);

    startNode->parent = startNode;

    struct node* currNode = NULL;

    visited[start[0]][start[1]] = true;
    bool reachedEnd = false;

    while (startNode != NULL) {
        int currX = startNode->x;
        int currY = startNode->y;
        int currF = 0;

        for (int i = 0; i < 8; i++) {
            int newX = currX + xDir[i];
            int newY = currY + yDir[i];

            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                struct node* newNode = getNode(newX, newY, startNode);
                
                // Manhattan Distance as Heuristic Function
                int h = abs(newX - end[0]) + abs(newY - end[1]);
                currF = h + 1;

                // Selecting the node with least f() 
                if (currNode == NULL || currF < currNode->x + currNode->y)
                currNode = newNode;

                // If end point is reached
                if (newX == end[0] && newY == end[1]) {
                    reachedEnd = true;
                    break;
                }
            }
        }
        if (reachedEnd) {
            break;
        }
        startNode = currNode;
        currNode = NULL;
    }
    if (!reachedEnd) {
        printf("No Path Found\n");
    }
    else {
        printPath(currNode);
    }
}

int main() {
    aStarSearch();
    return 0;
}