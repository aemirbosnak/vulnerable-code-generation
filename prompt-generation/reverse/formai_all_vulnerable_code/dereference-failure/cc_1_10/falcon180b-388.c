//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else if (rear == NULL) {
        rear = newnode;
        front->next = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("\n%d enqueued to the queue", data);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty");
    } else if (front == rear) {
        struct node *newnode = front;
        free(newnode);
        front = rear = NULL;
    } else {
        struct node *newnode = front;
        front = front->next;
        free(newnode);
    }

    printf("\n%d dequeued from the queue", front->data);
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty");
    } else {
        struct node *temp = front;
        printf("\nElements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, data;

    do {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice");
        }
    } while (choice!= 4);

    return 0;
}