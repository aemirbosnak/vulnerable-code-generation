//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the node structure as a Linked list element
typedef struct linked_list_element {
    int data;
    struct linked_list_element* next;
} linked_list_element;

// Initialize the head of the linked list
linked_list_element* head = NULL;

// Insert a new element at the beginning of the linked list
void insert_at_beginning(int value) {
    linked_list_element* new_element = (linked_list_element*) malloc(sizeof(linked_list_element));
    new_element->data = value;
    new_element->next = head;
    head = new_element;
}

// Insert a new element at the end of the linked list
void insert_at_end(int value) {
    linked_list_element* new_element = (linked_list_element*) malloc(sizeof(linked_list_element));
    new_element->data = value;
    new_element->next = NULL;
    if (head == NULL) {
        head = new_element;
        return;
    }
    linked_list_element* current_element = head;
    while (current_element->next != NULL) {
        current_element = current_element->next;
    }
    current_element->next = new_element;
}

// Delete the first element of the linked list
void delete_first_element() {
    if (head == NULL) {
        printf("The linked list is empty!");
        return;
    }
    linked_list_element* temporary_element = head;
    head = head->next;
    free(temporary_element);
}

// Delete the last element of the linked list
void delete_last_element() {
    if (head == NULL) {
        printf("The linked list is empty!");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    linked_list_element* current_element = head;
    while (current_element->next->next != NULL) {
        current_element = current_element->next;
    }
    free(current_element->next);
    current_element->next = NULL;
}

// Print all the elements of the linked list
void print_linked_list() {
    linked_list_element* current_element = head;
    while (current_element != NULL) {
        printf("%d ", current_element->data);
        current_element = current_element->next;
    }
    printf("\n");
}

// Main function to test the Linked list operations
int main() {
    insert_at_beginning(2);
    insert_at_beginning(1);
    insert_at_end(3);
    insert_at_end(4);
    printf("The original linked list: ");
    print_linked_list();
    delete_first_element();
    printf("The linked list after deleting the first element: ");
    print_linked_list();
    delete_last_element();
    printf("The linked list after deleting the last element: ");
    print_linked_list();
    return 0;
}