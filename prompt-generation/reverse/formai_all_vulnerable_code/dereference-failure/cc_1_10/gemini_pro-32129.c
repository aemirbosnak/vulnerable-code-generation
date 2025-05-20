//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: configurable
// Configurable Queue Implementation in C

// Define the maximum size of the queue
#define MAX_QUEUE_SIZE 100

// Define the type of data to be stored in the queue
typedef int data_type;

// Structure to represent a queue
struct Queue {
    data_type *items;  // Array to store the items in the queue
    int front;         // Index of the front item in the queue
    int rear;          // Index of the rear item in the queue
    int size;          // Size of the queue
};

// Function to create a new queue
struct Queue* createQueue(int size) {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->items = (data_type *)malloc(sizeof(data_type) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->rear == -1);
}

// Function to enqueue an item into the queue
void enqueue(struct Queue *q, data_type item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->items[q->rear] = item;
}

// Function to dequeue an item from the queue
data_type dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1;  // Return an error value
    }

    data_type item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return item;
}

// Function to print the contents of the queue
void printQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }

    printf("\n");
}

// Main function to test the queue implementation
int main() {
    // Create a queue of size 5
    struct Queue *q = createQueue(5);

    // Enqueue some items into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Print the contents of the queue
    printf("Contents of the queue:\n");
    printQueue(q);

    // Dequeue some items from the queue
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));

    // Print the contents of the queue
    printf("Contents of the queue after dequeuing:\n");
    printQueue(q);

    // Dequeue all remaining items from the queue
    while (!isEmpty(q)) {
        printf("Dequeued item: %d\n", dequeue(q));
    }

    // Print the contents of the queue
    printf("Contents of the queue after dequeuing all items:\n");
    printQueue(q);

    return 0;
}