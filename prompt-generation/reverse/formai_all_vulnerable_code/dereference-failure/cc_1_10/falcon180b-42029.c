//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// structure to represent a node
struct Node {
    int data;
    struct Node* next;
};

// function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to print a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to search for an element in a linked list
struct Node* search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// main function
int main() {
    struct Node* head = NULL;
    int i, choice, key;

    // create a linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // print the linked list
    printf("Linked List: ");
    printList(head);

    // search for an element
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    struct Node* result = search(head, key);
    if (result!= NULL)
        printf("Element found at position %d\n", result->data);
    else
        printf("Element not found\n");

    return 0;
}