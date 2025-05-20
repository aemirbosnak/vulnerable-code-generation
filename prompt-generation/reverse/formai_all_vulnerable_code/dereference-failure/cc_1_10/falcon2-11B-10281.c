//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct List {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct List* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct List* list, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = list->head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct List* list, int data) {
    struct Node* current = list->head;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current!= NULL) {
        if (prev == NULL) {
            list->head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Function to reverse a linked list
void reverse(struct List* list) {
    struct Node* current = list->head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

// Function to print the linked list
void printList(struct List* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to find the middle node of the linked list
struct Node* findMiddle(struct List* list) {
    struct Node* slow = list->head;
    struct Node* fast = list->head;
    while (fast!= NULL && fast->next!= NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list in-place
void reverseInPlace(struct List* list) {
    struct Node* current = list->head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

// Function to find the length of the linked list
int length(struct List* list) {
    int count = 0;
    struct Node* current = list->head;
    while (current!= NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;

    insertAtBeginning(list, 1);
    insertAtBeginning(list, 2);
    insertAtBeginning(list, 3);
    insertAtBeginning(list, 4);

    printList(list);

    deleteNode(list, 2);

    printList(list);

    reverseInPlace(list);

    printList(list);

    struct Node* middleNode = findMiddle(list);
    printf("Middle node: %d\n", middleNode->data);

    reverse(list);

    printList(list);

    free(list);
    return 0;
}