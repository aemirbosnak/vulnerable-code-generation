//FormAI DATASET v1.0 Category: Queue ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct queue {
  int capacity;
  int front;
  int rear;
  int *data;
};

// Function Declarations
void init_queue(struct queue *q, int capacity);
int is_full(struct queue *q);
int is_empty(struct queue *q);
void enqueue(struct queue *q, int item);
int dequeue(struct queue *q);
void print_queue(struct queue *q);

// Initialize a queue
void init_queue(struct queue *q, int capacity) {
  q->capacity = capacity;
  q->front = 0;
  q->rear = -1;
  q->data = malloc(capacity * sizeof(int));
}

// Check if the queue is full
int is_full(struct queue *q) {
  return q->rear == q->capacity - 1;
}

// Check if the queue is empty
int is_empty(struct queue *q) {
  return q->rear == -1;
}

// Add an item to the queue
void enqueue(struct queue *q, int item) {
  if (is_full(q)) {
    printf("Queue is full!\n");
  } else {
    q->rear++;
    q->data[q->rear] = item;
  }
}

// Remove an item from the queue
int dequeue(struct queue *q) {
  int item = -1;
  if (is_empty(q)) {
    printf("Queue is empty!\n");
  } else {
    item = q->data[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = 0;
      q->rear = -1;
    }
  }
  return item;
}

// Print the contents of the queue
void print_queue(struct queue *q) {
  int i;
  if (is_empty(q)) {
    printf("Queue is empty!\n");
  } else {
    printf("Front -> ");
    for (i = q->front; i <= q->rear; i++) {
      printf("%d ", q->data[i]);
    }
    printf(" <- Rear\n");
  }
}

// Main Function
int main() {

  struct queue q;
  int choice, item, capacity;

  printf("Enter the capacity of the queue: ");
  scanf("%d", &capacity);

  init_queue(&q, capacity);

  while (1) {
    printf("Select an option:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter a number to enqueue: ");
        scanf("%d", &item);
        enqueue(&q, item);
        break;

      case 2:
        item = dequeue(&q);
        if (item != -1) {
          printf("Dequeued element is %d\n", item);
        }
        break;

      case 3:
        print_queue(&q);
        break;

      default:
        printf("Invalid Option!\n");
        break;
    }

    if (choice == 4) {
      break;
    }
  }

  return 0;
}