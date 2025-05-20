//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head;
node *tail;

void queue_destroy(){
    node *temp;
    while(head!= NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void enqueue(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(tail == NULL){
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int dequeue(){
    if(head == NULL){
        printf("Queue is empty\n");
        return -1;
    }

    int data = head->data;
    node *temp = head;
    head = head->next;
    free(temp);

    return data;
}

void display(){
    node *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    queue_destroy();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    printf("Deleted element: %d\n", dequeue());
    display();
    enqueue(4);
    display();
    enqueue(5);
    display();
    queue_destroy();

    return 0;
}