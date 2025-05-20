//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// define a custom data type called "Node"
typedef struct Node {
    int data;           // data stored in the node
    struct Node* next;  // pointer to the next node in the list
} Node;

// function to insert a new node at the beginning of the list
void insert(Node** head_ref, int new_data) {
    // create a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;

    // set the head of the list to the new node
    *head_ref = new_node;
}

// function to delete a node from the list
void delete_node(Node** head_ref, int key) {
    // if the list is empty, return
    if (*head_ref == NULL)
        return;

    // if the key is at the head of the list, delete it
    if ((*head_ref)->data == key) {
        // create a temporary node to hold the next node in the list
        Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;

        // free the memory occupied by the node being deleted
        free(temp);
        return;
    }

    // search for the key in the list
    Node* curr = *head_ref;
    Node* prev = NULL;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // if the key is not found in the list, return
    if (curr == NULL)
        return;

    // delete the node containing the key
    prev->next = curr->next;
    free(curr);
}

// function to print the list
void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // create an empty linked list
    Node* head = NULL;

    // insert some nodes into the list
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);

    // print the list
    print_list(head);

    // delete a node from the list
    delete_node(&head, 10);

    // print the list again
    print_list(head);

    return 0;
}