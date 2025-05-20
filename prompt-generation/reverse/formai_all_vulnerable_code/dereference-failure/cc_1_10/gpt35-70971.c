//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
// A unique Queue implementation in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // maximum size of the queue

// Node struct for Queue
typedef struct node
{
    int data;
    struct node* next;
} Node;

Node* front = NULL; // front pointer of queue
Node* rear = NULL;  // rear pointer of queue
int size = 0;       // current size of the queue

// Function to enqueue an item into the queue
void enqueue(int item)
{
    if(size == MAX_SIZE)
    {
        printf("Queue is full! Item %d could not be enqueued.\n", item);
        return;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node)); // allocate memory for the new node
    new_node->data = item;                         // set the data of the new node
    new_node->next = NULL;
    
    if(front == NULL)  // if queue is empty, set both front and rear to the new node
    {
        front = new_node;
        rear = new_node;
    }
    else // else, insert the new node after the rear pointer and move rear pointer to the new node
    {
        rear->next = new_node;
        rear = new_node;
    }
    
    size++; // increase the size of the queue
    printf("Item %d enqueued.\n", item);
}

// Function to dequeue an item from the queue
void dequeue()
{
    if(front == NULL) // if queue is empty, nothing to dequeue
    {
        printf("Queue is empty! Nothing to dequeue.\n");
        return;
    }
    
    Node* temp = front; // hold the front pointer in a temp pointer
    front = front->next; // move front to the next node
    
    if(front == NULL) // if front becomes NULL after dequeue, set rear to NULL as well
        rear = NULL;
    
    printf("Item %d dequeued.\n", temp->data);
    free(temp); // free the memory of the dequeued node
    size--; // decrease the size of the queue
}

// Function to display all the items in the queue
void display()
{
    if(front == NULL) // if queue is empty, nothing to display
    {
        printf("Queue is empty! Nothing to display.\n");
        return;
    }
    
    Node* temp = front;
    
    printf("Queue Contents:\n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10); // enqueue some items
    enqueue(20); 
    enqueue(30); 
    enqueue(40); 
    enqueue(50); 
    display(); // display the current queue contents
    
    dequeue(); // dequeue some items
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // dequeue till the queue is empty
    dequeue(); // try to dequeue when there's nothing to dequeue anymore
    display();
    
    enqueue(60); // enqueue again after dequeueing everything
    display();
    
    return 0;
}