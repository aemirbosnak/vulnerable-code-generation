//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// The kingdom of Queueistan is a majestic land, ruled by the wise King FIFO.
// In this realm, data flows smoothly in a first-in-first-out fashion.

// Our trusty steed, the Queue, is a noble construct that carries messages to and fro.
struct Queue {
    int *data;   // An array of integers, storing the messages
    int head;     // The position of the oldest message
    int tail;     // The position of the newest message
    int size;    // The maximum number of messages the Queue can hold
};

// To create a new Queue, we summon the mighty Queue constructor.
struct Queue *create_queue(int size) {
    // We allocate memory for the Queue and its data array.
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->data = malloc(sizeof(int) * size);

    // We initialize the Queue's head and tail to the start of the data array.
    queue->head = 0;
    queue->tail = 0;

    // We set the Queue's size to the specified value.
    queue->size = size;

    // And with a flourish, the Queue is born!
    return queue;
}

// To add a message to the Queue, we call upon the enqueue function.
void enqueue(struct Queue *queue, int message) {
    // We first check if the Queue is full. If it is, we return an error message.
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Error: Queue is full. Cannot enqueue message.\n");
        return;
    }

    // We add the message to the end of the data array.
    queue->data[queue->tail] = message;

    // We increment the tail to point to the next empty position.
    queue->tail = (queue->tail + 1) % queue->size;
}

// To retrieve a message from the Queue, we call upon the dequeue function.
int dequeue(struct Queue *queue) {
    // We first check if the Queue is empty. If it is, we return an error message.
    if (queue->head == queue->tail) {
        printf("Error: Queue is empty. Cannot dequeue message.\n");
        return -1;
    }

    // We retrieve the message from the front of the data array.
    int message = queue->data[queue->head];

    // We increment the head to point to the next message.
    queue->head = (queue->head + 1) % queue->size;

    // And with a flourish, the message is delivered!
    return message;
}

// To print the contents of the Queue, we call upon the print_queue function.
void print_queue(struct Queue *queue) {
    // We iterate over the data array, starting from the head.
    int i = queue->head;
    while (i != queue->tail) {
        // We print each message.
        printf("%d ", queue->data[i]);

        // We increment the index to point to the next message.
        i = (i + 1) % queue->size;
    }

    printf("\n");
}

// In the realm of Queueistan, there lived a humble farmer named Bob. Bob had a vast field of wheat, and he used a Queue to keep track of the number of bushels harvested each day.

int main() {
    // We create a Queue with a size of 10.
    struct Queue *queue = create_queue(10);

    // We enqueue the number of bushels harvested each day.
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // We print the contents of the Queue to see how many bushels Bob has harvested so far.
    printf("Bob's daily harvest:\n");
    print_queue(queue);

    // We dequeue the number of bushels harvested on the first day.
    int first_day_harvest = dequeue(queue);

    // We print the updated contents of the Queue to see how many bushels Bob has left.
    printf("Bob's remaining harvest:\n");
    print_queue(queue);

    // We free the memory allocated for the Queue and its data array.
    free(queue->data);
    free(queue);

    return 0;
}