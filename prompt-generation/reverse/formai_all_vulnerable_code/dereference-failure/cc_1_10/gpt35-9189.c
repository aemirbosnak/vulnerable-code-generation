//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>

#define ROWS 10
#define COLS 10

struct Node {
    int x, y;
    int g, h, f;
    struct Node* parent;
};

struct AStarPath {
    int x, y;
    int cost;
};

// Calculate the minimum value between the two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Check if a node is inside the map
int isInsideMap(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

// Calculate the Manhattan Distance from one node to another
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Generate the path from start to end using the parent nodes
int generatePath(struct Node* end, struct AStarPath path[ROWS * COLS]) {
    int len = 0;
    struct Node* current = end;
    while (current != NULL) {
        path[len].x = current->x;
        path[len].y = current->y;
        path[len++].cost = current->f;
        current = current->parent;
    }
    return len;
}

// Generate the neighbor nodes around the current node
int generateNeighbors(int x, int y, struct Node* node, struct Node* neighbors[8]) {
    int i = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int nx = x + dx;
            int ny = y + dy;
            if (!isInsideMap(nx, ny)) {
                continue;
            }
            if (node->parent != NULL && nx == node->parent->x && ny == node->parent->y) {
                continue;
            }
            struct Node* neighbor = malloc(sizeof(struct Node));
            neighbor->x = nx;
            neighbor->y = ny;
            neighbors[i++] = neighbor;
        }
    }
    return i;
}

// Check if a node is in the open list
struct Node* findNodeInOpenList(struct Node* nodes[ROWS][COLS], int x, int y) {
    return nodes[x][y];
}

// Check if a node is in the closed list
struct Node* findNodeInClosedList(struct Node* closed[ROWS * COLS], int x, int y) {
    for (int i = 0; i < ROWS * COLS; i++) {
        struct Node* node = closed[i];
        if (node == NULL) {
            break;
        }
        if (node->x == x && node->y == y) {
            return node;
        }
    }
    return NULL;
}

// Sort the open list nodes by their f value
void sortOpenList(struct Node* open[ROWS * COLS], int length) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (open[j]->f > open[j + 1]->f) {
                struct Node* temp = open[j + 1];
                open[j + 1] = open[j];
                open[j] = temp;
            }
        }
    }
}

// A* algorithm to find the shortest path from start to end
int findShortestPath(int map[ROWS][COLS], int sx, int sy, int ex, int ey, struct AStarPath path[ROWS * COLS]) {
    // Initialization
    struct Node* start = malloc(sizeof(struct Node));
    start->x = sx;
    start->y = sy;
    start->g = 0;
    start->h = manhattanDistance(sx, sy, ex, ey);
    start->f = start->g + start->h;
    start->parent = NULL;

    struct Node* nodes[ROWS][COLS] = { NULL };
    nodes[sx][sy] = start;

    struct Node* open[ROWS * COLS] = { NULL };
    open[0] = start;
    int openLength = 1;

    struct Node* closed[ROWS * COLS] = { NULL };
    int closedLength = 0;

    // A* loop
    while (openLength > 0) {
        struct Node* current = open[0];

        // Goal test
        if (current->x == ex && current->y == ey) {
            return generatePath(current, path);
        }

        // Remove current from open list
        open[0] = open[openLength - 1];
        open[openLength - 1] = NULL;
        openLength--;

        // Add current to closed list
        closed[closedLength++] = current;

        // Generate neighbors of current
        struct Node* neighbors[8] = { NULL };
        int neighborLength = generateNeighbors(current->x, current->y, current, neighbors);

        // Reorder open list
        sortOpenList(open, openLength);

        // Expand neighbors
        for (int i = 0; i < neighborLength; i++) {
            struct Node* neighbor = neighbors[i];

            // Skip if neighbor is in closed list
            if (findNodeInClosedList(closed, neighbor->x, neighbor->y) != NULL) {
                continue;
            }

            // Calculate g, h, and f values for neighbor
            neighbor->g = current->g + map[neighbor->x][neighbor->y];
            neighbor->h = manhattanDistance(neighbor->x, neighbor->y, ex, ey);
            neighbor->f = neighbor->g + neighbor->h;
            neighbor->parent = current;

            // Add neighbor to open list
            struct Node* existingNode = findNodeInOpenList(nodes, neighbor->x, neighbor->y);
            if (existingNode != NULL && existingNode->f < neighbor->f) {
                free(neighbor);
                continue;
            }
            nodes[neighbor->x][neighbor->y] = neighbor;
            open[openLength++] = neighbor;
        }

        // Clean up neighbors
        for (int i = 0; i < neighborLength; i++) {
            struct Node* neighbor = neighbors[i];
            if (findNodeInOpenList(open, neighbor->x, neighbor->y) == NULL) {
                if (findNodeInClosedList(closed, neighbor->x, neighbor->y) == NULL) {
                    free(neighbor);
                }
            }
        }
    }

    // No path found
    return 0;
}

int main() {
    int map[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    struct AStarPath path[ROWS * COLS];
    int pathLength = findShortestPath(map, 1, 1, 8, 8, path);

    printf("Shortest Path:\n");
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("(%d, %d) cost: %d\n", path[i].x, path[i].y, path[i].cost);
    }

    return 0;
}