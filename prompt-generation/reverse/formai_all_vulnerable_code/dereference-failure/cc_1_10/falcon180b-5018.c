//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("\n%d added to the beginning of the list", new_data);
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        printf("\n%d added to the end of the list", new_data);
    } else {
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = new_node;
        printf("\n%d added to the end of the list", new_data);
    }
}

// Function to add a node at a specific position in the list
void addAtPosition(struct Node** head_ref, int data, int pos) {
    struct Node* new_node = newNode(data);
    struct Node* last = *head_ref;
    int count = 1;

    if (pos == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        printf("\n%d added to the beginning of the list", data);
    } else {
        while (last->next!= NULL && count < pos - 1) {
            last = last->next;
            count++;
        }
        new_node->next = last->next;
        last->next = new_node;
        printf("\n%d added at position %d", data, pos);
    }
}

// Function to delete a node with the given data
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("\n%d deleted from the list", key);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
    printf("\n%d deleted from the list", key);
}

// Function to display the list
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    append(&head, 40);
    addAtPosition(&head, 50, 3);

    // Displaying the list
    printf("\nList after adding nodes: ");
    display(head);

    // Deleting a node
    deleteNode(&head, 20);

    // Displaying the list after deleting a node
    printf("\nList after deleting node with data 20: ");
    display(head);

    return 0;
}