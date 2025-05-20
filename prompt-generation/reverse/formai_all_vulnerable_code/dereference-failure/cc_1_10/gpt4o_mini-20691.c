//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define FREE '.'
#define START 'S'
#define END 'E'

// Structure to represent a cell in the grid
typedef struct {
    int x;
    int y;
} Cell;

// Structure to represent a node in the pathfinding algorithm
typedef struct Node {
    Cell cell;
    float g_cost; // Cost from start to current node
    float h_cost; // Heuristic cost to end node
    float f_cost; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, float g_cost, float h_cost, Node* parent) {
    Node* newNode = malloc(sizeof(Node));
    newNode->cell.x = x;
    newNode->cell.y = y;
    newNode->g_cost = g_cost;
    newNode->h_cost = h_cost;
    newNode->f_cost = g_cost + h_cost;
    newNode->parent = parent;
    return newNode;
}

float heuristic(Cell a, Cell b) {
    return fabsf(a.x - b.x) + fabsf(a.y - b.y);
}

bool isValidCell(int x, int y, char grid[HEIGHT][WIDTH]) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != OBSTACLE);
}

void reconstructPath(Node* node) {
    if (node == NULL) return;
    reconstructPath(node->parent);
    printf(" -> (%d, %d)", node->cell.x, node->cell.y);
}

void aStar(char grid[HEIGHT][WIDTH], Cell start, Cell end) {
    Node* openList[WIDTH * HEIGHT];
    int openListSize = 0;
    Node* closedList[WIDTH * HEIGHT];
    int closedListSize = 0;

    openList[openListSize++] = createNode(start.x, start.y, 0.0f, heuristic(start, end), NULL);

    while (openListSize > 0) {
        int currentNodeIndex = 0;
        Node* currentNode = openList[0];

        // Find the node with the lowest f_cost
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f_cost < currentNode->f_cost) {
                currentNode = openList[i];
                currentNodeIndex = i;
            }
        }

        // Remove currentNode from openList
        openList[currentNodeIndex] = openList[--openListSize];

        // Check if we reached the end
        if (currentNode->cell.x == end.x && currentNode->cell.y == end.y) {
            printf("Path: (%d, %d)", currentNode->cell.x, currentNode->cell.y);
            reconstructPath(currentNode);
            printf("\n");
            return;
        }

        // Add currentNode to closedList
        closedList[closedListSize++] = currentNode;

        // Check neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue; // Only consider horizontal and vertical moves
                int newX = currentNode->cell.x + dx;
                int newY = currentNode->cell.y + dy;

                if (!isValidCell(newX, newY, grid)) continue;

                // Create new node
                float newGCost = currentNode->g_cost + 1;
                Node* newNode = createNode(newX, newY, newGCost, heuristic((Cell){newX, newY}, end), currentNode);

                // Check if it is in closedList
                bool inClosedList = false;
                for (int i = 0; i < closedListSize; i++) {
                    if (closedList[i]->cell.x == newNode->cell.x && closedList[i]->cell.y == newNode->cell.y) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) {
                    free(newNode);
                    continue;
                }

                // Check if it is in openList
                bool inOpenList = false;
                for (int i = 0; i < openListSize; i++) {
                    if (openList[i]->cell.x == newNode->cell.x && openList[i]->cell.y == newNode->cell.y) {
                        inOpenList = true;
                        if (openList[i]->g_cost > newNode->g_cost) {
                            openList[i]->g_cost = newNode->g_cost;
                            openList[i]->f_cost = newGCost + openList[i]->h_cost;
                            openList[i]->parent = currentNode;
                        }
                        free(newNode);
                        break;
                    }
                }

                if (!inOpenList) {
                    openList[openListSize++] = newNode;
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {FREE, FREE, FREE, OBSTACLE, FREE, FREE, FREE, FREE, OBSTACLE, FREE},
        {FREE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, FREE, FREE, FREE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE},
        {OBSTACLE, OBSTACLE, FREE, OBSTACLE, OBSTACLE, FREE, FREE, FREE, FREE, FREE},
        {FREE, FREE, FREE, FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE, FREE},
        {FREE, OBSTACLE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, END},
        {START, OBSTACLE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE, FREE, OBSTACLE, OBSTACLE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE},
        {FREE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, OBSTACLE, FREE, FREE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE}
    };

    Cell start = {0, 6}; // Starting position
    Cell end = {9, 5};   // Ending position

    aStar(grid, start, end);
    return 0;
}