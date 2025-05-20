//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_THREADS 4

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node *start;
    Node *end;
    int grid[HEIGHT][WIDTH];
    bool found;
} AStarArgs;

typedef struct {
    Node *path;
    int length;
} PathResult;

Node *createNode(int x, int y) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    return node;
}

double heuristic(Node *a, Node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void *performAStar(void *args) {
    AStarArgs *astarArgs = (AStarArgs *)args;

    Node *start = astarArgs->start;
    Node *end = astarArgs->end;

    // Create open and closed lists
    Node **openList = malloc(WIDTH * HEIGHT * sizeof(Node *));
    bool closedList[HEIGHT][WIDTH];
    memset(closedList, false, sizeof(closedList));

    int openListCount = 0;
    openList[openListCount++] = createNode(start->x, start->y);

    while (openListCount > 0) {
        // Find node with the lowest f cost
        int lowestIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            // Compute f = g + h (for simplicity, assume g is always 1)
            double fCurrent = heuristic(openList[i], end);
            double fLowest = heuristic(openList[lowestIndex], end);
            if (fCurrent < fLowest) {
                lowestIndex = i;
            }
        }

        Node *current = openList[lowestIndex];

        // Check if we reached the end
        if (current->x == end->x && current->y == end->y) {
            astarArgs->found = true;
            free(openList);
            return NULL;
        }

        // Remove the current node from open list and add to closed
        openList[lowestIndex] = openList[--openListCount];
        closedList[current->y][current->x] = true;

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals

                int nx = current->x + dx;
                int ny = current->y + dy;

                if (nx < 0 || ny < 0 || nx >= WIDTH || ny >= HEIGHT || 
                    closedList[ny][nx] || astarArgs->grid[ny][nx] == 1) {
                    continue; // Skip if out of bounds, in closed, or blocked
                }

                // Add node to open list if not already there
                bool alreadyInOpen = false;
                for (int i = 0; i < openListCount; i++) {
                    if (openList[i]->x == nx && openList[i]->y == ny) {
                        alreadyInOpen = true;
                        break;
                    }
                }
                if (!alreadyInOpen) {
                    openList[openListCount++] = createNode(nx, ny);
                }
            }
        }

        free(current);
    }

    free(openList);
    return NULL;
}

int main() {
    // Sample grid definition (1: blocked, 0: free)
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
    };

    Node *start = createNode(0, 0);
    Node *end = createNode(9, 9);

    AStarArgs astarArgs = {start, end, {0}};
    memcpy(astarArgs.grid, grid, sizeof(grid));
    astarArgs.found = false;

    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, performAStar, (void *)&astarArgs);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    if (astarArgs.found) {
        printf("Path found from (%d, %d) to (%d, %d)\n", start->x, start->y, end->x, end->y);
    } else {
        printf("No path found.\n");
    }

    free(start);
    free(end);
    return 0;
}