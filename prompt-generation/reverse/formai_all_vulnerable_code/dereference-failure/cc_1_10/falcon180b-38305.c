//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory recursively
void* recursive_malloc(size_t size) {
    void* result = malloc(size);
    if (result == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    return result;
}

// Function to free memory recursively
void recursive_free(void* ptr) {
    free(ptr);
}

// Function to create a recursive structure
typedef struct {
    int data;
    struct node* next;
} Node;

// Function to add a node to the end of the list
void add_node(Node** head, int data) {
    Node* new_node = recursive_malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the list
void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List:\n");
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_list(head);
    recursive_free(head);
    return 0;
}