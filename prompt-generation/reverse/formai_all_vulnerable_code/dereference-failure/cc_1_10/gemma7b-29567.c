//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* insertTail(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

struct Node* insertHead(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

struct Node* deleteTail(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;

    if (head == NULL) {
        return NULL;
    }

    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    if (prev) {
        prev->next = NULL;
    } else {
        head = NULL;
    }

    return head;
}

struct Node* deleteHead(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;

    if (head == NULL) {
        return NULL;
    }

    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    if (prev) {
        prev->next = head->next;
    } else {
        head = NULL;
    }

    return head;
}

void traverseAndPrint(struct Node* head)
{
    struct Node* curr = head;

    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);
    insertHead(head, 40);
    insertHead(head, 50);

    traverseAndPrint(head);

    deleteTail(head);
    deleteHead(head);

    traverseAndPrint(head);

    return 0;
}