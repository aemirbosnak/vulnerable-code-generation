//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 10
#define COL 10

// node structure
struct Node {
    int row;
    int col;
    int distance;
    int parent_row;
    int parent_col;
};

// queue struct for BFS
struct Queue {
    int front;
    int rear;
    int size;
    struct Node* nodes[ROW * COL];
};

// global variable for visited cells
int visited[ROW][COL];

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Check if queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Check if queue is full
bool isFull(struct Queue* queue) {
    return queue->size == ROW*COL;
}

// Add item to queue
void enqueue(struct Node* node, struct Queue* queue) {
    if(isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear+1) % (ROW * COL);
    queue->nodes[queue->rear] = node;
    queue->size++;
    if(queue->front == -1) {
        queue->front = queue->rear;
    }
}

// Remove item from queue
struct Node* dequeue(struct Queue* queue) {
    if(isEmpty(queue)) {
        return NULL;
    }
    struct Node* node = queue->nodes[queue->front];
    queue->front = (queue->front+1) % (ROW * COL);
    queue->size--;
    return node;
}

// Check if curr cell is valid
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && visited[row][col] == 0;
}

// Check if curr cell is the destination
bool isDestination(int row, int col, int dest_row, int dest_col) {
    return (row == dest_row) && (col == dest_col);
}

// Print the path found
void printPath(struct Node* node, int map[ROW][COL]) {
    int count = 0;
    while(node != NULL) {
        printf("(%d, %d) ", node->row, node->col);
        map[node->row][node->col] = count; // mark the path on map
        count++;
        node = (struct Node*) malloc(sizeof(struct Node));
        node->row = node->parent_row;
        node->col = node->parent_col;
    }
}

// Function to find shortest path to destination using BFS
void BFS(int map[ROW][COL], int src_row, int src_col, int dest_row, int dest_col) {
    if(src_row == dest_row && src_col == dest_col) {
        printf("The source is the destination\n");
        return;
    }
    struct Queue* queue = createQueue();
    struct Node* src_node = (struct Node*) malloc(sizeof(struct Node));
    src_node->row = src_row;
    src_node->col = src_col;
    src_node->distance = 0;
    src_node->parent_row = -1;
    src_node->parent_col = -1;
    visited[src_row][src_col] = 1;
    enqueue(src_node, queue);

    // BFS start
    while(!isEmpty(queue)) {
        struct Node* curr_node = dequeue(queue);
        int curr_row = curr_node->row;
        int curr_col = curr_node->col;
        int curr_distance = curr_node->distance;

        // check if curr cell is the destination cell
        if(isDestination(curr_row, curr_col, dest_row, dest_col)) {
            printPath(curr_node, map);
            printf("\nThe shortest path is: %d", curr_distance);
            return;
        }

        // check for all reachable neighbors
        int row_dist[] = {-1, 0, 0, 1};
        int col_dist[] = {0, -1, 1, 0};
        for(int i=0; i<4; i++) {
            int neighbor_row = curr_row + row_dist[i];
            int neighbor_col = curr_col + col_dist[i];
            if(isValid(neighbor_row, neighbor_col)) {
                visited[neighbor_row][neighbor_col] = 1;
                struct Node* neighbor_node = (struct Node*) malloc(sizeof(struct Node));
                neighbor_node->row = neighbor_row;
                neighbor_node->col = neighbor_col;
                neighbor_node->parent_row = curr_row;
                neighbor_node->parent_col = curr_col;
                neighbor_node->distance = curr_distance + 1;
                enqueue(neighbor_node, queue);
            }
        }
    }

    // print message if path is not found
    printf("No path found from source to destination\n");
    return;
}

// Driver function
int main() {
    int map[ROW][COL] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        { 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        { 1, 1, 0, 1, 1, 0, 0, 0, 1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int src_row = 0, src_col = 0;
    int dest_row = 9, dest_col = 9;
    BFS(map, src_row, src_col, dest_row, dest_col);
    printf("\nThe map is:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}