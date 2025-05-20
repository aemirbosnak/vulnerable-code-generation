//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    int size;
};

void enqueue(struct Queue *q, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = q->head;
    q->head = newNode;
    q->size++;
}

int dequeue(struct Queue *q) {
    if (q->size == 0) {
        return -1;
    } else {
        struct Node *temp = q->head;
        q->head = q->head->next;
        q->size--;
        return temp->value;
    }
}

int isEmpty(struct Queue *q) {
    return q->size == 0;
}

int main() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->size = 0;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }

    free(queue);
    return 0;
}