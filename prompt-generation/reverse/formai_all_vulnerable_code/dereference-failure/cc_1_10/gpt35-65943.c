//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10

// Define the queue struct to hold player IDs
typedef struct Queue {
    int front, rear, size;
    int players[MAX_PLAYERS];
} Queue;

// Function prototypes
Queue* createQueue();
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int playerID);
int dequeue(Queue* queue);
void printQueue(Queue* queue);

int main() {
    // Create a new queue
    Queue* lobbyQueue = createQueue();

    // Simulate players joining the queue
    enqueue(lobbyQueue, 1);
    enqueue(lobbyQueue, 2);
    enqueue(lobbyQueue, 3);
    enqueue(lobbyQueue, 4);
    printf("Players in queue: ");
    printQueue(lobbyQueue);

    // Simulate players leaving the queue
    int player1 = dequeue(lobbyQueue);
    int player2 = dequeue(lobbyQueue);
    printf("\nPlayer %d and Player %d joined the game.\n", player1, player2);
    printf("Players in queue: ");
    printQueue(lobbyQueue);

    // Simulate more players joining the queue
    enqueue(lobbyQueue, 5);
    enqueue(lobbyQueue, 6);
    printf("\nTwo more players joined the queue.\n");
    printf("Players in queue: ");
    printQueue(lobbyQueue);

    return 0;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = MAX_PLAYERS - 1; // Initialize rear to last index of array
    queue->size = 0;
    return queue;
}

// Function to check if queue is full
int isFull(Queue* queue) {
    return queue->size == MAX_PLAYERS;
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add a player to the queue
void enqueue(Queue* queue, int playerID) {
    if (isFull(queue)) {
        printf("\nQueue is full, cannot add player %d.\n", playerID);
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_PLAYERS; // Circular increment rear
    queue->players[queue->rear] = playerID;
    queue->size++;
}

// Function to remove a player from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is empty, cannot remove player.\n");
        return -1;
    }
    int playerID = queue->players[queue->front];
    queue->front = (queue->front + 1) % MAX_PLAYERS; // Circular increment front
    queue->size--;
    return playerID;
}

// Function to print the players in the queue
void printQueue(Queue* queue) {
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % MAX_PLAYERS; // Calculate actual index in array
        printf("%d ", queue->players[index]);
    }
    printf("\n");
}