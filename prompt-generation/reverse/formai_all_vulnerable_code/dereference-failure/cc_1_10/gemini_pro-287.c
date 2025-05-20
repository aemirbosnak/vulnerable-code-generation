//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node *next;
};

// A linked list
struct List {
    struct Node *head;
    struct Node *tail;
    int size;
};

// Create a new linked list
struct List *create_list() {
    struct List *list = (struct List *)malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a new element at the beginning of the linked list
void insert_at_beginning(struct List *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a new element at the end of the linked list
void insert_at_end(struct List *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Insert a new element at a given position in the linked list
void insert_at_position(struct List *list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        insert_at_beginning(list, data);
        return;
    }
    if (position == list->size) {
        insert_at_end(list, data);
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    struct Node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    list->size++;
}

// Delete an element from the beginning of the linked list
void delete_from_beginning(struct List *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

// Delete an element from the end of the linked list
void delete_from_end(struct List *list) {
    if (list->tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *current_node = list->head;
    while (current_node->next != list->tail) {
        current_node = current_node->next;
    }
    free(list->tail);
    list->tail = current_node;
    list->tail->next = NULL;
    list->size--;
}

// Delete an element from a given position in the linked list
void delete_from_position(struct List *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        delete_from_beginning(list);
        return;
    }
    if (position == list->size - 1) {
        delete_from_end(list);
        return;
    }
    struct Node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    struct Node *temp = current_node->next;
    current_node->next = temp->next;
    free(temp);
    list->size--;
}

// Print the elements of the linked list
void print_list(struct List *list) {
    struct Node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new linked list
    struct List *list = create_list();

    // Insert some elements into the linked list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_position(list, 3, 1);
    insert_at_position(list, 4, 3);
    insert_at_position(list, 5, 5);

    // Print the linked list
    printf("Linked list: ");
    print_list(list);

    // Delete some elements from the linked list
    delete_from_beginning(list);
    delete_from_end(list);
    delete_from_position(list, 2);

    // Print the linked list
    printf("Linked list after deletions: ");
    print_list(list);

    return 0;
}