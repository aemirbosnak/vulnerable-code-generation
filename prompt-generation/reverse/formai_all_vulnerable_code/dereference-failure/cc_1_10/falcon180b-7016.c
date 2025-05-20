//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// node structure for linked list
struct node {
    int data;
    struct node* next;
};

// function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// function to print the linked list
void printList(struct node* head) {
    struct node* node = head;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// function to search for a value in the linked list
struct node* searchList(struct node* head, int value) {
    struct node* node = head;
    while (node!= NULL) {
        if (node->data == value) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

// main function to test the linked list and search algorithm
int main() {
    // create a linked list with some values
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // print the initial linked list
    printf("Initial linked list:\n");
    printList(head);

    // search for a value in the linked list
    struct node* result = searchList(head, 3);

    // print the result of the search
    if (result!= NULL) {
        printf("Value %d found in the linked list.\n", result->data);
    } else {
        printf("Value %d not found in the linked list.\n", 3);
    }

    return 0;
}