//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

void insert(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteNode(struct node* node) {
    if (node == head) {
        head = node->next;
        head->prev = NULL;
    } else if (node == tail) {
        tail = node->prev;
        tail->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    printf("Linked List: ");
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    deleteNode(head->next->next);
    printf("Linked List after deleting node: ");
    temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}