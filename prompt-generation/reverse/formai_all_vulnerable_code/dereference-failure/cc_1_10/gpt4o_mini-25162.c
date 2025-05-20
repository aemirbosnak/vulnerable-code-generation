//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 20
#define INF 999999

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} OpenSet;

typedef struct {
    int parentX;
    int parentY;
    int gCost;
    int hCost;
    int fCost;
} NodeData;

int grid[MAX][MAX] = {
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
};


void initOpenSet(OpenSet *openSet) {
    openSet->size = 0;
    openSet->capacity = MAX * MAX;
    openSet->nodes = malloc(openSet->capacity * sizeof(Node));
}

void addToOpenSet(OpenSet *openSet, Node node) {
    openSet->nodes[openSet->size++] = node;
}

bool isInOpenSet(OpenSet *openSet, Node node) {
    for (int i = 0; i < openSet->size; i++) {
        if (openSet->nodes[i].x == node.x && openSet->nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

NodeData createNodeData(int parentX, int parentY, int gCost, int hCost) {
    NodeData data;
    data.parentX = parentX;
    data.parentY = parentY;
    data.gCost = gCost;
    data.hCost = hCost;
    data.fCost = gCost + hCost;
    return data;
}

void pathFinding(Node start, Node end) {
    NodeData nodeData[MAX][MAX];
    bool closedList[MAX][MAX] = {false};
    OpenSet openSet;
    initOpenSet(&openSet);
    
    addToOpenSet(&openSet, start);
    nodeData[start.x][start.y] = createNodeData(-1, -1, 0, heuristic(start, end));

    while (openSet.size > 0) {
        // Find the current node with the lowest fCost
        int currentIndex = -1;
        int lowestFCost = INF;
        for (int i = 0; i < openSet.size; i++) {
            int x = openSet.nodes[i].x;
            int y = openSet.nodes[i].y;
            if (nodeData[x][y].fCost < lowestFCost) {
                lowestFCost = nodeData[x][y].fCost;
                currentIndex = i;
            }
        }

        Node currentNode = openSet.nodes[currentIndex];
        if (currentNode.x == end.x && currentNode.y == end.y) {
            // Destination reached, reconstruct path
            printf("Path found:\n");
            Node path[MAX];
            int pathIndex = 0;

            while (currentNode.x != -1 && currentNode.y != -1) {
                path[pathIndex++] = currentNode;
                int tempX = nodeData[currentNode.x][currentNode.y].parentX;
                int tempY = nodeData[currentNode.x][currentNode.y].parentY;
                currentNode = (Node){tempX, tempY};
            }

            for (int i = pathIndex - 1; i >= 0; i--) {
                printf("(%d, %d) ", path[i].x, path[i].y);
            }
            printf("\n");
            free(openSet.nodes);
            return;
        }
        
        // Remove current node from openSet and add to closedList
        openSet.nodes[currentIndex] = openSet.nodes[--openSet.size];
        closedList[currentNode.x][currentNode.y] = true;
        
        // Check adjacent cells
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (abs(dx) == abs(dy))) {
                    continue; // Skip diagonal and self
                }
                
                int nx = currentNode.x + dx;
                int ny = currentNode.y + dy;

                if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && grid[nx][ny] == 0 && !closedList[nx][ny]) {
                    if (!isInOpenSet(&openSet, (Node){nx, ny})) {
                        nodeData[nx][ny] = createNodeData(currentNode.x, currentNode.y, nodeData[currentNode.x][currentNode.y].gCost + 1, heuristic((Node){nx, ny}, end));
                        addToOpenSet(&openSet, (Node){nx, ny});
                    }
                }
            }
        }
    }

    printf("No path found.\n");
    free(openSet.nodes);
}

int main() {
    Node start = {0, 0};
    Node end = {9, 9};
    pathFinding(start, end);
    return 0;
}