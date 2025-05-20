//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

// Create a structure to hold the coordinates of the cell
typedef struct {
    int x;
    int y;
} Point;

// Create a structure for the node in the pathfinding queue
typedef struct Node {
    Point pt;       // Current cell coordinates
    int dist;      // Distance from the start
    struct Node* parent; // Store parent node for path reconstruction
} Node;

// Queue for BFS
typedef struct {
    Node* arr[ROW * COL];
    int front;
    int rear;
} Queue;

// Initialize queue functions
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

bool isFull(Queue* queue) {
    return queue->rear == ROW * COL;
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, Node* node) {
    if (!isFull(queue)) {
        queue->arr[queue->rear++] = node;
    }
}

Node* dequeue(Queue* queue) {
    if (!isEmpty(queue)) {
        return queue->arr[queue->front++];
    }
    return NULL;
}

// Check if the given cell is within the bounds and not blocked
bool isSafe(int maze[ROW][COL], int row, int col) {
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL) &&
           (maze[row][col] == 1);
}

// BFS Algorithm to find the shortest path
void bfs(int maze[ROW][COL], Point start, Point end) {
    // Directions arrays for moving up, down, left, right
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    // Create a queue for BFS and initialize it
    Queue queue;
    initQueue(&queue);

    // Create an array to track visited cells
    bool visited[ROW][COL] = {false};
    visited[start.x][start.y] = true;

    // Create the initial node and enqueue it
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->pt = start;
    startNode->dist = 0;
    startNode->parent = NULL;
    enqueue(&queue, startNode);

    while (!isEmpty(&queue)) {
        Node* current = dequeue(&queue);

        // If the destination is reached, print the path
        if (current->pt.x == end.x && current->pt.y == end.y) {
            printf("Shortest Path Distance: %d\n", current->dist);
            Node* temp = current;
            printf("Path: ");
            while (temp) {
                printf("-> (%d, %d) ", temp->pt.x, temp->pt.y);
                temp = temp->parent;
            }
            printf("\n");
            return;
        }

        // Explore all four possible movements
        for (int i = 0; i < 4; i++) {
            int row = current->pt.x + rowNum[i];
            int col = current->pt.y + colNum[i];

            if (isSafe(maze, row, col) && !visited[row][col]) {
                visited[row][col] = true;
                
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->pt = (Point){row, col};
                newNode->dist = current->dist + 1;
                newNode->parent = current; // Link to parent
                enqueue(&queue, newNode);
            }
        }
    }
    printf("No path found!\n");
}

int main() {
    // Define a maze with 1's as paths and 0's as obstacles
    int maze[ROW][COL] = {
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1}
    };

    Point start = {0, 0}; // Starting point
    Point end = {8, 9};   // Destination point

    bfs(maze, start, end);

    return 0;
}