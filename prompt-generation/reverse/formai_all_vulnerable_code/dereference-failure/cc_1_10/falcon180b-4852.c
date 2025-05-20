//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if(!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** front, node** rear, int data) {
    node* newNode = createNode(data);
    if(*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    }
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(node** front, node** rear) {
    node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    free(temp);
    if(*front == NULL)
        *rear = NULL;
    return data;
}

void display(node* front) {
    while(front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    node* front = NULL;
    node* rear = NULL;
    int choice, data;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                if(data!= -1)
                    printf("Dequeued element is %d\n", data);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}