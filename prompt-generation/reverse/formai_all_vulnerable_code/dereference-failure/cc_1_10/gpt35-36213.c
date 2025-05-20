//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

// Structure to represent a point on the map
struct Point {
    int x, y;
};

// Structure to represent a node in the Priority Queue
struct PQNode {
    int priority;
    struct Point point;
};

// Structure to represent the Priority Queue
struct PriorityQueue {
    int size;
    int capacity;
    struct PQNode *nodes;
};

// Function to create a new Priority Queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue *queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->nodes = (struct PQNode*)malloc(sizeof(struct PQNode) * capacity);
    return queue;
}

// Function to swap two nodes in the Priority Queue
void swap(struct PQNode *node1, struct PQNode *node2) {
    struct PQNode temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// Function to get the index of the parent node
int parent(int index) {
    return (index - 1) / 2;
}

// Function to get the index of the left child node
int leftChild(int index) {
    return 2 * index + 1;
}

// Function to get the index of the right child node
int rightChild(int index) {
    return 2 * index + 2;
}

// Function to check if the Priority Queue is empty
int isEmpty(struct PriorityQueue *queue) {
    return queue->size == 0;
}

// Function to check if the Priority Queue is full
int isFull(struct PriorityQueue *queue) {
    return queue->size == queue->capacity;
}

// Function to add a new node to the Priority Queue
void enqueue(struct PriorityQueue *queue, struct PQNode node) {
    if (isFull(queue)) {
        printf("Priority Queue is full.\n");
        return;
    }
    int index = queue->size;
    queue->nodes[index] = node;
    queue->size++;
    while (index != 0 && queue->nodes[index].priority < queue->nodes[parent(index)].priority) {
        swap(&queue->nodes[index], &queue->nodes[parent(index)]);
        index = parent(index);
    }
}

// Function to remove the node with the highest priority from the Priority Queue
struct PQNode dequeue(struct PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty.\n");
        return (struct PQNode){-1, {-1, -1}};
    }
    struct PQNode rootNode = queue->nodes[0];
    queue->size--;
    queue->nodes[0] = queue->nodes[queue->size];
    int index = 0;
    while (leftChild(index) < queue->size) {
        int minChild = leftChild(index);
        if (rightChild(index) < queue->size && queue->nodes[rightChild(index)].priority < queue->nodes[minChild].priority) {
            minChild = rightChild(index);
        }
        if (queue->nodes[index].priority > queue->nodes[minChild].priority) {
            swap(&queue->nodes[index], &queue->nodes[minChild]);
            index = minChild;
        } else {
            break;
        }
    }
    return rootNode;
}

// Function to check if the given point is valid
int isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < ROWS && y < COLS;
}

// Function to calculate the Manhattan distance between two points
int manhattanDistance(struct Point a, struct Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Function to find the shortest path using the A* algorithm
void astar(int map[ROWS][COLS], struct Point start, struct Point goal) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int distanceFromStart[ROWS][COLS];
    int distanceToGoal[ROWS][COLS];
    int visited[ROWS][COLS];
    int parentX[ROWS][COLS];
    int parentY[ROWS][COLS];
    struct PriorityQueue *queue = createPriorityQueue(ROWS * COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            distanceFromStart[i][j] = -1;
            distanceToGoal[i][j] = -1;
            visited[i][j] = 0;
        }
    }
    distanceFromStart[start.x][start.y] = 0;
    distanceToGoal[start.x][start.y] = manhattanDistance(start, goal);
    struct PQNode startNode = {distanceFromStart[start.x][start.y] + distanceToGoal[start.x][start.y], start};
    enqueue(queue, startNode);
    while (!isEmpty(queue)) {
        struct PQNode current = dequeue(queue);
        int currentX = current.point.x;
        int currentY = current.point.y;
        if (current.point.x == goal.x && current.point.y == goal.y) {
            break;
        }
        visited[currentX][currentY] = 1;
        for (int i = 0; i < 4; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];
            if (isValid(nextX, nextY) && map[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                int tentativeDistanceFromStart = distanceFromStart[currentX][currentY] + 1;
                if (distanceFromStart[nextX][nextY] == -1 || tentativeDistanceFromStart < distanceFromStart[nextX][nextY]) {
                    distanceFromStart[nextX][nextY] = tentativeDistanceFromStart;
                    distanceToGoal[nextX][nextY] = manhattanDistance((struct Point){nextX, nextY}, goal);
                    parentX[nextX][nextY] = currentX;
                    parentY[nextX][nextY] = currentY;
                    struct PQNode nextNode = {tentativeDistanceFromStart + distanceToGoal[nextX][nextY], (struct Point){nextX, nextY}};
                    enqueue(queue, nextNode);
                }
            }
        }
    }
    if (distanceFromStart[goal.x][goal.y] == -1) {
        printf("No path found.\n");
    } else {
        printf("Shortest path length: %d\n", distanceFromStart[goal.x][goal.y]);
        printf("Shortest path: ");
        int x = goal.x;
        int y = goal.y;
        while (x != start.x || y != start.y) {
            printf("(%d, %d) ", x, y);
            int parentX_ = parentX[x][y];
            int parentY_ = parentY[x][y];
            x = parentX_;
            y = parentY_;
        }
        printf("(%d, %d)\n", start.x, start.y);
    }
}

int main() {
    int map[ROWS][COLS] = {
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
            {1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 1, 0, 1, 1, 1},
            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 1, 1, 1, 1, 0}
    };
    struct Point start = {0, 0};
    struct Point goal = {9, 9};
    astar(map, start, goal);
    return 0;
}