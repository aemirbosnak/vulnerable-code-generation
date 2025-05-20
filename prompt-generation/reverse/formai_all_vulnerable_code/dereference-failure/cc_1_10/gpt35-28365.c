//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

//Creating a structure to represent the Queue
struct Queue{
  int front,rear;
  int capacity;
  int*array;
};

//Function to create a Queue with a given capacity
struct Queue* createQueue(int capacity){
  struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity=capacity;
  queue->front=-1;
  queue->rear=-1;
  queue->array=(int*)malloc(sizeof(int)*capacity);
  return queue;
}

//Function to check if the Queue is Empty
int isEmpty(struct Queue* queue){
  if(queue->front==-1)
    return 1;
  else
    return 0;
}

//Function to check if the Queue is Full
int isFull(struct Queue* queue){
  if(queue->rear==queue->capacity-1)
    return 1;
  else
    return 0;
}

//Function to add an element to the Queue
void enqueue(struct Queue* queue,int data){
  if(isFull(queue)){
    printf("Queue is Full\n");
    return;
  }
  else{
    queue->rear++;
    queue->array[queue->rear]=data;
    if(queue->front==-1)
      queue->front++;
  }
}

//Function to remove an element from the Queue
int dequeue(struct Queue* queue){
  int data;
  if(isEmpty(queue)){
    printf("Queue is Empty\n");
    return -1;
  }
  else{
    data=queue->array[queue->front];
    queue->front++;
    if(queue->front>queue->rear){
      queue->front=-1;
      queue->rear=-1;
    }
    return data;
  }
}

//Function to display the elements of the Queue
void display(struct Queue* queue){
  int i;
  if(isEmpty(queue)){
    printf("Queue is Empty\n");
    return;
  }
  else{
    printf("Elements of the Queue are: ");
    for(i=queue->front;i<=queue->rear;i++)
      printf("%d ",queue->array[i]);
    printf("\n");
  }
}

//Main Function
int main(){
  struct Queue* queue=createQueue(5);
  int choice,data;
  while(1){
    printf("Enter 1 to Enqueue\n");
    printf("Enter 2 to Dequeue\n");
    printf("Enter 3 to Display\n");
    printf("Enter 4 to Exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the element to be Enqueued: ");
        scanf("%d",&data);
        enqueue(queue,data);
        break;
      case 2:
        data=dequeue(queue);
        if(data!=-1)
          printf("Dequeued Element is: %d\n",data);
        break;
      case 3:
        display(queue);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid Choice\n");
    }
  }
  return 0;
}