//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node structure for a doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define the Doubly Linked List structure
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the doubly linked list
DoublyLinkedList* initList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to append a node to the list
void appendNode(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

// Function to display the list
void displayList(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete a node from the list
void deleteNode(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;  // Updating head if needed
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;  // Updating tail if needed
            }
            free(current);
            printf("Deleted %d from the list\n", data);
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found in the list.\n", data);
}

// Function to visualize the linked list
void visualizeList(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("Visualizing the Doubly Linked List:\n");
    while (current != NULL) {
        printf("Node %d: Data = %d\n", (int)(current), current->data);
        if (current->prev != NULL) {
            printf("    Previous Node = %d\n", (int)(current->prev));
        } else {
            printf("    Previous Node = NULL\n");
        }
        if (current->next != NULL) {
            printf("    Next Node = %d\n", (int)(current->next));
        } else {
            printf("    Next Node = NULL\n");
        }
        current = current->next;
    }
    printf("End of visualization.\n");
}

// Main function to demonstrate the doubly linked list
int main() {
    DoublyLinkedList* list = initList();

    // Append nodes to the list
    for (int i = 1; i <= 5; i++) {
        appendNode(list, i);
    }
    
    // Display and visualize the list
    displayList(list);
    visualizeList(list);

    // Deleting a node and visualizing again
    deleteNode(list, 3);
    displayList(list);
    visualizeList(list);

    // Freeing the remaining nodes
    deleteNode(list, 1);
    deleteNode(list, 2);
    deleteNode(list, 4);
    deleteNode(list, 5);
    
    free(list); // free the list structure

    return 0;
}