//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//function to create a new node with given data
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(!new_node){
        printf("Memory error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//function to add an element to the rear of the queue
void enqueue(struct node** front_ref, struct node** rear_ref, int data){
    struct node* new_node = create_node(data);
    if(new_node == NULL){
        return;
    }
    if(*rear_ref == NULL){
        *front_ref = new_node;
        *rear_ref = new_node;
    }
    else{
        (*rear_ref)->next = new_node;
        *rear_ref = new_node;
    }
}

//function to remove an element from the front of the queue
int dequeue(struct node** front_ref, struct node** rear_ref){
    struct node* temp_node = *front_ref;
    int data = temp_node->data;
    if(temp_node == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    if(*front_ref == *rear_ref){
        *front_ref = NULL;
        *rear_ref = NULL;
    }
    else{
        *front_ref = (*front_ref)->next;
    }
    free(temp_node);
    return data;
}

//function to display the elements in the queue
void display(struct node* front){
    printf("Queue elements are: ");
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(){
    struct node* front = NULL;
    struct node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    printf("Queue elements after enqueue:\n");
    display(front);

    int dequeued_data = dequeue(&front, &rear);
    printf("Dequeued data: %d\n", dequeued_data);

    printf("Queue elements after dequeue:\n");
    display(front);

    dequeued_data = dequeue(&front, &rear);
    printf("Dequeued data: %d\n", dequeued_data);

    printf("Queue elements after dequeue:\n");
    display(front);

    dequeued_data = dequeue(&front, &rear);
    printf("Dequeued data: %d\n", dequeued_data);

    printf("Queue elements after dequeue:\n");
    display(front);

    dequeued_data = dequeue(&front, &rear);
    printf("Dequeued data: %d\n", dequeued_data);

    printf("Queue elements after dequeue:\n");
    display(front);

    return 0;
}