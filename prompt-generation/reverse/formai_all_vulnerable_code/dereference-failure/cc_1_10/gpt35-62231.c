//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the custom data structure called "Node"
typedef struct Node {
    int value;          // Value stored inside the Node
    struct Node* next;  // Pointer to the next Node
} Node;

// Function to add a new Node to the front of the Linked List
void push(Node** head_ref, int new_value) {
    // Allocate memory for the new Node
    Node* new_node = (Node*) malloc(sizeof(Node));
    
    // Update the value of the new Node
    new_node->value = new_value;
    
    // Update the next pointer of the new Node
    new_node->next = (*head_ref);
    
    // Update the head pointer
    (*head_ref) = new_node;
}

// Function to print the Linked List
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

int main() {
    // Initialize the head of the Linked List
    Node* head = NULL;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Populate the Linked List with random values from 1 to 100
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100 + 1;
        push(&head, value);
    }
    
    // Print the Linked List before sorting
    printf("Linked List before sorting: ");
    printList(head);
    printf("\n");
    
    // Sort the Linked List using bubble sort
    for (int i = 0; i < 10; i++) {
        Node* current = head;
        Node* next = head->next;
        while (next != NULL) {
            if (current->value > next->value) {
                int temp = current->value;
                current->value = next->value;
                next->value = temp;
            }
            current = current->next;
            next = next->next;
        }
    }
    
    // Print the Linked List after sorting
    printf("Linked List after sorting: ");
    printList(head);
    printf("\n");
    
    return 0;
}