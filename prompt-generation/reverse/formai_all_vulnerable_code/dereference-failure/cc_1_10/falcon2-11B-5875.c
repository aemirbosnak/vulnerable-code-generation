//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct Node {
    char name[50];
    struct Node *next;
} Node;

// Function to insert a new node at the beginning of the list
Node* insert_at_beginning(Node *head, char* name) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }
    strcpy(new_node->name, name);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node after a specified node
Node* insert_after(Node *head, char* name, Node* position) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }
    strcpy(new_node->name, name);
    new_node->next = position->next;
    position->next = new_node;
    return new_node;
}

// Function to delete a node from the list
void delete_node(Node *node) {
    Node *temp = node->next;
    free(node);
    node = temp;
}

// Function to display the mailing list
void display_list(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Function to search for a name in the list
int search_name(Node *head, char* name) {
    Node *current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0)
            return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    // Initialize the mailing list
    Node *head = NULL;
    char name[50];

    // Insert some subscribers into the list
    head = insert_at_beginning(head, "John Doe");
    head = insert_after(head, "Jane Doe", head);
    head = insert_after(head, "Alice Smith", head);
    head = insert_after(head, "Bob Johnson", head);

    // Display the mailing list
    printf("Mailing List:\n");
    display_list(head);

    // Search for a name in the list
    printf("Is \"John Doe\" in the list? %s\n", search_name(head, "John Doe")? "Yes" : "No");
    printf("Is \"Jane Smith\" in the list? %s\n", search_name(head, "Jane Smith")? "Yes" : "No");
    printf("Is \"Bob Johnson\" in the list? %s\n", search_name(head, "Bob Johnson")? "Yes" : "No");

    // Delete a subscriber from the list
    delete_node(head);
    printf("Mailing List after deleting \"Jane Doe\":\n");
    display_list(head);

    return 0;
}