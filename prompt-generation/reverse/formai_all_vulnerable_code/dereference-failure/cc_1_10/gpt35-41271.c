//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

/* Defining structure for queue */
typedef struct node{
    int data;
    struct node* next;
}node;

/* Defining structure for queue */
typedef struct queue{
    node *front, *rear;
}queue;

/* Initializing empty queue */
queue* init_queue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

/* Checking if queue is empty */
int is_empty(queue* q){
    return (q->front == NULL);
}

/* Adding element to the rear of the queue */
void enqueue(queue* q, int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(q->rear == NULL){
        q->front = q->rear = new_node;
        return;
    }
    
    q->rear->next = new_node;
    q->rear = new_node;
}

/* Removing element from the front of the queue */
void dequeue(queue* q){
    if(is_empty(q))
        return;
    
    node* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);
}

/* Printing elements of the queue */
void print_queue(queue* q){
    if(is_empty(q))
        return;

    node* temp = q->front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver code */
int main(){
    queue *q1 = init_queue();
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);

    printf("Initial Queue:\n");
    print_queue(q1);

    dequeue(q1);
    printf("\nQueue after dequeue operation:\n");
    print_queue(q1);

    enqueue(q1,40);
    printf("\nQueue after enqueue operation:\n");
    print_queue(q1);

    return 0;
}