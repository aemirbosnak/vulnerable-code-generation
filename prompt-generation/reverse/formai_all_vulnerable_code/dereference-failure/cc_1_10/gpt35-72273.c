//FormAI DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

/* Define a linked list structure */
struct Node {
    int data;
    struct Node* next;
};

/* Function to insert a new node at the beginning of the linked list */
void insertAtBeginning(struct Node** head_ref, int new_data) {
    /* Create a new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    /* Set the data and next pointers of the new node */
    new_node->data = new_data;
    new_node->next = *head_ref;
    
    /* Set the head pointer to the new node */
    *head_ref = new_node;
}

/* Function to insert a new node after a given node */
void insertAfterNode(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    
    /* Create a new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    /* Set the data and next pointers of the new node */
    new_node->data = new_data;
    new_node->next = prev_node->next;
    
    /* Set the next pointer of the previous node to the new node */
    prev_node->next = new_node;
}

/* Function to insert a new node at the end of the linked list */
void insertAtEnd(struct Node** head_ref, int new_data) {
    /* Create a new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node* last = *head_ref;
    
    /* Set the data and next pointers of the new node */
    new_node->data = new_data;
    new_node->next = NULL;
    
    /* If the linked list is empty, set the head pointer to the new node */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    /* Otherwise, traverse the linked list to find the last node */
    while (last->next != NULL) {
        last = last->next;
    }
    
    /* Set the next pointer of the last node to the new node */
    last->next = new_node;
}

/* Function to delete a node with a given key */
void deleteNode(struct Node** head_ref, int key) {
    /* Store head node */
    struct Node* temp = *head_ref, *prev;
    
    /* If the head node itself holds the key to be deleted */
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    /* Search for the key to be deleted, keep track of the previous node */
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    /* If the key was not present in the linked list */
    if (temp == NULL) {
        printf("Key not found");
        return;
    }
    
    /* Unlink the node from the linked list */
    prev->next = temp->next;
    free(temp);
}

/* Function to search for a node with a given key */
void searchNode(struct Node* head, int key) {
    int position = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            printf("Key found at position %d\n", position);
            return;
        }
        position++;
        current = current->next;
    }
    printf("Key not found\n");
}

/* Function to print the linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    /* Initialize an empty linked list */
    struct Node* head = NULL;
    
    /* Insert some nodes into the linked list */
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAfterNode(head->next, 4);
    
    /* Print the linked list */
    printf("Linked list: ");
    printList(head);
    
    /* Search for a node with key value 3 */
    searchNode(head, 3);
    
    /* Delete a node with key value 2 */
    deleteNode(&head, 2);
    
    /* Print the linked list again */
    printf("Linked list after deletion: ");
    printList(head);
    
    return 0;
}