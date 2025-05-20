//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

int isFull(Queue *queue) {
    Node *temp = queue->rear;
    while (temp!= NULL) {
        temp = temp->next;
    }
    return (temp == NULL);
}

void enqueue(Queue *queue, int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(queue)) {
        queue->front = temp;
        queue->rear = temp;
    }
    else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

int dequeue(Queue *queue) {
    int data;
    Node *temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    else if (queue->front == queue->rear) {
        data = queue->front->data;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        data = queue->front->data;
        queue->front = queue->front->next;
        free(temp);
    }
    return data;
}

void display(Queue *queue) {
    Node *temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue *queue = createQueue();
    int choice, data;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                printf("Dequeued element is: %d\n", data);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}