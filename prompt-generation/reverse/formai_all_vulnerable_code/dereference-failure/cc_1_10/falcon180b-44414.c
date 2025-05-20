//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: excited
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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL)
        return;

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;

    return;
}

// Function to add a node after a given position in the list
void addNode(struct Node** head_ref, int data, int position) {
    struct Node* new_node = newNode(data);
    struct Node* last = *head_ref;
    int count = 0;

    if (position == 0)
        push(head_ref, data);
    else {
        while (last!= NULL && count!= position - 1) {
            last = last->next;
            count++;
        }

        if (last == NULL)
            printf("Invalid position\n");
        else {
            new_node->next = last->next;
            last->next = new_node;
        }
    }
}

// Function to delete a node with the given data from the list
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* curr = *head_ref;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr = prev;
    *head_ref = curr;
}

int main() {
    struct Node* head = NULL;

    // Add nodes to the list
    push(&head, 5);
    push(&head, 7);
    push(&head, 9);
    append(&head, 11);

    // Print the list
    printList(head);

    // Add a node at position 2
    addNode(&head, 13, 2);

    // Print the list
    printList(head);

    // Delete a node with data 7
    deleteNode(&head, 7);

    // Print the list
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the list
    printList(head);

    return 0;
}