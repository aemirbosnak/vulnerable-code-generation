//GEMINI-pro DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type for a linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define a custom data type for a linked list
typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;

// Create a new linked list
LinkedList *create_linked_list() {
    LinkedList *new_list = (LinkedList *)malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(LinkedList *list, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(LinkedList *list, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->size == 0) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// Insert a new node at a specific index in the linked list
void insert_at_index(LinkedList *list, int index, int data) {
    if (index == 0) {
        insert_at_beginning(list, data);
    } else if (index == list->size) {
        insert_at_end(list, data);
    } else {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->size++;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *current = list->head;
    list->head = current->next;
    free(current);
    list->size--;
}

// Delete a node from the end of the linked list
void delete_from_end(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    if (list->size == 1) {
        delete_from_beginning(list);
    } else {
        Node *current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node *last_node = current->next;
        current->next = NULL;
        free(last_node);
        list->size--;
    }
}

// Delete a node from a specific index in the linked list
void delete_from_index(LinkedList *list, int index) {
    if (index == 0) {
        delete_from_beginning(list);
    } else if (index == list->size - 1) {
        delete_from_end(list);
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *node_to_delete = current->next;
        current->next = node_to_delete->next;
        free(node_to_delete);
        list->size--;
    }
}

// Print the contents of the linked list
void print_linked_list(LinkedList *list) {
    Node *current = list->head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver code to test the linked list operations
int main() {
    // Create a new linked list
    LinkedList *list = create_linked_list();

    // Insert some data into the linked list
    insert_at_beginning(list, 10);
    insert_at_end(list, 20);
    insert_at_index(list, 1, 15);

    // Print the contents of the linked list
    print_linked_list(list);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(list);

    // Print the contents of the linked list
    print_linked_list(list);

    // Delete a node from the end of the linked list
    delete_from_end(list);

    // Print the contents of the linked list
    print_linked_list(list);

    // Delete a node from a specific index in the linked list
    delete_from_index(list, 0);

    // Print the contents of the linked list
    print_linked_list(list);

    // Free the memory allocated for the linked list
    free(list);

    return 0;
}