//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the Node struct for the Linked List
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define the LinkedList struct to keep track of the head Node
typedef struct LinkedList {
    Node *head;
} LinkedList;

// Initialize an empty LinkedList
void initializeList(LinkedList *list) {
    list->head = NULL;
}

// Insert a new Node at the beginning of the LinkedList
void insertNode(LinkedList *list, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// Delete a Node with the given data from the LinkedList
void deleteNode(LinkedList *list, int data) {
    // If head Node needs to be deleted
    while (list->head != NULL && list->head->data == data) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    
    // If a Node other than head needs to be deleted
    if (list->head != NULL) {
        Node *prev = list->head;
        Node *curr = list->head->next;
        
        while (curr != NULL) {
            if (curr->data == data) {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

// Traverse and print all the Nodes in the LinkedList
void printList(LinkedList *list) {
    Node *curr = list->head;
    
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Main function to test the LinkedList operations
int main() {
    LinkedList myList;
    initializeList(&myList);
    
    insertNode(&myList, 1);
    insertNode(&myList, 2);
    insertNode(&myList, 3);
    insertNode(&myList, 4);
    insertNode(&myList, 5);
    
    printf("Original List: ");
    printList(&myList);
    
    deleteNode(&myList, 3);
    deleteNode(&myList, 1);
    
    printf("Updated List: ");
    printList(&myList);
    
    return 0;
}