//FormAI DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

typedef struct queue Queue;

void enqueue(Queue **, int); // function prototype to insert a node at the end of the queue
int dequeue(Queue **); // function prototype to remove a node from the front of the queue
void print_queue(Queue *); // function prototype to print the queue

int main(){
    Queue *head = NULL; // initialize an empty queue
    
    enqueue(&head, 10); // insert 10 in the queue
    enqueue(&head, 20); // insert 20 in the queue
    enqueue(&head, 30); // insert 30 in the queue
    enqueue(&head, 40); // insert 40 in the queue
    
    printf("Original Queue: ");
    print_queue(head); // print the original queue
    
    int removed = dequeue(&head); // remove the first node (10) from the queue
    printf("\nRemoved element: %d", removed);
    
    printf("\nQueue after removing first element: ");
    print_queue(head); // print the updated queue
    
    return 0;
}

// function definition to insert a node at the end of the queue
void enqueue(Queue **head, int value){
    Queue *new_node = (Queue *) malloc(sizeof(Queue)); // allocate memory for the new node
    new_node->data = value;
    new_node->next = NULL;
    
    // if queue is empty
    if(*head == NULL){
        *head = new_node;
    } else{ // if queue is not empty
        Queue *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// function definition to remove a node from the front of the queue
int dequeue(Queue **head){
    // if queue is empty
    if(*head == NULL){
        printf("\nQueue is empty.");
        return -1;
    } else{ // if queue is not empty
        int removed_element = (*head)->data;
        Queue *temp = *head;
        *head = (*head)->next;
        free(temp);
        
        return removed_element;
    }
}

// function definition to print the queue
void print_queue(Queue *head){
    if(head == NULL){
        return;
    } else{
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
}