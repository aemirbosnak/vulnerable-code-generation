//FormAI DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

/* Structure for each node in the linked list */
typedef struct node
{
    int data;
    struct node *next;
} Node;

/* Function prototypes */
Node* createNode(int data);
void insertNode(Node **head, int data);
void deleteNode(Node **head, int data);
void displayList(Node *head);

int main()
{
    Node *head = NULL; // Initialize empty linked list

    // Insert 3 nodes
    insertNode(&head, 2);
    insertNode(&head, 5);
    insertNode(&head, 7);

    printf("Linked list after inserting 2, 5, 7:\n");
    displayList(head);

    printf("\n");

    // Delete node with data value 5
    printf("Deleting node with data value 5...\n");
    deleteNode(&head, 5);

    printf("Linked list after deleting node with data value 5:\n");
    displayList(head);

    return 0;
}

/* Function to create a new node with given data */
Node* createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* Function to insert a new node with given data at the end of the linked list */
void insertNode(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        Node *currentNode = *head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(data);
    }
}

/* Function to delete the first node with given data from the linked list */
void deleteNode(Node **head, int data)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->data == data)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        Node *currentNode = *head;
        while (currentNode->next != NULL && currentNode->next->data != data)
        {
            currentNode = currentNode->next;
        }
        if (currentNode->next != NULL)
        {
            Node *temp = currentNode->next;
            currentNode->next = temp->next;
            free(temp);
        }
    }
}

/* Function to display the contents of the linked list */
void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        Node *currentNode = head;
        while (currentNode != NULL)
        {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
    }
}