//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void enqueue(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    struct node* temp = head;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dequeue() {
    if(head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct node* temp = head;
    if(temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    temp->next = temp->next->next;
    free(temp);
}

void display() {
    struct node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}