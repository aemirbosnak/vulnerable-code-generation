//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A kingdom is a queue of peasants
struct Kingdom {
    int *peasant;
    int front, rear, capacity;
};

// Creates a kingdom with a capacity of `capacity` peasants
struct Kingdom *createKingdom(int capacity) {
    struct Kingdom *kingdom = (struct Kingdom *) malloc(sizeof(struct Kingdom));
    kingdom->peasant = (int *) malloc(capacity * sizeof(int));
    kingdom->front = kingdom->rear = -1;
    kingdom->capacity = capacity;
    return kingdom;
}

// Adds a peasant to the end of the queue
void enqueue(struct Kingdom *kingdom, int peasant) {
    if (kingdom->rear == kingdom->capacity - 1) {
        printf("The kingdom is full!\n");
        return;
    }

    if (kingdom->front == -1) {
        kingdom->front = kingdom->rear = 0;
    } else {
        kingdom->rear++;
    }

    kingdom->peasant[kingdom->rear] = peasant;
}

// Removes the first peasant from the queue
int dequeue(struct Kingdom *kingdom) {
    if (kingdom->front == -1) {
        printf("The kingdom is empty!\n");
        return -1;
    }

    int peasant = kingdom->peasant[kingdom->front];
    kingdom->front++;

    if (kingdom->front > kingdom->rear) {
        kingdom->front = kingdom->rear = -1;
    }

    return peasant;
}

// Returns the first peasant in the queue without removing it
int peek(struct Kingdom *kingdom) {
    if (kingdom->front == -1) {
        printf("The kingdom is empty!\n");
        return -1;
    }

    return kingdom->peasant[kingdom->front];
}

// Returns the number of peasants in the queue
int size(struct Kingdom *kingdom) {
    if (kingdom->front == -1) {
        return 0;
    }

    return kingdom->rear - kingdom->front + 1;
}

// Prints the peasants in the queue
void printKingdom(struct Kingdom *kingdom) {
    if (kingdom->front == -1) {
        printf("The kingdom is empty!\n");
        return;
    }

    for (int i = kingdom->front; i <= kingdom->rear; i++) {
        printf("%d ", kingdom->peasant[i]);
    }

    printf("\n");
}

// Frees the memory allocated for the kingdom
void destroyKingdom(struct Kingdom *kingdom) {
    free(kingdom->peasant);
    free(kingdom);
}

int main() {
    srand(time(NULL));

    // Create a kingdom with a capacity of 10 peasants
    struct Kingdom *kingdom = createKingdom(10);

    // Add 5 peasants to the kingdom
    for (int i = 0; i < 5; i++) {
        enqueue(kingdom, rand() % 100);
    }

    // Print the peasants in the kingdom
    printKingdom(kingdom);

    // Remove 2 peasants from the kingdom
    for (int i = 0; i < 2; i++) {
        dequeue(kingdom);
    }

    // Print the peasants in the kingdom
    printKingdom(kingdom);

    // Add 3 peasants to the kingdom
    for (int i = 0; i < 3; i++) {
        enqueue(kingdom, rand() % 100);
    }

    // Print the peasants in the kingdom
    printKingdom(kingdom);

    // Destroy the kingdom
    destroyKingdom(kingdom);

    return 0;
}