//FormAI DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// define a linked list node
struct Node {
    int data;
    struct Node* next;
};

// function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    // create a new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    // update the head pointer
    *head = new_node;
}

// function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    // create a new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    // if the list is empty
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    // traverse to the last node
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// function to delete a node with the given key from the linked list
void deleteNode(struct Node** head, int key) {
    // check if the list is empty
    if (*head == NULL) {
        return;
    }
    // if the head node has the key
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    // find the previous node of the node to be deleted
    struct Node* prev = *head;
    while (prev->next != NULL && prev->next->data != key) {
        prev = prev->next;
    }
    // if the node with the key isn't present in the list
    if (prev->next == NULL) {
        return;
    }
    // delete the node
    struct Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// main function
int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);
    printList(head);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    printf("Number of nodes: %d\n", countNodes(head));
    return 0;
}