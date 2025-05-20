//FormAI DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define a structure node with a value and a link to the next node
typedef struct node {
    int value;
    struct node* next;
} Node;

// returns a new, empty node
Node* create_new_node() {
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

// adds a node to the end of the linked list
void add_to_list(Node** head, int value) {
    // if the head is null, add the first node
    if (*head == NULL) {
        *head = create_new_node(); // create a new node
        (*head)->value = value; // set the node's value
    } else {
        // find the last node in the list
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // create a new node and add it to the end of the list
        curr->next = create_new_node();
        curr->next->value = value;
    }
}

// returns true if the list contains the given value, false otherwise
bool contains(Node* head, int value) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->value == value) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int main() {
    // create an empty linked list
    Node* head = NULL;

    // add some nodes to the list
    add_to_list(&head, 5);
    add_to_list(&head, 10);
    add_to_list(&head, 15);

    // print the contents of the list
    printf("List contains: ");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");

    // check if the list contains a value
    if (contains(head, 10)) {
        printf("List contains 10\n");
    } else {
        printf("List does not contain 10\n");
    }

    if (contains(head, 20)) {
        printf("List contains 20\n");
    } else {
        printf("List does not contain 20\n");
    }

    return 0;
}