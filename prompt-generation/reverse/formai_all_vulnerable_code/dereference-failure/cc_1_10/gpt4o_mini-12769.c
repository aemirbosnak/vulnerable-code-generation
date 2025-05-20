//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_QUEUE_SIZE 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    float g;
    float h;
    float f;
    struct Node* parent;
} Node;

typedef struct {
    Node* array[MAX_QUEUE_SIZE];
    int size;
} NodeQueue;

// Function declarations
Node* createNode(int x, int y, Node* parent);
void addToQueue(NodeQueue* queue, Node* node);
Node* removeFromQueue(NodeQueue* queue);
bool isInQueue(NodeQueue* queue, Point pos);
float heuristic(Point a, Point b);
void printPath(Node* node);
void aStar(int grid[HEIGHT][WIDTH], Point start, Point goal);

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {9, 9};

    aStar(grid, start, goal);

    return 0;
}

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pos.x = x;
    newNode->pos.y = y;
    newNode->g = parent ? parent->g + 1 : 0;
    newNode->h = 0;
    newNode->f = 0;
    newNode->parent = parent;
    return newNode;
}

NodeQueue* createQueue() {
    NodeQueue* queue = (NodeQueue*)malloc(sizeof(NodeQueue));
    queue->size = 0;
    return queue;
}

void addToQueue(NodeQueue* queue, Node* node) {
    if (queue->size < MAX_QUEUE_SIZE) {
        queue->array[queue->size++] = node;
    }
}

Node* removeFromQueue(NodeQueue* queue) {
    if (queue->size > 0) {
        Node* minNode = queue->array[0];
        int minIndex = 0;
        for (int i = 1; i < queue->size; i++) {
            if (queue->array[i]->f < minNode->f) {
                minNode = queue->array[i];
                minIndex = i;
            }
        }
        for (int i = minIndex; i < queue->size - 1; i++) {
            queue->array[i] = queue->array[i + 1];
        }
        queue->size--;
        return minNode;
    }
    return NULL;
}

bool isInQueue(NodeQueue* queue, Point pos) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->array[i]->pos.x == pos.x && queue->array[i]->pos.y == pos.y) {
            return true;
        }
    }
    return false;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);  // Manhattan distance
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("-> (%d, %d) ", node->pos.x, node->pos.y);
}

void aStar(int grid[HEIGHT][WIDTH], Point start, Point goal) {
    NodeQueue* openSet = createQueue();
    NodeQueue* closedSet = createQueue();

    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->h = heuristic(start, goal);
    startNode->f = startNode->g + startNode->h;

    addToQueue(openSet, startNode);

    while (openSet->size > 0) {
        Node* currentNode = removeFromQueue(openSet);

        if (currentNode->pos.x == goal.x && currentNode->pos.y == goal.y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        addToQueue(closedSet, currentNode);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // skip diagonals
                int newX = currentNode->pos.x + dx;
                int newY = currentNode->pos.y + dy;

                if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT || grid[newY][newX] == 1) continue;
                Point newPoint = {newX, newY};

                if (isInQueue(closedSet, newPoint)) continue;

                Node* neighbor = createNode(newX, newY, currentNode);
                neighbor->h = heuristic(newPoint, goal);
                neighbor->f = neighbor->g + neighbor->h;

                if (isInQueue(openSet, newPoint)) {
                    free(neighbor); // Don't add duplicate neighbors.
                } else {
                    addToQueue(openSet, neighbor);
                }
            }
        }
    }

    printf("No path found!\n");
}