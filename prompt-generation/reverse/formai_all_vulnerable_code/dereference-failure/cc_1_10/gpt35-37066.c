//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Define the width and height of the grid
#define WIDTH 10
#define HEIGHT 10

// Define the starting and ending points
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Initialize the grid as a 2D array of integers
int grid[WIDTH][HEIGHT] = {
    {0,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// Define a struct to represent a single node in the grid
struct Node {
    int x;
    int y;
    int distance;
    struct Node* parent;
};

// Create a global variable for the final path
struct Node* finalPath;

// Create a pthread_mutex_t to handle concurrent access to the final path variable
pthread_mutex_t finalPathLock = PTHREAD_MUTEX_INITIALIZER;

// Define a function to check if a given node is valid (i.e. not in a wall or outside the bounds of the grid)
bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
        return false;
    } else if (grid[x][y] == 1) {
        return false;
    } else {
        return true;
    }
}

// Define a helper function to add a neighbor to the queue
void addToQueue(struct Node** queue, int* queueTail, struct Node* node) {
    queue[*queueTail] = node;
    *queueTail += 1;
}

// Define the asynchronous breadth-first search function
void* bfsAsync(void* arg) {
    // Obtain the arguments passed to the function
    struct Node* start = (struct Node*) arg;
    
    // Create a queue to hold nodes to visit
    struct Node* queue[WIDTH * HEIGHT];
    int queueHead = 0;
    int queueTail = 0;
    
    // Enqueue the starting node
    addToQueue(queue, &queueTail, start);
    
    // Process the queue until it is empty or the final node is found
    while (queueHead < queueTail && finalPath == NULL) {
        // Dequeue the next node
        struct Node* curr = queue[queueHead];
        queueHead += 1;
        
        // Stop processing if the final node is found
        if (curr->x == END_X && curr->y == END_Y) {
            pthread_mutex_lock(&finalPathLock);
            finalPath = curr;
            pthread_mutex_unlock(&finalPathLock);
            break;
        }
        
        // Check each of the neighbors
        if (isValid(curr->x + 1, curr->y)) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->x = curr->x + 1;
            newNode->y = curr->y;
            newNode->distance = curr->distance + 1;
            newNode->parent = curr;
            addToQueue(queue, &queueTail, newNode);
        }
        if (isValid(curr->x, curr->y + 1)) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->x = curr->x;
            newNode->y = curr->y + 1;
            newNode->distance = curr->distance + 1;
            newNode->parent = curr;
            addToQueue(queue, &queueTail, newNode);
        }
        if (isValid(curr->x - 1, curr->y)) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->x = curr->x - 1;
            newNode->y = curr->y;
            newNode->distance = curr->distance + 1;
            newNode->parent = curr;
            addToQueue(queue, &queueTail, newNode);
        }
        if (isValid(curr->x, curr->y - 1)) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->x = curr->x;
            newNode->y = curr->y - 1;
            newNode->distance = curr->distance + 1;
            newNode->parent = curr;
            addToQueue(queue, &queueTail, newNode);
        }
        
        // Sleep for a short time to simulate processing complexity
        usleep(1000);
    }
    
    // Free all of the allocated nodes
    for (int i = queueHead; i < queueTail; i++) {
        free(queue[i]);
    }
    
    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Initialize the start and end nodes
    struct Node start;
    start.x = START_X;
    start.y = START_Y;
    start.distance = 0;
    start.parent = NULL;
    
    struct Node end;
    end.x = END_X;
    end.y = END_Y;
    end.distance = -1;
    end.parent = NULL;
    
    // Create two threads to perform the search
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, bfsAsync, (void*) &start);
    pthread_create(&thread2, NULL, bfsAsync, (void*) &end);
    
    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Verify that a path was found
    if (finalPath == NULL) {
        printf("No path found.\n");
        return 0;
    }
    
    // Print the final path
    struct Node* node = finalPath;
    while (node != NULL) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
    
    // Free the final path node and exit
    free(finalPath);
    return 0;
}