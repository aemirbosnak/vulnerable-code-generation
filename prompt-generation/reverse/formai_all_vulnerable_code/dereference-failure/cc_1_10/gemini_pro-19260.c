//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a new node after a given node
void insert_after(struct Node** head, int data, int after_data) {
    struct Node* new_node = create_node(data);
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == after_data) {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found\n", after_data);
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

// Function to delete a node from the linked list after a given node
void delete_after(struct Node** head, int after_data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == after_data) {
            if (temp->next == NULL) {
                printf("Node with data %d not found\n", after_data);
                return;
            }
            prev = temp;
            temp = temp->next;
            break;
        }
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to print the linked list
void print_linked_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    struct Node* head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(&head, 4, 2);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting from beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list
    printf("Linked list after deleting from end: ");
    print_linked_list(head);

    // Delete a node from the linked list after a given node
    delete_after(&head, 2);

    // Print the linked list
    printf("Linked list after deleting after given node: ");
    print_linked_list(head);

    // Free the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}