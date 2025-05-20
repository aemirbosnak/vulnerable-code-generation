//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    int value = -1;
    if (front!= NULL) {
        struct node *temp = front;
        value = front->data;
        front = front->next;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
    return value;
}

void display() {
    struct node *temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value == -1)
                    printf("Queue is empty\n");
                else
                    printf("The dequeued value is %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}