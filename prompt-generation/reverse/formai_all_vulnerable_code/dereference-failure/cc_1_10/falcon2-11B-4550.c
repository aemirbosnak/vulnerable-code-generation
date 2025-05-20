//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>

// Structure definition for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push a new node at the beginning of the linked list
void push_front(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to push a new node at the end of the linked list
void push_back(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct Node* current = (*head_ref);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to remove and return the first node in the linked list
struct Node* pop_front(struct Node** head_ref) {
    struct Node* temp = (*head_ref);
    if ((*head_ref) == NULL) {
        return NULL;
    }
    (*head_ref) = (*head_ref)->next;
    free(temp);
    return temp;
}

// Function to remove and return the last node in the linked list
struct Node* pop_back(struct Node** head_ref) {
    struct Node* temp = (*head_ref);
    if ((*head_ref) == NULL) {
        return NULL;
    }
    if ((*head_ref)->next == NULL) {
        free(temp);
        (*head_ref) = NULL;
        return temp;
    }
    struct Node* prev = (*head_ref)->next;
    struct Node* current = (*head_ref)->next->next;
    free(prev);
    (*head_ref) = current;
    return temp;
}

// Function to return a pointer to the first node in the linked list
struct Node* front(struct Node* head) {
    return head;
}

// Function to return a pointer to the last node in the linked list
struct Node* back(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    return current;
}

// Function to return the number of nodes in the linked list
int size(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current!= NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to remove all nodes from the linked list
void clear(struct Node** head_ref) {
    struct Node* current = (*head_ref);
    while (current!= NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    (*head_ref) = NULL;
}

// Function to print the data of each node in the linked list
void print(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the usage of linked list operations
int main() {
    struct Node* head = NULL;

    // Push nodes at the beginning and end of the linked list
    push_front(&head, 5);
    push_front(&head, 10);
    push_back(&head, 15);
    push_back(&head, 20);

    // Print the linked list
    printf("Linked list before pop operations: ");
    print(head);

    // Pop nodes from the front and back of the linked list
    struct Node* front_node = pop_front(&head);
    printf("Node popped from the front: %d\n", front_node->data);
    struct Node* back_node = pop_back(&head);
    printf("Node popped from the back: %d\n", back_node->data);

    // Print the updated linked list
    printf("Linked list after pop operations: ");
    print(head);

    return 0;
}