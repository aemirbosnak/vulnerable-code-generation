//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define a structure for the Doubly Linked List
typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize a doubly linked list
DoublyLinkedList* initList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

// Function to insert a node at the end of the list
void insertEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (!list->head) {
        list->head = newNode;
        return;
    }
    
    Node* temp = list->head;
    while (temp->next) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list in normal order
void displayList(DoublyLinkedList* list) {
    Node* temp = list->head;
    printf("Doubly Linked List (head to tail): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the list in reverse order
void displayListReverse(DoublyLinkedList* list) {
    if (!list->head) {
        return;
    }
    
    Node* temp = list->head;
    while (temp->next) {
        temp = temp->next;
    }
    
    printf("Doubly Linked List (tail to head): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to delete a node with a specific value
void deleteNode(DoublyLinkedList* list, int value) {
    Node* temp = list->head;
    while (temp) {
        if (temp->data == value) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            } else {
                list->head = temp->next; // Node to delete is head
            }

            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", value);
}

// Function to free the list memory
void freeList(DoublyLinkedList* list) {
    Node* temp = list->head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

// Main function demonstrating basic operations
int main() {
    DoublyLinkedList* list = initList();
    
    insertEnd(list, 5);
    insertEnd(list, 10);
    insertEnd(list, 15);
    insertEnd(list, 20);
    
    displayList(list);
    displayListReverse(list);

    printf("Deleting 10 from the list.\n");
    deleteNode(list, 10);
    displayList(list);
    displayListReverse(list);
    
    printf("Deleting 5 from the list.\n");
    deleteNode(list, 5);
    displayList(list);
    displayListReverse(list);

    printf("Attempting to delete value 100 (not in list):\n");
    deleteNode(list, 100);

    freeList(list);
    return 0;
}