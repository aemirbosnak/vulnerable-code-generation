//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#define Q_TYPE int
#define Q_SIZE 7
#define TRUE 1
#define FALSE 0

typedef struct {
    Q_TYPE data[Q_SIZE];
    int head;
    int tail;
} CircularQueue;

CircularQueue *createQueue() {
    CircularQueue *queue = (CircularQueue *) malloc(sizeof(CircularQueue));
    queue->head = -1;
    queue->tail = -1;
    return queue;
}

int isFull(CircularQueue *queue) {
    if ((queue->head + 1) % Q_SIZE == queue->tail || queue->head == queue->tail)
        return TRUE;
    else
        return FALSE;
}

int isEmpty(CircularQueue *queue) {
    if (queue->head == -1 && queue->tail == -1)
        return TRUE;
    else
        return FALSE;
}

void enqueue(CircularQueue *queue, Q_TYPE data) {
    if (isFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->head = 0;
        queue->tail = 0;
    }
    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % Q_SIZE;
}

Q_TYPE dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    Q_TYPE data = queue->data[queue->head];
    queue->head = (queue->head + 1) % Q_SIZE;
    if (queue->head == queue->tail) {
        queue->head = queue->tail = -1;
    }
    return data;
}

int main() {
    CircularQueue *queue = createQueue();
    int i;
    for (i = 0; i < Q_SIZE; i++) {
        enqueue(queue, i);
        printf("Enqueued %d\n", i);
    }
    printf("Queue Full!\n");
    for (i = 0; i < Q_SIZE; i++) {
        printf("Dequeued %d\n", dequeue(queue));
    }
    printf("Queue Empty!\n");
    free(queue);
    return 0;
}