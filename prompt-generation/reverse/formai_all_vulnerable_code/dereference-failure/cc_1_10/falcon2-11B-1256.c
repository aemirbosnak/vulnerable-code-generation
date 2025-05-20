//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>

struct Queue {
    int* arr;
    int size;
};

void createQueue(struct Queue* queue) {
    queue->arr = (int*)malloc(sizeof(int) * 10);
    queue->size = 10;
}

void addToQueue(struct Queue* queue, int num) {
    if (queue->size == 0) {
        queue->arr[0] = num;
        queue->size++;
        return;
    }

    for (int i = 0; i < queue->size; i++) {
        if (queue->arr[i] == 0) {
            queue->arr[i] = num;
            queue->size++;
            return;
        }
    }

    printf("Queue is full!\n");
}

int removeFromQueue(struct Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    int result = queue->arr[0];
    queue->arr[0] = 0;
    queue->size--;
    return result;
}

void displayQueue(struct Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    createQueue(&queue);
    addToQueue(&queue, 1);
    addToQueue(&queue, 2);
    addToQueue(&queue, 3);
    addToQueue(&queue, 4);
    addToQueue(&queue, 5);
    addToQueue(&queue, 6);
    addToQueue(&queue, 7);
    addToQueue(&queue, 8);
    addToQueue(&queue, 9);
    addToQueue(&queue, 10);

    int num = removeFromQueue(&queue);
    printf("Removed: %d\n", num);

    displayQueue(&queue);
    return 0;
}