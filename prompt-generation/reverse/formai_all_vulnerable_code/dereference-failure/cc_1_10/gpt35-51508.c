//FormAI DATASET v1.0 Category: Queue ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

struct queue
{
   int front, rear;
   int capacity;
   int* array;
};

typedef struct queue queue;

queue* createQueue(int capacity)
{
   queue* q = (queue*)malloc(sizeof(queue));
   q->front = q->rear = -1;
   q->capacity = capacity;
   q->array = (int*)malloc(q->capacity * sizeof(int));
   printf("Congratulations! Your queue has been created. All hail the Almighty Queue!\n");
   return q;
}

int isEmpty(queue* q)
{
   if(q->front == -1)
   {
      printf("What sorcery is this? The queue is empty!\n");
      return 1;
   }
   else
   {
      printf("Fear not, the queue is not empty. The gods of the queue smile upon us!\n");
      return 0;
   }
}

int isFull(queue* q)
{
   if(q->rear == q->capacity - 1)
   {
      printf("By the great queue in the sky, the queue is full! Sacrifices must be offered to appease the gods of the queue.\n");
      return 1;
   }
   else
   {
      printf("The queue still has spaces to fill. The gods of the queue are satisfied for now.\n");
      return 0;
   }
}

void enqueue(queue* q, int item)
{
   if(isFull(q))
      printf("Oh no! The queue is full. We must wait for someone to leave.\n");
   else
   {
      q->rear++;
      q->array[q->rear] = item;
      printf("Fantastic! We have added %d to the queue. The queue gods are pleased.\n", item);
      if(q->front == -1)
         q->front = 0;
   }
}

int dequeue(queue* q)
{
   int item;
   if(isEmpty(q))
   {
      printf("Alas! The queue is already empty. We cannot remove anymore.\n");
      return -1;
   }
   else
   {
      item = q->array[q->front];
      printf("Hooray! We have removed %d from the queue. The queue gods are pleased.\n", item);
      q->front++;
      if(q->front > q->rear)
         q->front = q->rear = -1;
      return item;
   }
}

void display(queue* q)
{
   int i;
   if(isEmpty(q))
      printf("There is nothing to display. The queue is empty.\n");
   else
   {
      printf("The queue elements are:\n");
      for(i = q->front; i <= q->rear; i++)
         printf("%d\t", q->array[i]);
      printf("\n");
   }
}

int main()
{
   queue* q;
   int choice, item, capacity;
   printf("Welcome to the creation of a queue, mortal!\nEnter the capacity of the queue: ");
   scanf("%d", &capacity);
   q = createQueue(capacity);
   do
   {
      printf("\n1. Display Queue\n2. Enqueue\n3. Dequeue\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch(choice)
      {
         case 1: display(q);
                 break;
         case 2: printf("Enter the element to be added: ");
                 scanf("%d", &item);
                 enqueue(q, item);
                 break;
         case 3: item = dequeue(q);
                 printf("The removed element is: %d\n", item);
                 break;
         case 4: printf("Hark! Let the queue be destroyed! The gods of the queue have spoken.\n");
                 break;
         default: printf("You have committed a grave mistake. Beware the wrath of the queue gods!\n");
                  break;
      }
   }while(choice != 4);
   free(q->array);
   free(q);
   return 0;
}