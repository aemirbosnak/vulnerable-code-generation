//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

/* Define node structure */
struct Node
{
    int data;
    struct Node* next;
};

void createNode(struct Node** head, int data);
void addNode(struct Node* head, int data);
void deleteNode(struct Node* head, int data);
void traverseList(struct Node* head);

int main()
{
    struct Node* head = NULL;

    createNode(&head, 10);
    createNode(&head, 20);
    createNode(&head, 30);
    createNode(&head, 40);
    createNode(&head, 50);

    printf("Original List:\n");
    traverseList(head);

    deleteNode(head, 30);

    printf("\nList after deleting node with value 30:\n");
    traverseList(head);

    deleteNode(head, 10);

    printf("\nList after deleting node with value 10:\n");
    traverseList(head);

    return 0;
}

/* Function to create a new node */
void createNode(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
        *head = newNode;
    else
    {
        struct Node* temp = *head;
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

/* Function to add a new node */
void addNode(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else
    {
        struct Node* temp = head;
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

/* Function to delete a node */
void deleteNode(struct Node* head, int data)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    if(temp!= NULL && temp->data == data)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

/* Function to traverse the list */
void traverseList(struct Node* head)
{
    printf("List: ");
    while(head!= NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}