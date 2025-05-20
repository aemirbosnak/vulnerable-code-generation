//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
node* insert_at_beginning(node* head, int data) {
    node* new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of the linked list
node* insert_at_end(node* head, int data) {
    node* new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a node at a specific position in the linked list
node* insert_at_position(node* head, int data, int position) {
    if (position == 1) {
        return insert_at_beginning(head, data);
    }
    node* new_node = create_node(data);
    node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete a node from the beginning of the linked list
node* delete_from_beginning(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
node* delete_from_end(node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node from a specific position in the linked list
node* delete_from_position(node* head, int position) {
    if (position == 1) {
        return delete_from_beginning(head);
    }
    node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return head;
    }
    node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return head;
}

// Function to search for a node in the linked list
node* search_node(node* head, int data) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the linked list
void print_linked_list(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node* head = NULL;
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    // Print the linked list
    printf("Original Linked List: ");
    print_linked_list(head);

    // Insert a node at the beginning of the linked list
    head = insert_at_beginning(head, 0);

    // Print the linked list
    printf("Linked List after inserting a node at the beginning: ");
    print_linked_list(head);

    // Insert a node at the end of the linked list
    head = insert_at_end(head, 6);

    // Print the linked list
    printf("Linked List after inserting a node at the end: ");
    print_linked_list(head);

    // Insert a node at a specific position in the linked list
    head = insert_at_position(head, 7, 3);

    // Print the linked list
    printf("Linked List after inserting a node at position 3: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);

    // Print the linked list
    printf("Linked List after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    head = delete_from_end(head);

    // Print the linked list
    printf("Linked List after deleting a node from the end: ");
    print_linked_list(head);

    // Delete a node from a specific position in the linked list
    head = delete_from_position(head, 3);

    // Print the linked list
    printf("Linked List after deleting a node from position 3: ");
    print_linked_list(head);

    // Search for a node in the linked list
    node* found_node = search_node(head, 4);
    if (found_node == NULL) {
        printf("Node not found.\n");
    } else {
        printf("Node found: %d\n", found_node->data);
    }

    return 0;
}