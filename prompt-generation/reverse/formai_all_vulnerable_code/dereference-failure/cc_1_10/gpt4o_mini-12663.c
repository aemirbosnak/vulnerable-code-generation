//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define NUM_THREADS 4
#define INF 9999

typedef struct {
    int startX, startY;
    int endX, endY;
    int thread_id;
} ThreadData;

typedef struct {
    int x, y, f, g, h;
    struct Node *parent;
} Node;

Node *grid[GRID_SIZE][GRID_SIZE];
bool closedSet[GRID_SIZE][GRID_SIZE];
bool openSet[GRID_SIZE][GRID_SIZE];
Node *cameFrom[GRID_SIZE][GRID_SIZE];

// Directions for moving in the grid
int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up

void initGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = (Node *)malloc(sizeof(Node));
            grid[i][j]->x = i;
            grid[i][j]->y = j;
            grid[i][j]->f = INF;
            grid[i][j]->g = INF;
            grid[i][j]->h = INF;
            grid[i][j]->parent = NULL;
            openSet[i][j] = false;
            closedSet[i][j] = false;
            cameFrom[i][j] = NULL;
        }
    }
}

// Heuristic function (Manhattan distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

// A* algorithm for finding path in a part of the grid
void *aStar(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int startX = data->startX;
    int startY = data->startY;
    int endX = data->endX;
    int endY = data->endY;
    
    Node *startNode = grid[startX][startY];
    Node *endNode = grid[endX][endY];

    openSet[startX][startY] = true;
    startNode->g = 0;
    startNode->h = heuristic(startX, startY, endX, endY);
    startNode->f = startNode->g + startNode->h;

    while (true) {
        // Find the node with the lowest f in openSet
        Node *currentNode = NULL;
        int lowestIndex = INF;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (openSet[i][j] && grid[i][j]->f < lowestIndex) {
                    lowestIndex = grid[i][j]->f;
                    currentNode = grid[i][j];
                }
            }
        }
        
        if (currentNode == NULL) break; // No more nodes to explore
        if (currentNode == endNode) break; // Path found

        // Move currentNode from open set to closed set
        openSet[currentNode->x][currentNode->y] = false;
        closedSet[currentNode->x][currentNode->y] = true;

        // Explore neighbors
        for (int direction = 0; direction < 4; direction++) {
            int neighborX = currentNode->x + directions[direction][0];
            int neighborY = currentNode->y + directions[direction][1];

            if (neighborX < 0 || neighborX >= GRID_SIZE || neighborY < 0 || neighborY >= GRID_SIZE || 
                closedSet[neighborX][neighborY]) {
                continue; // Skip out of bounds or closed node
            }

            Node *neighborNode = grid[neighborX][neighborY];

            int tempG = currentNode->g + 1; // 1 is the cost to move to neighbor

            if (!openSet[neighborX][neighborY]) {
                openSet[neighborX][neighborY] = true; // Discover a new node
            } else if (tempG >= neighborNode->g) {
                continue; // This is not a better path
            }

            // This path is the best until now. Record it!
            neighborNode->parent = currentNode;
            neighborNode->g = tempG;
            neighborNode->h = heuristic(neighborX, neighborY, endX, endY);
            neighborNode->f = neighborNode->g + neighborNode->h;
        }
    }

    // Output the path, if found
    if (cameFrom[endX][endY] != NULL || (endNode->g != INF)) {
        Node *tempNode = endNode;
        printf("Thread %d found a path:\n", data->thread_id);
        while (tempNode != NULL) {
            printf("(%d, %d) <- ", tempNode->x, tempNode->y);
            tempNode = tempNode->parent;
        }
        printf("Start\n");
    } else {
        printf("Thread %d found no path.\n", data->thread_id);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];

    initGrid();

    // Set start and end points for each thread
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].startX = 0;
        threadData[i].startY = 0;
        threadData[i].endX = GRID_SIZE - 1;
        threadData[i].endY = GRID_SIZE - 1;
        threadData[i].thread_id = i;
        pthread_create(&threads[i], NULL, aStar, &threadData[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free allocated memory
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            free(grid[i][j]);
        }
    }

    return 0;
}