//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_SEARCH_NODES 100
#define INF 9999

typedef struct {
    int x;
    int y;
} Node;

typedef struct {
    Node node;
    float gCost; // Cost from start node to current node
    float hCost; // Heuristic cost to target node
    float fCost; // gCost + hCost
    struct PathNode* parent; // Pointer to parent node for path reconstruction
} PathNode;

PathNode* openList[MAX_SEARCH_NODES];
int openListCount = 0;
PathNode* closedList[MAX_SEARCH_NODES];
int closedListCount = 0;

// Function prototypes
float heuristic(Node a, Node b);
bool isInClosedList(Node node);
bool isInOpenList(Node node);
void addToOpenList(PathNode* node);
PathNode* getLowestCostNode();
void cleanupOpenList();
Node getNextMove(Node start, Node target, int grid[WIDTH][HEIGHT]);

int main() {
    int grid[WIDTH][HEIGHT] = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    Node start = {0, 0};
    Node target = {9, 9};

    Node nextMove = getNextMove(start, target, grid);
    if (nextMove.x == -1 && nextMove.y == -1) {
        printf("No path found.\n");
    } else {
        printf("Next move to (%d, %d)\n", nextMove.x, nextMove.y);
    }
    return 0;
}

float heuristic(Node a, Node b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool isInClosedList(Node node) {
    for (int i = 0; i < closedListCount; i++) {
        if (closedList[i]->node.x == node.x && closedList[i]->node.y == node.y) {
            return true;
        }
    }
    return false;
}

bool isInOpenList(Node node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->node.x == node.x && openList[i]->node.y == node.y) {
            return true;
        }
    }
    return false;
}

void addToOpenList(PathNode* node) {
    if (openListCount < MAX_SEARCH_NODES) {
        openList[openListCount++] = node;
    } else {
        printf("Open list overflow! Something went wrong...\n");
        exit(EXIT_FAILURE); // Fail fast if too many nodes are in the open list
    }
}

PathNode* getLowestCostNode() {
    PathNode* lowest = openList[0];
    for (int i = 1; i < openListCount; i++) {
        if (openList[i]->fCost < lowest->fCost) {
            lowest = openList[i];
        }
    }
    return lowest;
}

void cleanupOpenList() {
    for (int i = 0; i < openListCount; i++) {
        free(openList[i]);
    }
    openListCount = 0;
}

Node getNextMove(Node start, Node target, int grid[WIDTH][HEIGHT]) {
    // Initialize the open list and closed list
    PathNode* startNode = (PathNode*)malloc(sizeof(PathNode));
    startNode->node = start;
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, target);
    startNode->fCost = startNode->gCost + startNode->hCost;
    startNode->parent = NULL;

    addToOpenList(startNode);

    while (openListCount > 0) {
        PathNode* currentNode = getLowestCostNode();

        // Check if we've reached the target
        if (currentNode->node.x == target.x && currentNode->node.y == target.y) {
            Node nextMove = currentNode->node; // For demonstration, next move is the target node
            cleanupOpenList(); // Clean up before exit
            return nextMove;
        }

        // Move current node to closed list
        closedList[closedListCount++] = currentNode;

        // Neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (dx != 0 && dy != 0)) continue; // Skip the node itself or diagonal moves

                Node neighbor = {currentNode->node.x + dx, currentNode->node.y + dy};

                // Check boundaries and obstacles
                if (neighbor.x < 0 || neighbor.x >= WIDTH ||
                    neighbor.y < 0 || neighbor.y >= HEIGHT ||
                    grid[neighbor.x][neighbor.y] == 1 || // Check if it's an obstacle
                    isInClosedList(neighbor)) {
                    continue;
                }

                PathNode* neighborNode = (PathNode*)malloc(sizeof(PathNode));
                neighborNode->node = neighbor;
                neighborNode->gCost = currentNode->gCost + 1; // Assuming each move has a cost of 1
                neighborNode->hCost = heuristic(neighbor, target);
                neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
                neighborNode->parent = currentNode;

                // If it’s in the open list with a higher cost, skip it
                if (isInOpenList(neighbor) && neighborNode->gCost >= currentNode->gCost) {
                    free(neighborNode);
                    continue;
                }

                addToOpenList(neighborNode);
            }
        }

        // Remove the processed node from open list
        cleanupOpenList();
    }

    Node failure = {-1, -1}; // Indicate failure if no path found
    cleanupOpenList(); // Clean up any remaining open nodes
    return failure;
}