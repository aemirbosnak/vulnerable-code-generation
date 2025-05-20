//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *headRef;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int dequeue(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = *headRef;
    int data = temp->data;
    *headRef = temp->next;
    free(temp);
    return data;
}

void printQueue(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    printQueue(head);
    printf("Dequeued %d from the queue.\n", dequeue(&head));
    printQueue(head);
    return 0;
}