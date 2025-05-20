//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    int data = -1;

    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    else if (front == rear) {
        data = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    }
    else {
        data = front->data;
        node* temp = front;
        front = front->next;
        free(temp);
    }

    return data;
}

void display() {
    node* temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                data = dequeue();
                if (data!= -1)
                    printf("Dequeued data: %d\n", data);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    while (choice!= 4);

    return 0;
}