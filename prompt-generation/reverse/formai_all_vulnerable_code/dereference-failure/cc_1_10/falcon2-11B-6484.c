//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createQueue() {
    Node* head = NULL;
    Node* tail = NULL;
    return head;
}

void enqueue(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int dequeue(Node** headRef) {
    Node* temp = *headRef;
    if (*headRef == NULL) {
        return -1;
    } else {
        Node* temp2 = *headRef;
        if (temp2->next == NULL) {
            *headRef = NULL;
        } else {
            while (temp2->next->next!= NULL) {
                temp2 = temp2->next;
            }
            Node* temp3 = temp2->next;
            temp2->next = NULL;
            *headRef = temp3;
        }
    }
    return temp->data;
}

void printQueue(Node* head) {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    Node* head = createQueue();
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);
    enqueue(&head, 5);
    printf("Queue after enqueueing\n");
    printQueue(head);
    printf("\n");
    printf("Dequeuing from the head\n");
    int data = dequeue(&head);
    printf("%d\n", data);
    printf("Queue after dequeueing\n");
    printQueue(head);
    return 0;
}