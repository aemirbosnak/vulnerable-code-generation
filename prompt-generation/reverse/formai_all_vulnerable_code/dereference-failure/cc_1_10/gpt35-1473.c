//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* A structure to represent a node in the linked list */
typedef struct Node {
    int data;             // data in each node
    struct Node *next;    // pointer to next node
} Node;

/* Function to create a new node with given data */
Node *newNode(int data) 
{
    Node *new_node = (Node*) malloc(sizeof(Node));    // allocate memory for new node
    new_node->data = data;                            // set the data for new node
    new_node->next = NULL;                            // set next pointer to null
    return new_node;
}

/* Function to add a node at the beginning of the linked list */
void push(Node **head_ref, int new_data)
{
    Node *new_node = newNode(new_data);               // create a new node with given data
    new_node->next = *head_ref;                       // point new node to the current head
    *head_ref = new_node;                             // set the new node as head
}

/* Function to insert a node after a given node */
void insertAfter(Node *prev_node, int new_data) 
{
    if (prev_node == NULL)
    {
        printf("Cannot insert after a NULL node.\n");
        return;
    }
    Node *new_node = newNode(new_data);               // create a new node with given data
    new_node->next = prev_node->next;                 // point new node to next of previous node
    prev_node->next = new_node;                       // set the previous node's next as new node
}

/* Function to append a node at the end of the linked list */
void append(Node **head_ref, int new_data)
{
    Node *new_node = newNode(new_data);               // create a new node with given data
    if (*head_ref == NULL)
    {
        *head_ref = new_node;                         // if empty list, set new node as head
        return;
    }
    Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;                            // traverse to the end of the list
    }
    last->next = new_node;                            // set the last node's next as new node
}

/* Function to delete a node with given key */
void delete(Node **head_ref, int key)
{
    Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;                       // if head node itself has the key, delete it
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;                                  // find previous node of the node to be deleted
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key not found in the list.\n");
        return;
    }
    prev->next = temp->next;                          // unlink the node to be deleted and free memory
    free(temp);
}

/* Function to print the linked list */
void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);                 // print data of current node
        node = node->next;                            // go to next node
    }
    printf("NULL\n");
}

/* Main function to test above functions */
int main() 
{
    Node *head = NULL;                                // start with an empty list
    printf("Empty Linked List: ");
    printList(head);
    push(&head, 6);
    printf("Linked List after Push: 6 -> ");
    printList(head);
    push(&head, 7);
    printf("Linked List after Push: 7 -> 6 -> ");
    printList(head);
    append(&head, 5);
    printf("Linked List after Append: 7 -> 6 -> 5 -> ");
    printList(head);
    append(&head, 4);
    printf("Linked List after Append: 7 -> 6 -> 5 -> 4 -> ");
    printList(head);
    insertAfter(head->next, 10);
    printf("Linked List after InsertAfter: 7 -> 6 -> 10 -> 5 -> 4 -> ");
    printList(head);
    delete(&head, 10);
    printf("Linked List after Delete: 7 -> 6 -> 5 -> 4 -> ");
    printList(head);
    return 0;
}