//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = size;
    queue->front = queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    return item;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);
    int ch, item;
    do {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter element to insert: ");
                    scanf("%d", &item);
                    enqueue(queue, item);
                    break;
            case 2: item = dequeue(queue);
                    if (item != -1) {
                        printf("Deleted item: %d\n", item);
                    }
                    break;
            case 3: display(queue);
                    break;
            case 4: printf("Exiting..\n");
                    exit(0);
                    break;
            default: printf("Invalid choice!\n");
                     break;
        }
    } while(ch != 4);
    return 0;
}