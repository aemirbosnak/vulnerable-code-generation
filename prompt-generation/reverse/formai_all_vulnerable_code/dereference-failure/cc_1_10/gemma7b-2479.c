//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* queue, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

char dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    char data = queue->head->data;
    queue->head = queue->head->next;

    return data;
}

int main() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    char message[MAX_BUFFER_SIZE];
    printf("Enter a message: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);

    // Split the message into words and enqueue each word into the queue
    char* word = strtok(message, " ");
    while (word) {
        enqueue(queue, word[0]);
        word = strtok(NULL, " ");
    }

    // Print the words in the queue
    printf("Words in the queue:");
    for (Node* node = queue->head; node; node = node->next) {
        printf(" %c", node->data);
    }

    // Dequeue words from the queue and print them
    printf("\nWords dequeued:");
    char data = dequeue(queue);
    while (data != -1) {
        printf(" %c", data);
        data = dequeue(queue);
    }

    free(queue);
    return 0;
}