//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

// A function to create a new node
Node* create_node(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// A function to insert node at beginning of linked list
void insert_at_beginning(Node** head_ref, int data) {
    Node* newNode = create_node(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// A function to insert node at end of linked list
void insert_at_end(Node** head_ref, int data) {
    Node* newNode = create_node(data);
    Node* temp = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// A function to delete a node
void delete_node(Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;
    Node* temp = *head_ref;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        Node* prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    Node* prev = temp;
    prev->next = temp->next;
    free(temp);
}

// A function to print the linked list
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Test the functions
int main() {
    Node* head = NULL;
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 2);
    insert_at_end(&head, 6);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    return 0;
}