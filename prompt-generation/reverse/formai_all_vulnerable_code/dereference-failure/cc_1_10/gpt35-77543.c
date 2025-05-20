//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
  int pid;
  int priority;
  struct Node* next;
}Node;

Node* head = NULL; //initialize the head node

//function to insert new process in the queue
void insert(int pid, int priority){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->pid = pid;
  newNode->priority = priority;
  newNode->next = NULL;
  
  if(head == NULL){
    head = newNode;
  }else if(head->priority > priority){
    newNode->next = head;
    head = newNode;
  }else{
    Node* temp = head;
    while(temp->next != NULL && temp->next->priority <= priority){
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

//function to remove process with highest priority from the queue
void removeProcess(){
  if(head == NULL){
    printf("No processes in the queue!\n");
  }else{
    Node* temp = head;
    head = head->next;
    printf("Process with PID %d and priority %d has been dequeued.\n", temp->pid, temp->priority);
    free(temp);
  }
}

//function to print all processes in the queue
void displayQueue(){
  Node* temp = head;
  if(temp == NULL){
    printf("No processes in the queue!\n");
    return;
  }
  printf("PID\tPriority\n");
  while(temp != NULL){
    printf("%d\t%d\n", temp->pid, temp->priority);
    temp = temp->next;
  }
}

int main(){
  int choice = 0, pid, priority;
  srand(time(NULL)); //initialize random seed
  printf("Welcome to the Cyberpunk QoS Monitor!\n");

  //main menu loop
  do{
    printf("\n1. Add process to queue\n");
    printf("2. Remove highest priority process from queue\n");
    printf("3. Display processes in queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        //generate random PID and priority values
        pid = rand() % 1000;
        priority = rand() % 10 + 1; //priority range: 1-10
        printf("Adding process with PID %d and priority %d to queue...\n", pid, priority);
        insert(pid, priority);
        break;
      case 2:
        printf("Removing highest priority process from queue...\n");
        removeProcess();
        break;
      case 3:
        printf("Displaying processes in queue...\n");
        displayQueue();
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
    }
  }while(choice != 4);
  
  return 0;
}