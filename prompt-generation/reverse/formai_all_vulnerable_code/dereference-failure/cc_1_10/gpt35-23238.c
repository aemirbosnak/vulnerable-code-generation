//FormAI DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>

// A simple linked-list to demonstrate memory allocation and management
typedef struct Node {
    int value;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    
    // Allocate memory for 5 nodes
    for (int i = 0; i < 5; i++) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("Error: Unable to allocate memory!");
            exit(EXIT_FAILURE);
        }
        newNode->value = i;
        newNode->next = NULL;
        
        // Add the new node to the end of the list
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    // Print the linked-list
    printf("Linked-list values: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    
    // De-allocate all the memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}