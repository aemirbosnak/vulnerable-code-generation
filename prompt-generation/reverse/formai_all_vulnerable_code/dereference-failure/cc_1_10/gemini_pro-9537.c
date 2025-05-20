//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Cyberdeck
typedef struct Cyberdeck {
    int head;                        // The head of the queue
    int tail;                        // The tail of the queue
    int capacity;                    // The capacity of the queue
    char **data;                     // The data in the queue
} Cyberdeck;

// Initialize the Cyberdeck
Cyberdeck *init_cyberdeck(int capacity) {
    Cyberdeck *cyberdeck = malloc(sizeof(Cyberdeck));
    cyberdeck->head = 0;
    cyberdeck->tail = 0;
    cyberdeck->capacity = capacity;
    cyberdeck->data = malloc(sizeof(char *) * capacity);
    return cyberdeck;
}

// Enqueue an item onto the Cyberdeck
void enqueue_cyberdeck(Cyberdeck *cyberdeck, char *item) {
    cyberdeck->data[cyberdeck->tail] = item;
    cyberdeck->tail = (cyberdeck->tail + 1) % cyberdeck->capacity;
    if (cyberdeck->tail == cyberdeck->head) {
        printf("Cyberdeck is full!\n");
    }
}

// Dequeue an item from the Cyberdeck
char *dequeue_cyberdeck(Cyberdeck *cyberdeck) {
    if (cyberdeck->head == cyberdeck->tail) {
        printf("Cyberdeck is empty!\n");
        return NULL;
    }
    char *item = cyberdeck->data[cyberdeck->head];
    cyberdeck->head = (cyberdeck->head + 1) % cyberdeck->capacity;
    return item;
}

// Print the Cyberdeck
void print_cyberdeck(Cyberdeck *cyberdeck) {
    printf("Cyberdeck:\n");
    for (int i = cyberdeck->head; i != cyberdeck->tail; i = (i + 1) % cyberdeck->capacity) {
        printf("%s\n", cyberdeck->data[i]);
    }
}

// Destroy the Cyberdeck
void destroy_cyberdeck(Cyberdeck *cyberdeck) {
    free(cyberdeck->data);
    free(cyberdeck);
}

// Main function
int main() {
    // Initialize the Cyberdeck
    Cyberdeck *cyberdeck = init_cyberdeck(10);

    // Enqueue some items onto the Cyberdeck
    enqueue_cyberdeck(cyberdeck, "Neuromancer");
    enqueue_cyberdeck(cyberdeck, "Count Zero");
    enqueue_cyberdeck(cyberdeck, "Mona Lisa Overdrive");

    // Print the Cyberdeck
    print_cyberdeck(cyberdeck);

    // Dequeue some items from the Cyberdeck
    char *item = dequeue_cyberdeck(cyberdeck);
    printf("Dequeued: %s\n", item);
    item = dequeue_cyberdeck(cyberdeck);
    printf("Dequeued: %s\n", item);

    // Print the Cyberdeck
    print_cyberdeck(cyberdeck);

    // Destroy the Cyberdeck
    destroy_cyberdeck(cyberdeck);

    return 0;
}