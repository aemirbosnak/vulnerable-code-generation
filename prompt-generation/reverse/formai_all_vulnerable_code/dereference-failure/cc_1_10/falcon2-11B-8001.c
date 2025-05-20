//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to initialize the head of the Linked List
void init(struct Node** head_ref) {
    *head_ref = NULL;
}

// Function to insert a new node at the beginning of the Linked List
void insert_at_beginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the Linked List
void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct Node* temp = *head_ref;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a new node after a specific node in the Linked List
void insert_after_node(struct Node** head_ref, int new_data, int target_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct Node* temp = *head_ref;
    while(temp->data!= target_data) {
        if(temp->next == NULL) {
            printf("Target node not found\n");
            return;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node from the Linked List
void delete_node(struct Node** head_ref, int target_data) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    while(temp!= NULL && temp->data!= target_data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Target node not found\n");
        return;
    }
    if(prev == NULL) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the elements of the Linked List
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    init(&head);
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 4);
    insert_at_end(&head, 5);
    insert_after_node(&head, 10, 3);
    display(head);
    printf("Deleting node with data 3...\n");
    delete_node(&head, 3);
    display(head);
    return 0;
}