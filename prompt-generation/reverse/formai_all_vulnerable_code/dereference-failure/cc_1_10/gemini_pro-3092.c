//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// Create a new linked list
LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a new node at the beginning of the linked list
void insertAtBeginning(LinkedList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    if (list->head == NULL) {
        list->tail = newNode;
    }
    list->head = newNode;
    list->size++;
}

// Insert a new node at the end of the linked list
void insertAtEnd(LinkedList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    list->size++;
}

// Insert a new node at a specific position in the linked list
void insertAtPosition(LinkedList *list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    if (position == list->size) {
        insertAtEnd(list, data);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}

// Delete the first node in the linked list
void deleteFirstNode(LinkedList *list) {
    if (list->head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(temp);
    list->size--;
}

// Delete the last node in the linked list
void deleteLastNode(LinkedList *list) {
    if (list->head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    Node *current = list->head;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        previous->next = NULL;
        list->tail = previous;
    }
    free(current);
    list->size--;
}

// Delete a node at a specific position in the linked list
void deleteAtPosition(LinkedList *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 0) {
        deleteFirstNode(list);
        return;
    }
    if (position == list->size - 1) {
        deleteLastNode(list);
        return;
    }
    Node *current = list->head;
    Node *previous = NULL;
    for (int i = 0; i < position; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    list->size--;
}

// Print the linked list
void printLinkedList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Reverse a linked list
LinkedList *reverseLinkedList(LinkedList *list) {
    LinkedList *newLinkedList = createLinkedList();
    Node *current = list->head;
    while (current != NULL) {
        insertAtBeginning(newLinkedList, current->data);
        current = current->next;
    }
    return newLinkedList;
}

// Get the size of the linked list
int getLinkedListSize(LinkedList *list) {
    return list->size;
}

// Test the linked list operations
int main() {
    LinkedList *list = createLinkedList();
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtEnd(list, 30);
    insertAtEnd(list, 40);
    insertAtPosition(list, 50, 2);
    printf("Original linked list: ");
    printLinkedList(list);
    deleteFirstNode(list);
    printf("Linked list after deleting the first node: ");
    printLinkedList(list);
    deleteLastNode(list);
    printf("Linked list after deleting the last node: ");
    printLinkedList(list);
    deleteAtPosition(list, 2);
    printf("Linked list after deleting the node at position 2: ");
    printLinkedList(list);
    LinkedList *reversedLinkedList = reverseLinkedList(list);
    printf("Reversed linked list: ");
    printLinkedList(reversedLinkedList);
    printf("Size of the original linked list: %d\n", getLinkedListSize(list));
    printf("Size of the reversed linked list: %d\n", getLinkedListSize(reversedLinkedList));
    return 0;
}