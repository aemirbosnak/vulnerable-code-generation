//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: complete
#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node* temp = *head_ref;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    while(temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Key not found in the list");
    } else {
        if(temp == *head_ref) {
            *head_ref = temp->next;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printList(head);
    delete_node(&head, 20);
    printList(head);
    delete_node(&head, 10);
    printList(head);
    delete_node(&head, 40);
    printList(head);
    delete_node(&head, 50);
    printList(head);

    return 0;
}