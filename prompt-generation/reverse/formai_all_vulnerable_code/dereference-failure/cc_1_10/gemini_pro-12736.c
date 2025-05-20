//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *arr;
  int front, rear, capacity;
} Queue;

Queue* createQueue(int capacity) {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->arr = (int*) malloc(sizeof(int) * capacity);
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

void enqueue(Queue* queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->arr[++queue->rear] = data;
}

int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  }
  int data = queue->arr[queue->front];
  queue->front++;
  if (queue->front > queue->rear) {
    queue->front = queue->rear = -1;
  }
  return data;
}

int front(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. No front element.\n");
    return -1;
  }
  return queue->arr[queue->front];
}

int rear(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. No rear element.\n");
    return -1;
  }
  return queue->arr[queue->rear];
}

int size(Queue* queue) {
  if (isEmpty(queue)) {
    return 0;
  }
  return queue->rear - queue->front + 1;
}

int isEmpty(Queue* queue) {
  return queue->front == -1;
}

int isFull(Queue* queue) {
  return queue->rear == queue->capacity - 1;
}

void printQueue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Nothing to print.\n");
    return;
  }
  printf("Queue: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

int main() {
  int n, choice, data;
  printf("Enter the capacity of the queue: ");
  scanf("%d", &n);

  Queue* queue = createQueue(n);

  while (1) {
    printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Size\n6. Print\n7. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        enqueue(queue, data);
        break;
      case 2:
        printf("Dequeued: %d\n", dequeue(queue));
        break;
      case 3:
        printf("Front: %d\n", front(queue));
        break;
      case 4:
        printf("Rear: %d\n", rear(queue));
        break;
      case 5:
        printf("Size: %d\n", size(queue));
        break;
      case 6:
        printQueue(queue);
        break;
      case 7:
        return 0;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }
  }

  return 0;
}