//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for the node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for the linked list
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Create a new node with the given data
Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Add a new node to the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* node = create_node(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->size++;
}

// Remove a node with the given data from the linked list
Node* remove_node(LinkedList* list, int data) {
    Node* head = list->head;
    Node* prev = NULL;
    while (head!= NULL && head->data!= data) {
        prev = head;
        head = head->next;
    }
    if (head == NULL) {
        return NULL;
    }
    if (prev == NULL) {
        list->head = head->next;
    } else {
        prev->next = head->next;
    }
    list->size--;
    return head;
}

// Print the contents of the linked list
void print_list(LinkedList* list) {
    Node* head = list->head;
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    printf("List contents:\n");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new linked list
    LinkedList list = {NULL, 0};

    // Add some nodes to the list
    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);

    // Print the contents of the list
    print_list(&list);

    // Remove a node from the list
    Node* removed_node = remove_node(&list, 2);
    if (removed_node!= NULL) {
        printf("Removed node: %d\n", removed_node->data);
    }

    // Print the contents of the list again
    print_list(&list);

    return 0;
}