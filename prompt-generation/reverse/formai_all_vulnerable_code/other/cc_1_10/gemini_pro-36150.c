//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Say what?! A queue implemented with a linked list?!
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// You won't believe this! A queue with a head and a tail!
struct Queue {
    struct QueueNode* head;
    struct QueueNode* tail;
};

// We're serious! Let's create a new queue.
struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Are you kidding me?! Enqueueing an element!
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->tail) {
        queue->tail->next = newNode;
    } else {
        queue->head = newNode;
    }
    queue->tail = newNode;
}

// You're pulling my leg! Dequeueing an element!
int dequeue(struct Queue* queue) {
    assert(!isEmpty(queue));  // Oops, you can't dequeue from an empty queue!
    struct QueueNode* oldHead = queue->head;
    int data = oldHead->data;
    queue->head = oldHead->next;
    if (!queue->head) {
        queue->tail = NULL;  // Don't forget about your tail!
    }
    free(oldHead);
    return data;
}

// No way, José! Checking if the queue is empty!
int isEmpty(struct Queue* queue) {
    return !queue->head;
}

// Wow, that's awesome! Displaying all the elements in the queue!
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    struct QueueNode* current = queue->head;
    printf("Elements in the queue: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Are you kidding me?! A main function to test the queue!
int main() {
    // Oh, come on! We're really creating a queue!
    struct Queue* queue = createQueue();
    // Stop it! You're enqueueing elements!
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    // Hold your horses! You're displaying the elements!
    printf("Initial queue: ");
    displayQueue(queue);
    // You're not serious! You're dequeueing an element!
    printf("Dequeueing an element: %d\n", dequeue(queue));
    // Oh my goodness! You're displaying the elements again!
    printf("Queue after dequeue: ");
    displayQueue(queue);
    // But wait, there's more! You're enqueueing another element!
    enqueue(queue, 4);
    // You can't believe it! You're displaying the elements again!
    printf("Queue after enqueue: ");
    displayQueue(queue);
    // And finally, you're checking if the queue is empty!
    printf("Is the queue empty? %d\n", isEmpty(queue));
    return 0;
}