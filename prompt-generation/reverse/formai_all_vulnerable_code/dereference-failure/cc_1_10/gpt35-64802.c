//FormAI DATASET v1.0 Category: Queue ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* Define the Queue Node data structure */
typedef struct QueueNode {
   int data;
   struct QueueNode* next;
} Node;

/* Define the Queue data structure */
typedef struct {
   Node* front;
   Node* rear;
} Queue;

/*
 * Recursive function to reverse the Queue contents
 * This function will use the concept of recursion by taking out the first element
 * and recursively calling itself to move the remaining elements to the front of the Queue
 */
void reverse(Queue* queue) {
   if (!queue || !queue->front) {
      return;
   }
   int data = queue->front->data;
   Node* temp = queue->front->next;
   reverse(queue);
   if (!queue->rear) {
      queue->rear = queue->front;
   }
   queue->front->next = NULL;
   if (queue->rear != queue->front) {
      queue->rear->next = queue->front;
      queue->rear = queue->front;
   }
   queue->front = temp;
   if (queue->front) {
      Node* curr = queue->front;
      while (curr->next) {
         curr = curr->next;
      }
      queue->rear = curr;
   }
   queue->rear->next = (Node*) malloc(sizeof(Node));
   queue->rear->next->data = data;
   queue->rear->next->next = NULL;
}

int main() {
   Queue* queue = (Queue*) malloc(sizeof(Queue));
   queue->front = NULL;
   queue->rear = NULL;
   int value;

   /* enqueue few elements */
   printf("Enqueuing elements to the Queue ....\n");
   for (int i = 1; i <=5; i++) {
      queue->rear = (Node*) malloc(sizeof(Node));
      queue->rear->data = i*10;
      queue->rear->next = NULL;

      if (queue->front == NULL) {
         queue->front = queue->rear;
      }
      else {
         Node* temp = queue->front;
         while (temp->next != NULL) {
            temp = temp->next;
         }
         temp->next = queue->rear;
      }
   }
   
   /* Display the current state of the queue */
   printf("The queue before reversing its elements:\n");
   if (queue->front == NULL) {
      printf("The queue is empty!\n");
   } else {
      Node* curr = queue->front;
      while (curr != NULL) {
         printf("%d ", curr->data);
         curr = curr->next;
      }
      printf("\n");
   }
   
   /* Reverse the queue contents */
   reverse(queue);

   /* Display the current state of the queue */
   printf("The queue after reversing its elements:\n");
   if (queue->front == NULL) {
      printf("The queue is empty!\n");
   } else {
      Node* curr = queue->front;
      while (curr != NULL) {
         printf("%d ", curr->data);
         curr = curr->next;
      }
      printf("\n");
   }

   /* Dequeue elements till the queue becomes empty */
   while (queue->front != NULL) {
      value = queue->front->data;
      printf("Dequeuing element: %d\n", value);
      Node* temp = queue->front;
      queue->front = queue->front->next;
      free(temp);
   }
   free(queue);
   return 0;
}