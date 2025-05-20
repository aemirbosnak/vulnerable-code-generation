//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

struct Queue 
{ 
    struct Node* front; 
    struct Node* rear; 
}; 
  
void addElement(struct Queue *q, int new_element) 
{ 
    // Create a new node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    
    // Initialize data of new_node 
    new_node->data = new_element; 
    
    // If queue is empty (i.e., front==NULL) 
    if (q->front==NULL) 
    { 
        // Make new_node as front of queue 
        q->front = new_node; 
        q->rear = new_node; 
    } 
    else 
    { 
        // Make new_node as rear of queue 
        q->rear->next = new_node; 
        q->rear = new_node; 
    } 
} 
  
void displayQueue(struct Queue* q) 
{ 
    if(q==NULL) 
    { 
        printf("Queue is Empty\n"); 
        return; 
    } 
    struct Node* temp=q->front; 
      
    while(temp!=NULL) 
    { 
        printf("%d ",temp->data); 
        temp=temp->next; 
    } 
    printf("\n"); 
} 
  
int main() 
{ 
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue)); 
    addElement(q,10); 
    addElement(q,20); 
    addElement(q,30); 
    displayQueue(q); 
    
    return 0; 
}