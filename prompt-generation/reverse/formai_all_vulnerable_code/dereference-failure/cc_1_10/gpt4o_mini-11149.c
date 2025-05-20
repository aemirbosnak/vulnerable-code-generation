//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 5
#define COL 5

// Structure for the queue node
typedef struct Node {
    int x, y;
    int distance;
    struct Node* next;
} Node;

// Queue structure for BFS
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int x, int y, int dist);
Node* dequeue(Queue* q);
bool isEmpty(Queue* q);
bool isValid(int row, int col);
void printPath(int distance[ROW][COL], int endX, int endY);
void bfs(int grid[ROW][COL], int startX, int startY, int endX, int endY);

// Main function
int main() {
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int startX = 0, startY = 0; // Start position
    int endX = 4, endY = 4;     // End position

    bfs(grid, startX, startY, endX, endY);

    return 0;
}

// Create queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(Queue* q, int x, int y, int dist) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    temp->distance = dist;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }

    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    return temp;
}

// Check if queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Check if a cell is valid
bool isValid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// Print the path found
void printPath(int distance[ROW][COL], int endX, int endY) {
    if (distance[endX][endY] == -1) {
        printf("No path found.\n");
        return;
    }
    
    printf("Shortest path length is %d\n", distance[endX][endY]);
}

// BFS function
void bfs(int grid[ROW][COL], int startX, int startY, int endX, int endY) {
    int distance[ROW][COL];
    memset(distance, -1, sizeof(distance)); // Initialize distances as -1

    Queue* q = createQueue();
    enqueue(q, startX, startY, 0);
    distance[startX][startY] = 0;

    // Directions for moving up, down, left, right
    int rowDir[] = {-1, 1, 0, 0};
    int colDir[] = {0, 0, -1, 1};

    while (!isEmpty(q)) {
        Node* node = dequeue(q);
        int x = node->x;
        int y = node->y;

        // Check if we reached the destination
        if (x == endX && y == endY) {
            printPath(distance, endX, endY);
            free(node);
            break;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = x + rowDir[i];
            int newY = y + colDir[i];

            if (isValid(newX, newY) && grid[newX][newY] == 0 && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[x][y] + 1;
                enqueue(q, newX, newY, distance[newX][newY]);
            }
        }
        free(node); // Free memory for the node
    }

    while (!isEmpty(q)) {
        free(dequeue(q)); // Free remaining nodes
    }
    free(q); // Free the queue
}