//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Definition of a linked list
struct LinkedList {
    struct Node* head;
};

// Function to insert a node at the beginning of the list
void insert_head(struct LinkedList* list, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

// Function to insert a node at the end of the list
void insert_tail(struct LinkedList* list, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        list->head->next = new_node;
    }
    list->head = new_node;
}

// Function to print the list
void print_list(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Example program
int main() {
    struct LinkedList list;

    // Insert some nodes
    insert_head(&list, 1);
    insert_head(&list, 2);
    insert_tail(&list, 3);
    insert_tail(&list, 4);

    // Print the list
    print_list(&list);

    return 0;
}