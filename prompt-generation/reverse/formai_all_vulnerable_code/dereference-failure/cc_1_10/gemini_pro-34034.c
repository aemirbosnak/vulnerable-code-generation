//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// Create a new linked list
LinkedList *create_linked_list() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(LinkedList *list, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a node at the end of the linked list
void insert_at_end(LinkedList *list, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
    list->size++;
}

// Insert a node at a specific position in the linked list
void insert_at_position(LinkedList *list, int data, int position) {
    if (position == 0) {
        insert_at_beginning(list, data);
        return;
    }
    if (position == list->size) {
        insert_at_end(list, data);
        return;
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    Node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    list->size++;
}

// Delete a node from the beginning of the linked list
int delete_from_beginning(LinkedList *list) {
    if (list->head == NULL) {
        return -1;
    }
    int data = list->head->data;
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    return data;
}

// Delete a node from the end of the linked list
int delete_from_end(LinkedList *list) {
    if (list->tail == NULL) {
        return -1;
    }
    int data = list->tail->data;
    Node *current_node = list->head;
    if (current_node->next == NULL) {
        free(current_node);
        list->head = NULL;
        list->tail = NULL;
    } else {
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        Node *temp = list->tail;
        list->tail = current_node;
        list->tail->next = NULL;
        free(temp);
    }
    list->size--;
    return data;
}

// Delete a node from a specific position in the linked list
int delete_from_position(LinkedList *list, int position) {
    if (position == 0) {
        return delete_from_beginning(list);
    }
    if (position == list->size - 1) {
        return delete_from_end(list);
    }
    Node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    Node *temp = current_node->next;
    current_node->next = current_node->next->next;
    free(temp);
    list->size--;
    return temp->data;
}

// Print the linked list
void print_linked_list(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_linked_list(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        Node *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    free(list);
}

int main() {
    // Create a linked list
    LinkedList *list = create_linked_list();

    // Insert some nodes into the linked list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_position(list, 3, 1);
    insert_at_position(list, 4, 3);

    // Print the linked list
    print_linked_list(list);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(list);

    // Delete a node from the end of the linked list
    delete_from_end(list);

    // Delete a node from a specific position in the linked list
    delete_from_position(list, 1);

    // Print the linked list
    print_linked_list(list);

    // Free the linked list
    free_linked_list(list);

    return 0;
}