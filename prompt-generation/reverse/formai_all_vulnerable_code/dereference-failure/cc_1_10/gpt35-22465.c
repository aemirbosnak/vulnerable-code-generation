//FormAI DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a node at the end of a linked list
void insertAtEnd(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// Function to delete a node at a given position in a linked list
void deleteNode(struct Node** head_ref, int position)
{
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node* next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

// Function to print the linked list
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main Function
int main()
{
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Original Linked List: ");
    printList(head);

    // Insert nodes at the end
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);

    printf("\nLinked List after inserting nodes at the end: ");
    printList(head);

    // Delete a node at a given position
    deleteNode(&head, 3);

    printf("\nLinked List after deleting node at position 3: ");
    printList(head);

    return 0;
}