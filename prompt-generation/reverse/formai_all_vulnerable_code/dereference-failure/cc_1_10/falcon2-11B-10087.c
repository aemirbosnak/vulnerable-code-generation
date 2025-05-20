//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Node structure for the Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the beginning of the Linked List
void add_node(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete a node from the Linked List
void delete_node(struct Node** head_ref, int data) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return; // Data not found
    }

    if (prev == NULL) {
        *head_ref = temp->next;
        free(temp);
        return; // Last node
    }

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node in the Linked List
int search_node(struct Node* head, int data) {
    struct Node* temp = head;

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0; // Data not found
    } else {
        return 1; // Data found
    }
}

// Function to print the Linked List
void print_list(struct Node* head) {
    struct Node* temp = head;

    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the Linked List
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    // Deleting a node from the Linked List
    delete_node(&head, 3);

    // Searching for a node in the Linked List
    int found = search_node(head, 4);
    if (found == 1) {
        printf("Node found!\n");
    } else {
        printf("Node not found!\n");
    }

    // Printing the Linked List
    print_list(head);

    return 0;
}