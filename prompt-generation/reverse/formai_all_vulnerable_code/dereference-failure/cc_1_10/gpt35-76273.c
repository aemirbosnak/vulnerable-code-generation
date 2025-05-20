//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

//Defining a structure for the node
struct Node
{
    int data;
    struct Node* next;
};

//Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data)
{
    //Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    //Update the data and next pointer of the new node
    newNode->data = data;
    newNode->next = *head;

    //Update the head pointer to the new node
    *head = newNode;
}

//Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data)
{
    //Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    //Update the data and next pointer of the new node
    newNode->data = data;
    newNode->next = NULL;

    //If the list is empty, make the new node as head
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    //Traverse the list to find the last node
    while (last->next != NULL)
        last = last->next;

    //Change the next of last node
    last->next = newNode;
    return;
}

//Function to insert a node at a given position in the linked list
void insertAtPosition(struct Node** head, int data, int position)
{
    //If the position is 0, insert the node at the beginning
    if (position == 0)
    {
        insertAtBeginning(head, data);
        return;
    }

    //Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = NULL;
    struct Node* current = *head;

    //Update the data and next pointer of the new node
    newNode->data = data;
    newNode->next = NULL;

    //Traverse the list to find the node at the given position
    int count = 0;
    while (count < position && current != NULL)
    {
        prev = current;
        current = current->next;
        count++;
    }

    //If the position is greater than the length of the list, insert the node at the end
    if (current == NULL)
    {
        prev->next = newNode;
        return;
    }

    //Insert the node at the given position
    newNode->next = current;
    prev->next = newNode;
}

//Function to delete a node at a given position in the linked list
void deleteAtPosition(struct Node** head, int position)
{
    //If the list is empty, return
    if (*head == NULL)
        return;

    struct Node* prev = NULL;
    struct Node* current = *head;

    //If the position is 0, delete the first node
    if (position == 0)
    {
        *head = current->next;
        free(current);
        return;
    }

    //Traverse the list to find the node at the given position
    int count = 0;
    while (count < position && current != NULL)
    {
        prev = current;
        current = current->next;
        count++;
    }

    //If the position is greater than the length of the list, return
    if (current == NULL)
        return;

    //Delete the node at the given position
    prev->next = current->next;
    free(current);
}

//Function to print the linked list
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

//Main function
int main()
{
    struct Node* head = NULL;

    //Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    //Print the linked list
    printf("Linked List after inserting nodes at the beginning: ");
    printList(head);

    //Insert nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    //Print the linked list
    printf("\nLinked List after inserting nodes at the end: ");
    printList(head);

    //Insert nodes at a given position
    insertAtPosition(&head, 8, 2);
    insertAtPosition(&head, 9, 5);
    insertAtPosition(&head, 10, 8);

    //Print the linked list
    printf("\nLinked List after inserting nodes at a given position: ");
    printList(head);

    //Delete nodes at a given position
    deleteAtPosition(&head, 0);
    deleteAtPosition(&head, 3);
    deleteAtPosition(&head, 7);

    //Print the linked list
    printf("\nLinked List after deleting nodes at a given position: ");
    printList(head);

    return 0;
}