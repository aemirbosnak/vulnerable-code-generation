//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void enqueue(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int dequeue() {
    if (head == NULL) {
        return -1;
    }
    int data = head->data;
    struct node* temp = head;
    head = head->next;
    free(temp);
    return data;
}

int peek() {
    if (head == NULL) {
        return -1;
    }
    return head->data;
}

int isEmpty() {
    return head == NULL;
}

int size() {
    if (head == NULL) {
        return 0;
    }
    return 1 + size();
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("Queue: ");
    while (!isEmpty()) {
        printf("%d ", peek());
        dequeue();
    }
    printf("\n");
    printf("Queue size: %d\n", size());
    return 0;
}