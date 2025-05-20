//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d added at the beginning.\n", new_data);
}

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = new_node;
    printf("%d added at the end.\n", new_data);
}

// Function to add a node at a specific position in the list
void insertNode(Node** head_ref, int new_data, int pos) {
    Node* new_node = newNode(new_data);
    Node* temp = *head_ref;
    if (pos == 1) {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }
    for (int i = 0; i < pos - 2 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        printf("Invalid position.\n");
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf("%d added at position %d.\n", new_data, pos);
}

// Function to delete a node from the list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", key);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Key not found in the list.\n");
    else {
        prev->next = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", key);
    }
}

// Function to display the list
void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    display(head);
    append(&head, 4);
    append(&head, 5);
    display(head);
    insertNode(&head, 6, 3);
    display(head);
    deleteNode(&head, 2);
    display(head);
    deleteNode(&head, 1);
    display(head);
    deleteNode(&head, 6);
    display(head);
    return 0;
}