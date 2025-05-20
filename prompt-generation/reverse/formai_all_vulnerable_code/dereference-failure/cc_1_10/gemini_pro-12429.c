//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: visionary
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

// Create a new node
Node* create_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new linked list
LinkedList* create_linked_list() {
    LinkedList *new_list = (LinkedList*) malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(LinkedList *list, int data) {
    Node *new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a node at the end of the linked list
void insert_at_end(LinkedList *list, int data) {
    Node *new_node = create_node(data);
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Insert a node at a specific position in the linked list
void insert_at_position(LinkedList *list, int data, int position) {
    if (position == 0) {
        insert_at_beginning(list, data);
    } else if (position == list->size) {
        insert_at_end(list, data);
    } else {
        Node *new_node = create_node(data);
        Node *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
        list->size++;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(LinkedList *list) {
    if (list->head == NULL) {
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

// Delete a node from the end of the linked list
void delete_from_end(LinkedList *list) {
    if (list->tail == NULL) {
        return;
    }
    Node *current_node = list->head;
    while (current_node->next != list->tail) {
        current_node = current_node->next;
    }
    free(list->tail);
    list->tail = current_node;
    list->tail->next = NULL;
    list->size--;
}

// Delete a node from a specific position in the linked list
void delete_from_position(LinkedList *list, int position) {
    if (position == 0) {
        delete_from_beginning(list);
    } else if (position == list->size - 1) {
        delete_from_end(list);
    } else {
        Node *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        Node *temp = current_node->next;
        current_node->next = temp->next;
        free(temp);
        list->size--;
    }
}

// Search for a node in the linked list
Node* search_node(LinkedList *list, int data) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        if (current_node->data == data) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Print the linked list
void print_linked_list(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d  ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    LinkedList *list = create_linked_list();
    insert_at_beginning(list, 10);
    insert_at_end(list, 20);
    insert_at_position(list, 30, 1);
    print_linked_list(list);  // 10  30  20

    Node *found_node = search_node(list, 30);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    delete_from_beginning(list);
    delete_from_end(list);
    delete_from_position(list, 0);
    print_linked_list(list);  //

    return 0;
}