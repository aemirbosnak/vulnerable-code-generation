//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

typedef struct Node {
    int x, y;
    int gCost, hCost, fCost;
    struct Node* parent;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->gCost = 0;
    node->hCost = 0;
    node->fCost = 0;
    node->parent = NULL;
    return node;
}

int calculateHCost(Node* current, Node* end) {
    int dx = abs(current->x - end->x);
    int dy = abs(current->y - end->y);
    return dx + dy;
}

int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

int isBlocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 1;
}

int isDestination(int row, int col, Node* end) {
    return (row == end->x) && (col == end->y);
}

void printPath(Node* current) {
    if (current->parent == NULL) return;
    printPath(current->parent);
    printf("%d,%d\n", current->x, current->y);
}

void A_star(int grid[][COL], Node* start, Node* end) {
    if (isValid(start->x, start->y) == 0) {
        printf("Invalid Start\n");
        return;
    }
    if (isValid(end->x, end->y) == 0) {
        printf("Invalid End\n");
        return;
    }
    if (isBlocked(grid, start->x, start->y) || isBlocked(grid, end->x, end->y)) {
        printf("Start or End is blocked\n");
        return;
    }
    if (isDestination(start->x, start->y, end)) {
        printf("Already at destination!\n");
        return;
    }

    // initialize the open and closed lists
    Node* openList[ROW*COL];
    Node* closedList[ROW*COL];
    int openSize = 0;
    int closedSize = 0;

    // add the start node to the open list
    start->gCost = 0;
    start->hCost = calculateHCost(start, end);
    start->fCost = start->gCost + start->hCost;
    openList[openSize++] = start;

    // iterate until the destination is found or the open list is empty
    while (openSize > 0) {
        // sort the open list with ascending fCost values
        for (int i = 0; i < openSize-1; i++) {
            for (int j = 0; j < openSize-i-1; j++) {
                if (openList[j]->fCost > openList[j+1]->fCost) {
                    Node* temp = openList[j];
                    openList[j] = openList[j+1];
                    openList[j+1] = temp;
                }
            }
        }

        // get the node with the lowest fCost value
        Node* current = openList[0];

        // remove the current node from the open list and add to the closed list
        openList[0] = openList[--openSize];
        closedList[closedSize++] = current;

        // check if the current node is the destination
        if (isDestination(current->x, current->y, end)) {
            printf("Path Found!\n");
            printPath(current);
            return;
        }

        // iterate over the neighbors of the current node
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int row = current->x + dx[i];
            int col = current->y + dy[i];

            // skip if the neighbor is invalid or blocked or in the closed list
            if (isValid(row, col) == 0) continue;
            if (isBlocked(grid, row, col)) continue;
            int skip = 0;
            for (int j = 0; j < closedSize; j++) {
                if (closedList[j]->x == row && closedList[j]->y == col) {
                    skip = 1;
                    break;
                }
            }
            if (skip == 1) continue;

            // calculate the tentative gCost of the neighbor and add it to the open list if not already in
            int tentative_gCost = current->gCost + 1;
            Node* neighbor = NULL;
            int neighbor_index;
            for (int j = 0; j < openSize; j++) {
                if (openList[j]->x == row && openList[j]->y == col) {
                    neighbor = openList[j];
                    neighbor_index = j;
                    break;
                }
            }
            if (neighbor == NULL) {
                neighbor = createNode(row, col);
                neighbor->parent = current;
                neighbor->gCost = tentative_gCost;
                neighbor->hCost = calculateHCost(neighbor, end);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;
                openList[openSize++] = neighbor;
            } else if (tentative_gCost < neighbor->gCost) {
                neighbor->gCost = tentative_gCost;
                neighbor->fCost = neighbor->gCost + neighbor->hCost;
                neighbor->parent = current;
            }
        }
    }

    printf("Path not found!\n");
}

int main() {
    int grid[ROW][COL] = {{0, 0, 0, 0, 0},
                          {0, 1, 1, 0, 0},
                          {0, 1, 1, 0, 0},
                          {0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0}};

    Node* start = createNode(1, 1);
    Node* end = createNode(3, 3);

    A_star(grid, start, end);

    return 0;
}