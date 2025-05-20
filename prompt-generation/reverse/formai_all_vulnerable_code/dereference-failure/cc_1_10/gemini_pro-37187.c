//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// A surreal queue.
//
// This code implements a queue in the surrealist style, which will be quite
// confusing and difficult to understand.
//
// For those who are not familiar with surrealism, it is an art movement that
// emerged in the early 20th century and is characterized by the use of
// unexpected juxtapositions and non-sequiturs.
//
// The surrealist queue is implemented using a linked list, but the list is
// manipulated in a non-standard way. The head of the queue is always the
// last element in the list, and the tail of the queue is always the first
// element in the list.
//
// To enqueue an item, we create a new node and add it to the end of the list.
// To dequeue an item, we remove the first node from the list and return its
// value.
//
// This implementation is not efficient, but it is surreal.

// A surreal node.
//
// This struct represents a node in the surreal queue. Each node has a value
// and a pointer to the next node in the list.
//
// The next pointer is stored in the "prev" field, because in the surrealist
// queue, the next node is actually the previous node.
typedef struct surreal_node {
    int value;
    struct surreal_node *prev;
} surreal_node;

// A surreal queue.
//
// This struct represents a surreal queue. It contains a pointer to the head
// of the queue and a pointer to the tail of the queue.
typedef struct surreal_queue {
    surreal_node *head;
    surreal_node *tail;
} surreal_queue;

// Create a new surreal queue.
//
// This function allocates memory for a new surreal queue and initializes its
// head and tail pointers to NULL.
surreal_queue *surreal_queue_create() {
    surreal_queue *queue = malloc(sizeof(surreal_queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Destroy a surreal queue.
//
// This function frees the memory associated with a surreal queue. It also
// frees the memory associated with all of the nodes in the queue.
void surreal_queue_destroy(surreal_queue *queue) {
    surreal_node *node = queue->head;
    while (node != NULL) {
        surreal_node *next_node = node->prev;
        free(node);
        node = next_node;
    }
    free(queue);
}

// Enqueue an item into a surreal queue.
//
// This function adds an item to the end of a surreal queue. The item is
// stored in a new node, which is added to the end of the list.
void surreal_queue_enqueue(surreal_queue *queue, int value) {
    surreal_node *new_node = malloc(sizeof(surreal_node));
    new_node->value = value;
    new_node->prev = queue->head;
    queue->head = new_node;
    if (queue->tail == NULL) {
        queue->tail = new_node;
    }
}

// Dequeue an item from a surreal queue.
//
// This function removes the first item from a surreal queue and returns its
// value. The first node in the list is removed, and its value is returned.
int surreal_queue_dequeue(surreal_queue *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    surreal_node *node = queue->tail;
    queue->tail = node->prev;
    if (queue->tail == NULL) {
        queue->head = NULL;
    }
    int value = node->value;
    free(node);
    return value;
}

// Print a surreal queue.
//
// This function prints the contents of a surreal queue to the standard output.
// The queue is printed in reverse order, with the first item in the queue
// being printed last.
void surreal_queue_print(surreal_queue *queue) {
    surreal_node *node = queue->tail;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->prev;
    }
    printf("\n");
}

// Test the surreal queue implementation.
int main() {
    surreal_queue *queue = surreal_queue_create();
    surreal_queue_enqueue(queue, 1);
    surreal_queue_enqueue(queue, 2);
    surreal_queue_enqueue(queue, 3);
    surreal_queue_print(queue);
    printf("%d\n", surreal_queue_dequeue(queue));
    printf("%d\n", surreal_queue_dequeue(queue));
    printf("%d\n", surreal_queue_dequeue(queue));
    surreal_queue_destroy(queue);
    return 0;
}