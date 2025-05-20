//FormAI DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to hold the queue
typedef struct queue {
   int data[MAX_SIZE];
   int front;
   int rear;
   int size;
} Queue;

// Function to initialize a new Queue
Queue *newQueue() {
   Queue *queue = (Queue *) malloc(sizeof (Queue));
   queue->front = -1;
   queue->rear = -1;
   queue->size = 0;
   return queue;
}

// Function to check if the Queue is empty
int isEmpty(Queue *queue) {
   return queue->size == 0;
}

// Function to check if the Queue is full
int isFull(Queue *queue) {
   return queue->size == MAX_SIZE;
}

// Function to add an element to the rear of the Queue
void enqueue(Queue *queue, int item) {
   if (isFull(queue)) {
      printf("Queue is full, cannot add element %d.\n", item);
      return;
   }
   queue->rear = (queue->rear+1) % MAX_SIZE;
   queue->data[queue->rear] = item;
   queue->size++;
   if (queue->front == -1) {
      queue->front = queue->rear;
   }
}

// Function to remove an element from the front of the Queue
int dequeue(Queue *queue) {
   if (isEmpty(queue)) {
      printf("Queue is empty, cannot remove element.\n");
      return -1;
   }
   int item = queue->data[queue->front];
   if (queue->front == queue->rear) {
      queue->front = -1;
      queue->rear = -1;
   } else {
      queue->front = (queue->front+1) % MAX_SIZE;
   }
   queue->size--;
   return item;
}

// Function to display elements in the Queue
void display(Queue *queue) {
   if (isEmpty(queue)) {
      printf("The queue is empty.\n");
      return;
   }
   printf("Elements in the queue: ");
   int i;
   for (i = queue->front; i != queue->rear; i = (i+1) % MAX_SIZE) {
      printf("%d ", queue->data[i]);
   }
   printf("%d\n", queue->data[queue->rear]);
}

// Main function to test the Queue
int main() {
   Queue *queue = newQueue();
   int choice, item;
   do {
      printf("Enter your choice:\n");
      printf("1: Enqueue\n");
      printf("2: Dequeue\n");
      printf("3: Display queue\n");
      printf("4: Exit\n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter element to be enqueued: ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
         case 2:
            item = dequeue(queue);
            if (item != -1) {
               printf("Element dequeued: %d\n", item);
            }
            break;
         case 3:
            display(queue);
            break;
         case 4:
            printf("Exiting program...\n");
            break;
         default:
            printf("Invalid choice!\n");
            break;
      }
   } while (choice != 4);
   return 0;
}