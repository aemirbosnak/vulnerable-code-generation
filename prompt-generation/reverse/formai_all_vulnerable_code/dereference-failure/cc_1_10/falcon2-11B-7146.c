//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation error");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct node* insertNode(struct node* node, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return NULL;
    }
    newNode->prev = node;
    node->next = newNode;
    return newNode;
}

struct node* removeNode(struct node* node) {
    struct node* temp = node->next;
    free(node);
    return temp;
}

void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void enqueue(struct node** front, struct node** rear, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    (*rear)->next = newNode;
    newNode->prev = *rear;
    *rear = newNode;
}

int dequeue(struct node** front, struct node** rear) {
    struct node* temp = *front;
    if (*front == NULL) {
        return -1;
    }
    (*front)->next->prev = NULL;
    *front = (*front)->next;
    free(temp);
    return 0;
}

void displayQueue(struct node** front, struct node** rear) {
    printList(*front);
    printf("\n");
    printList(*rear);
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    displayQueue(&front, &rear);
    printf("\n");
    dequeue(&front, &rear);
    displayQueue(&front, &rear);
    return 0;
}