//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for new node.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        perror("Failed to allocate memory for linked list.");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

// Function to add a node at the end of the linked list
void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete the first node from the linked list
void deleteFirstNode(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    printf("First node deleted successfully.\n");
}

// Function to print the linked list
void printList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

// Main function to test the linked list
int main() {
    LinkedList* list = createLinkedList();
    
    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);
    
    printList(list);
    
    printf("Deleting the first node...\n");
    deleteFirstNode(list);
    
    printList(list);
    
    printf("Deleting the first node again...\n");
    deleteFirstNode(list);
    
    printList(list);
    
    freeList(list);
    
    return 0;
}