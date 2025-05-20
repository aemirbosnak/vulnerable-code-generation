//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the size of the grid
#define ROW_SIZE 6
#define COL_SIZE 7

// Define the node structure
typedef struct node {
    int row, col;
    struct node *parent;
} Node;

// Define the queue structure
typedef struct queue {
    int size;
    int front, rear;
    Node **array;
} Queue;

// Define the array to hold the grid
int grid[ROW_SIZE][COL_SIZE] = {
    { 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 0 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 0, 1, 1 }
};

// Define the queue functions
Queue *createQueue(int size) {
    Queue *queue = malloc(sizeof(Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->array = malloc(size * sizeof(Node *));
    int i;
    for (i = 0; i < size; i++) {
        queue->array[i] = NULL;
    }
    return queue;
}

void enqueue(Queue *queue, Node *node) {
    if (queue->front == -1 && queue->rear == -1) {
        queue->front = 0;
        queue->rear = 0;
        queue->array[0] = node;
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = node;
}

Node *dequeue(Queue *queue) {
    Node *node = queue->array[queue->front];
    queue->front++;
    return node;
}

int isEmpty(Queue *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        return 1;
    } else {
        return 0;
    }
}

// Define the pathfinding function
Node *findPath(int startRow, int startCol, int goalRow, int goalCol) {
    // Create the start node
    Node *start = malloc(sizeof(Node));
    start->row = startRow;
    start->col = startCol;
    start->parent = NULL;
    
    // Create the goal node
    Node *goal = malloc(sizeof(Node));
    goal->row = goalRow;
    goal->col = goalCol;
    goal->parent = NULL;
    
    // Create the queue and add the start node
    Queue *queue = createQueue(ROW_SIZE * COL_SIZE);
    enqueue(queue, start);
    
    // Create the visited array
    int visited[ROW_SIZE][COL_SIZE];
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Loop through the queue until the goal node is found
    while (!isEmpty(queue)) {
        // Dequeue the next node
        Node *current = dequeue(queue);
        
        // Check if the current node is the goal node
        if (current->row == goalRow && current->col == goalCol) {
            return current;
        }
        
        // Check if the current node is already visited
        if (visited[current->row][current->col] == 1) {
            continue;
        }
        
        // Mark the current node as visited
        visited[current->row][current->col] = 1;
        
        // Add the adjacent nodes to the queue
        if (current->row > 0 && grid[current->row - 1][current->col] == 1) {
            Node *up = malloc(sizeof(Node));
            up->row = current->row - 1;
            up->col = current->col;
            up->parent = current;
            enqueue(queue, up);
        }
        if (current->row < ROW_SIZE - 1 && grid[current->row + 1][current->col] == 1) {
            Node *down = malloc(sizeof(Node));
            down->row = current->row + 1;
            down->col = current->col;
            down->parent = current;
            enqueue(queue, down);
        }
        if (current->col > 0 && grid[current->row][current->col - 1] == 1) {
            Node *left = malloc(sizeof(Node));
            left->row = current->row;
            left->col = current->col - 1;
            left->parent = current;
            enqueue(queue, left);
        }
        if (current->col < COL_SIZE - 1 && grid[current->row][current->col + 1] == 1) {
            Node *right = malloc(sizeof(Node));
            right->row = current->row;
            right->col = current->col + 1;
            right->parent = current;
            enqueue(queue, right);
        }
    }
    
    // If the goal node is not found, return NULL
    return NULL;
}

// Define the main function
int main() {
    // Find the path from (0, 0) to (5, 6)
    Node *current = findPath(0, 0, 5, 6);
    
    // Print the path
    if (current != NULL) {
        printf("Path from (0, 0) to (5, 6):\n");
        while (current != NULL) {
            printf("(%d, %d)\n", current->row, current->col);
            current = current->parent;
        }
    } else {
        printf("Path not found.\n");
    }
    
    return 0;
}