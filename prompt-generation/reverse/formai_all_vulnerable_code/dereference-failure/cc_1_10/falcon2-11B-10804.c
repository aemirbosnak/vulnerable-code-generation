//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node* last_node = *head_ref;
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    if (temp == NULL) {
        return;
    }
    if (temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == key) {
            temp->next = temp->next->next;
            free(temp->next);
            return;
        }
        temp = temp->next;
    }
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);
    insert_at_end(&head, 7);
    insert_at_end(&head, 8);
    insert_at_end(&head, 9);
    print_list(head);
    printf("Deleting node with data 5...\n");
    delete_node(&head, 5);
    print_list(head);
    printf("Deleting node with data 2...\n");
    delete_node(&head, 2);
    print_list(head);
    return 0;
}