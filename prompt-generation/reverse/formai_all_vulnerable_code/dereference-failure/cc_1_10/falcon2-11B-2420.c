//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

/*
 * Node structure for the linked list
 */
struct Node
{
    int data;
    struct Node* next;
};

/*
 * Function to create a new node with the given data and link it to the head of the list
 */
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
 * Function to print the contents of the linked list
 */
void printList(struct Node* head)
{
    struct Node* current = head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/*
 * Function to reverse the linked list
 */
void reverseList(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/*
 * Function to insert a node at the beginning of the list
 */
void insertAtHead(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

/*
 * Function to insert a node at the end of the list
 */
void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    struct Node* current = *head;

    while (current->next!= NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

/*
 * Function to delete a node from the list
 */
void deleteNode(struct Node** head, int data)
{
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= data)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    if (prev == NULL)
    {
        *head = current->next;
        free(current);
    }
    else
    {
        prev->next = current->next;
        free(current);
    }
}

/*
 * Function to search for a node in the list
 */
struct Node* search(struct Node* head, int data)
{
    struct Node* current = head;

    while (current!= NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main()
{
    struct Node* head = NULL;

    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);
    insertAtHead(&head, 4);
    insertAtHead(&head, 5);

    printList(head);

    reverseList(&head);
    printList(head);

    deleteNode(&head, 3);
    printList(head);

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 40);
    insertAtHead(&head, 50);

    printList(head);

    struct Node* node = search(head, 50);
    if (node!= NULL)
    {
        printf("Node with data 50 found\n");
    }
    else
    {
        printf("Node with data 50 not found\n");
    }

    return 0;
}