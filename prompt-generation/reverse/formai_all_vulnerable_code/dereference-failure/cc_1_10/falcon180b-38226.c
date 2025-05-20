//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void push(struct node** head_ref, int new_data) {
    struct node* node = newNode(new_data);
    node->next = (*head_ref);
    (*head_ref) = node;
    printf("%d added to the list\n", new_data);
}

// Function to add a node at the beginning of the list
void push_front(struct node** head_ref, int new_data) {
    struct node* node = newNode(new_data);
    node->next = (*head_ref);
    (*head_ref) = node;
    printf("%d added to the list\n", new_data);
}

// Function to remove a node from the list
void deleteNode(struct node **head_ref, int key) {
    struct node* temp = *head_ref, *prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);            
        return;
    }

    // Delete node
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list\n", key);
}

// Function to search for a node in the list
struct node* search(struct node* head, int key) {
    struct node* current = head;
    while(current!= NULL) {
        if(current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    struct node* head = NULL;

    // Add nodes
    push(&head, 10);
    push(&head, 20);
    push_front(&head, 30);
    push_front(&head, 40);

    // Print the list
    printf("List: ");
    printList(head);

    // Search for a node
    struct node* result = search(head, 20);
    if(result!= NULL) {
        printf("Node found with value %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node
    deleteNode(&head, 30);

    // Print the list again
    printf("List after deleting 30: ");
    printList(head);

    return 0;
}