//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 8

// Define a structure for a node in the queue
typedef struct queueNode {
    int row;
    int col;
    struct queueNode* next;
} QueueNode;

// Define a structure for the queue
typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to check if a given coordinate is valid
int is_valid(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROWS && col < COLS);
}

// Function to check if a given coordinate is blocked or not
int is_blocked(int maze[ROWS][COLS], int row, int col) {
    return (maze[row][col] == 1);
}

// Function to initialize a queue
void init_queue(Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if a queue is empty
int is_empty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to add a node to the rear of the queue
void enqueue(Queue* q, int row, int col) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove a node from the front of the queue
void dequeue(Queue* q, int* row, int* col) {
    if (is_empty(q)) {
        return;
    }
    QueueNode* temp = q->front;
    *row = temp->row;
    *col = temp->col;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Function to find the shortest path through the maze
void find_shortest_path(int maze[ROWS][COLS], int start_row, int start_col,
                        int end_row, int end_col, int* path_len, int path[ROWS*COLS][2]) {
    // Create an array to keep track of visited nodes
    int visited[ROWS][COLS] = {{0}};
    visited[start_row][start_col] = 1;

    // Create a queue to hold the nodes to be visited
    Queue q;
    init_queue(&q);
    enqueue(&q, start_row, start_col);

    // Create arrays to hold the parent of each node and the distance from the start
    int parent[ROWS][COLS][2] = {{{0}}};
    int distance[ROWS][COLS] = {{0}};

    // Loop until we reach the end or there are no more nodes to visit
    int row, col, next_row, next_col;
    while (!is_empty(&q)) {
        dequeue(&q, &row, &col);
        if (row == end_row && col == end_col) {
            break;
        }
        // Check the neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 && j == 0) || (i != 0 && j != 0)) {
                    continue;
                }
                next_row = row + i;
                next_col = col + j;
                if (is_valid(next_row, next_col) && !is_blocked(maze, next_row, next_col) &&
                    !visited[next_row][next_col]) {
                    visited[next_row][next_col] = 1;
                    parent[next_row][next_col][0] = row;
                    parent[next_row][next_col][1] = col;
                    distance[next_row][next_col] = distance[row][col] + 1;
                    enqueue(&q, next_row, next_col);
                }
            }
        }
    }

    // Construct the path using the parent array
    int curr_row = end_row;
    int curr_col = end_col;
    int index = 0;
    path[index][0] = curr_row;
    path[index][1] = curr_col;
    index++;
    while (curr_row != start_row || curr_col != start_col) {
        int temp_row = parent[curr_row][curr_col][0];
        curr_col = parent[curr_row][curr_col][1];
        curr_row = temp_row;
        path[index][0] = curr_row;
        path[index][1] = curr_col;
        index++;
    }

    // Reverse the path
    int temp[2];
    for (int i = 0; i < index/2; i++) {
        temp[0] = path[i][0];
        temp[1] = path[i][1];
        path[i][0] = path[index-1-i][0];
        path[i][1] = path[index-1-i][1];
        path[index-1-i][0] = temp[0];
        path[index-1-i][1] = temp[1];
    }

    *path_len = index;
}

int main() {
    // Define the maze
    int maze[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
    };

    // Define the start and end points
    int start_row = 0;
    int start_col = 0;
    int end_row = 5;
    int end_col = 7;

    // Find the shortest path
    int path_len;
    int path[ROWS*COLS][2];
    find_shortest_path(maze, start_row, start_col, end_row, end_col, &path_len, path);

    // Print the path
    printf("Shortest path from (%d, %d) to (%d, %d):\n", start_row, start_col, end_row, end_col);
    for (int i = 0; i < path_len; i++) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");

    return 0;
}