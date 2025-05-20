//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue
struct Queue {
  int front, rear, size;
  int *array;
};

// Create a new queue
struct Queue* createQueue(int size) {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = queue->rear = -1;
  queue->size = size;
  queue->array = (int *)malloc(queue->size * sizeof(int));
  return queue;
}

// Check if the queue is full
int isFull(struct Queue *queue) {
  return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
  return (queue->front == -1);
}

// Add an element to the queue
void enqueue(struct Queue *queue, int element) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }
  else {
    if (queue->front == -1)
      queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = element;
    printf("%d inserted to the queue\n", element);
  }
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
  int element;
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return (-1);
  }
  else {
    element = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
      queue->front = queue->rear = -1;
    printf("%d removed from the queue\n", element);
    return (element);
  }
}

// Display the elements of the queue
void display(struct Queue *queue) {
  int i;
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
  }
  else {
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i++)
      printf("%d  ", queue->array[i]);
    printf("\n");
  }
}

// Free the queue
void freeQueue(struct Queue *queue) {
  if (queue) {
    if (queue->array)
      free(queue->array);
    free(queue);
  }
}

// Example usage
int main() {
  int size;
  struct Queue *queue = NULL;
  int element;
  int choice;

  printf("Enter the size of the queue: ");
  scanf("%d", &size);

  queue = createQueue(size);

  while(1) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the element to be enqueued: ");
        scanf("%d", &element);
        enqueue(queue, element);
        break;
      case 2:
        element = dequeue(queue);
        break;
      case 3:
        display(queue);
        break;
      case 4:
        freeQueue(queue);
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}