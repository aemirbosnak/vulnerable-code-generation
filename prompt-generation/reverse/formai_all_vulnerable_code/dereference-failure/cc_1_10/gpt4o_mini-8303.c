//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE 'X'
#define PATH '.'
#define START 'S'
#define END 'E'

// Node Structure
typedef struct Node {
    int x, y;
    int gCost; // Cost from start to node
    int hCost; // Heuristic cost from node to end
    int fCost; // Total cost
    struct Node *parent;
} Node;

// Grid Structure
typedef struct Grid {
    char cells[HEIGHT][WIDTH];
    Node *nodes[HEIGHT][WIDTH];
} Grid;

// Function Declarations
Grid* createGrid();
void initializeGrid(Grid *grid);
void displayGrid(Grid *grid);
Node* createNode(int x, int y, Node *parent);
int heuristic(Node *a, Node *b);
void aStar(Grid *grid, Node *start, Node *end);
bool isValid(Node *node);
bool isDestination(Node *current, Node *destination);
void freeGrid(Grid *grid);

// Main Function
int main() {
    Grid *grid = createGrid();
    initializeGrid(grid);
    Node *start = grid->nodes[1][1]; // Start Point
    Node *end = grid->nodes[8][8]; // End Point

    printf("Initial Grid:\n");
    displayGrid(grid);

    aStar(grid, start, end);

    freeGrid(grid);
    return 0;
}

// Function Definitions
Grid* createGrid() {
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    return grid;
}

void initializeGrid(Grid *grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid->cells[i][j] = '.';
            grid->nodes[i][j] = createNode(j, i, NULL);
        }
    }
    // Set some obstacles
    grid->cells[2][3] = OBSTACLE;
    grid->cells[3][3] = OBSTACLE;
    grid->cells[6][5] = OBSTACLE;
    grid->cells[4][4] = OBSTACLE;

    grid->cells[1][1] = START;
    grid->cells[8][8] = END;
}

void displayGrid(Grid *grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid->cells[i][j]);
        }
        printf("\n");
    }
}

Node* createNode(int x, int y, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->gCost = INT_MAX;
    node->hCost = 0;
    node->fCost = 0;
    node->parent = parent;
    return node;
}

int heuristic(Node *a, Node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y); // Manhattan distance
}

bool isValid(Node *node) {
    return (node->x >= 0 && node->x < WIDTH && node->y >= 0 && node->y < HEIGHT);
}

bool isDestination(Node *current, Node *destination) {
    return current->x == destination->x && current->y == destination->y;
}

void aStar(Grid *grid, Node *start, Node *end) {
    bool openSet[HEIGHT][WIDTH] = { false };
    bool closedSet[HEIGHT][WIDTH] = { false };
    
    Node *current = start;
    start->gCost = 0;
    start->hCost = heuristic(start, end);
    start->fCost = start->gCost + start->hCost;

    while (true) {
        // Mark current node as in closed set
        closedSet[current->y][current->x] = true;
        
        if (isDestination(current, end)) {
            printf("Path found:\n");
            Node *temp = current;
            while (temp) {
                grid->cells[temp->y][temp->x] = '*'; // Mark the path
                temp = temp->parent;
            }
            displayGrid(grid);
            return;
        }

        // Check neighbors
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if ((dx == 0 && dy == 0) || (abs(dx) == abs(dy))) continue; // Skip the node itself and diagonals
                Node *neighbor = grid->nodes[current->y + dy][current->x + dx];
                if (!isValid(neighbor) || grid->cells[neighbor->y][neighbor->x] == OBSTACLE || closedSet[neighbor->y][neighbor->x]) {
                    continue;
                }

                int tentativeGCost = current->gCost + 1;
                if (!openSet[neighbor->y][neighbor->x]) {
                    openSet[neighbor->y][neighbor->x] = true;
                } else if (tentativeGCost >= neighbor->gCost) {
                    continue;
                }

                neighbor->parent = current;
                neighbor->gCost = tentativeGCost;
                neighbor->hCost = heuristic(neighbor, end);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;
            }
        }

        // Find node with lowest fCost
        current = NULL;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (openSet[i][j] && (current == NULL || grid->nodes[i][j]->fCost < current->fCost)) {
                    current = grid->nodes[i][j];
                }
            }
        }

        if (!current) {
            printf("No path found!\n");
            return;
        }
    }
}

void freeGrid(Grid *grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            free(grid->nodes[i][j]);
        }
    }
    free(grid);
}