//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the rear of the queue
void enqueue(Node** front, Node** rear, int data) {
    Node* node = newNode(data);
    if (*rear == NULL) {
        *front = node;
        *rear = node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Node** front, Node** rear) {
    Node* temp = *front;
    int data = temp->data;
    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
    } else {
        *front = (*front)->next;
    }
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    display(front);

    int data = dequeue(&front, &rear);
    printf("Dequeued element: %d\n", data);

    display(front);

    return 0;
}