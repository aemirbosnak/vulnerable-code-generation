//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
struct Node* insert_at_beginning(struct Node *head, int data) {
    struct Node *new_node = create_node(data);
    if (new_node == NULL) {
        return NULL;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of the list
struct Node* insert_at_end(struct Node *head, int data) {
    struct Node *new_node = create_node(data);
    if (new_node == NULL) {
        return NULL;
    }
    if (head == NULL) {
        head = new_node;
        return head;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to insert a node after a given node
struct Node* insert_after_node(struct Node *head, int data, int after_data) {
    struct Node *new_node = create_node(data);
    if (new_node == NULL) {
        return NULL;
    }
    if (head == NULL) {
        printf("Error: List is empty.\n");
        free(new_node);
        return NULL;
    }
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == after_data) {
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        current = current->next;
    }
    printf("Error: Node with data %d not found.\n", after_data);
    free(new_node);
    return head;
}

// Function to delete a node from the beginning of the list
struct Node* delete_from_beginning(struct Node *head) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the list
struct Node* delete_from_end(struct Node *head) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    struct Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
    return head;
}

// Function to delete a node after a given node
struct Node* delete_after_node(struct Node *head, int after_data) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return NULL;
    }
    struct Node *current = head;
    struct Node *previous = NULL;
    while (current != NULL) {
        if (current->data == after_data) {
            if (current->next == NULL) {
                printf("Error: Node not found.\n");
                return head;
            }
            previous = current;
            current = current->next;
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Node not found.\n");
        return head;
    }
    previous->next = current->next;
    free(current);
    return head;
}

// Function to print the list
void print_list(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty list
    struct Node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after_node(head, 30, 10);
    head = insert_at_end(head, 40);
    head = insert_after_node(head, 50, 30);

    // Print the list
    printf("List before operations:\n");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Delete a node after a given node
    head = delete_after_node(head, 30);

    // Print the list
    printf("\nList after operations:\n");
    print_list(head);

    return 0;
}