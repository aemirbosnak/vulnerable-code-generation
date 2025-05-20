//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// A function to create a new node
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a new node at the beginning of the linked list
node* insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// A function to insert a new node at the end of the linked list
node* insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// A function to insert a new node after a given node
node* insert_after(node *head, int data, int after_data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current = head;
    while (current != NULL) {
        if (current->data == after_data) {
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        current = current->next;
    }
    return head;
}

// A function to delete a node from the linked list
node* delete_node(node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        return head->next;
    }
    node *current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            return head;
        }
        current = current->next;
    }
    return head;
}

// A function to print the linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// A function to sort the linked list using the insertion sort algorithm
node* insertion_sort(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *sorted_list = NULL;
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        sorted_list = insert_at_end(sorted_list, current->data);
        current = next;
    }
    return sorted_list;
}

int main() {
    node *head = NULL;
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 8);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 1);
    print_linked_list(head);
    head = insertion_sort(head);
    print_linked_list(head);
    return 0;
}