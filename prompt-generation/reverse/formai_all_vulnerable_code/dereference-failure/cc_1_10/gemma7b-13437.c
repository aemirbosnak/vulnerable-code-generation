//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertAtEnd(struct node* head, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

struct node* insertAtBeginning(struct node* head, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
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

struct node* deleteFromEnd(struct node* head)
{
    struct node* temp = head;
    struct node* prev = NULL;

    if (head == NULL) {
        return NULL;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }

    return head;
}

struct node* deleteFromBeginning(struct node* head)
{
    struct node* temp = head;

    if (head == NULL) {
        return NULL;
    }

    head = temp->next;
    free(temp);

    return head;
}

struct node* searchForNode(struct node* head, int data)
{
    struct node* temp = head;

    while (temp) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main()
{
    struct node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtBeginning(head, 50);

    struct node* searchResult = searchForNode(head, 30);

    if (searchResult) {
        printf("Node found: %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }

    deleteFromBeginning(head);
    deleteFromEnd(head);

    searchResult = searchForNode(head, 30);

    if (searchResult) {
        printf("Node found: %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}