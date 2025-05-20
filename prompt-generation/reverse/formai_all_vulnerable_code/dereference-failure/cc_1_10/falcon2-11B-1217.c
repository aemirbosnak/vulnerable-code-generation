//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// Node definition
struct Node
{
    int data;
    struct Node* next;
};

// Function to initialize new node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data)
{
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main()
{
    struct Node* head = NULL;
    
    // Inserting elements in the linked list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    // Printing the linked list
    printf("Linked List: ");
    printList(head);
    
    return 0;
}