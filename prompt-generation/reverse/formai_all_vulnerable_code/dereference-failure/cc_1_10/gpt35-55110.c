//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define our node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define our linked list structure
typedef struct list {
    Node* head;
} List;

// Create a new node
Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Add a node to the linked list
void add_node(List* list, int data) {
    // If the list is empty, create a new node and make it the head
    if (list->head == NULL) {
        list->head = create_node(data);
        return;
    }

    // If the list is not empty, add the node to the end of the list
    Node* current_node = list->head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = create_node(data);
}

// Remove the head node from the linked list
void remove_head(List* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

// Print the contents of the linked list
void print_list(List* list) {
    printf("List contents: ");
    Node* current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    List list;
    list.head = NULL;

    // Add some nodes to the list
    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);
    add_node(&list, 4);

    // Print the list
    print_list(&list);

    // Remove the head node
    remove_head(&list);

    // Print the list again
    print_list(&list);

    return 0;
}