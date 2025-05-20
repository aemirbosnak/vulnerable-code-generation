//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // maximum size of the queue

/* Define a struct for each customer */
typedef struct customer {
    int id;  // unique customer ID
    char flavor[20]; // favorite ice-cream flavor
    struct customer *next; // pointer to the next customer
} Customer;

/* Define a struct for the queue */
typedef struct queue {
    Customer *front; // pointer to the front of queue
    Customer *rear; // pointer to the rear of queue
    int count;  // number of customers in the queue
} Queue;

/* Initialize an empty queue */
void Initialize(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

/* Check if the queue is full */
int IsFull(Queue *q) {
    if(q->count == MAX_SIZE)
        return 1;
    else
        return 0;
}

/* Check if the queue is empty */
int IsEmpty(Queue *q) {
    if(q->count == 0)
        return 1;
    else
        return 0;
}

/* Insert a new customer to the queue */
void Insert(Queue *q, int id, char flavor[]) {
    if(IsFull(q)) {
        printf("The queue is full! Cannot add a new customer.\n");
        return;
    }

    Customer *new_customer = (Customer*)malloc(sizeof(Customer)); // allocate memory for new customer
    new_customer->id = id;  // assign customer ID
    strcpy(new_customer->flavor, flavor); // assign ice-cream flavor
    new_customer->next = NULL;

    if(IsEmpty(q)) { // if the queue is initially empty
        q->front = new_customer;
        q->rear = new_customer;
    }
    else {  // if the queue is not empty
        q->rear->next = new_customer;
        q->rear = new_customer;
    }

    q->count++; // increase the queue size
    printf("Customer with ID %d and favorite ice-cream flavor %s has been added to the queue.\n", id, flavor);
}

/* Remove the front customer from the queue */
void Delete(Queue *q) {
    if(IsEmpty(q)) {
        printf("The queue is empty! Cannot remove any customer.\n");
        return;
    }

    Customer *temp = q->front;
    q->front = q->front->next;

    free(temp); // release the memory for the front customer
    q->count--; // decrease the queue size
}

/* Print the customer queue */
void Print(Queue *q) {
    if(IsEmpty(q)) {
        printf("The queue is empty!\n");
        return;
    }

    Customer *temp = q->front;
    printf("Here is the list of customers in the queue:\n");
    while(temp != NULL) {
        printf("Customer ID: %d | Favorite ice-cream flavor: %s\n", temp->id, temp->flavor);
        temp = temp->next;
    }
}

/* Main function */
int main() {
    Queue queue;
    Initialize(&queue);
    printf("Welcome to our virtual ice-cream store!\n");

    /* Add some initial customers */
    Insert(&queue, 1, "Strawberry");
    Insert(&queue, 2, "Chocolate");
    Insert(&queue, 3, "Vanilla");
    Insert(&queue, 4, "Mint");

    /* Print the initial customer queue */
    Print(&queue);

    /* Add more customers */
    Insert(&queue, 5, "Butter Pecan");
    Insert(&queue, 6, "Rocky Road");
    Insert(&queue, 7, "Pistachio");

    /* Print the updated customer queue */
    Print(&queue);

    /* Remove some customers */
    Delete(&queue);
    Delete(&queue);

    /* Print the updated customer queue */
    Print(&queue);

    return 0;
}