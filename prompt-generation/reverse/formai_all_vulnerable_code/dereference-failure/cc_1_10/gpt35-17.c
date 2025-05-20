//FormAI DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createList(struct node **head, int n)
{
    struct node *newNode, *temp;
    int data, i;

    *head = (struct node *)malloc(sizeof(struct node));

    if(*head == NULL)
    {
        printf("Memory cannot be allocated!\n");
        exit(0);
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);

    (*head)->data = data;
    (*head)->next = NULL;
    temp = *head;

    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Memory cannot be allocated!\n");
            exit(0);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }

    printf("Linked list created successfully!\n");
}

void displayList(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertBegin(struct node **head)
{
    int data;
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory cannot be allocated!\n");
        exit(0);
    }

    printf("Enter data to be inserted: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;

    printf("Data inserted successfully at beginning of the list!\n");
}

void insertEnd(struct node **head)
{
    int data;
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory cannot be allocated!\n");
        exit(0);
    }

    printf("Enter data to be inserted: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        printf("Data inserted successfully at end of the list!\n");
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Data inserted successfully at end of the list!\n");
}

void insertAfter(struct node *head)
{
    int data, position, i;
    struct node *newNode, *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position where you want to insert a new node: ");
    scanf("%d", &position);

    temp = head;

    for(i=1; i<position; i++)
    {
        if(temp == NULL)
        {
            printf("Cannot insert at this position!\n");
            return;
        }

        temp = temp->next;
    }

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory cannot be allocated!\n");
        exit(0);
    }

    printf("Enter data to be inserted: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Data inserted successfully!\n");
}

void deleteBegin(struct node **head)
{
    struct node *temp;

    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    printf("%d deleted successfully from the beginning of the list!\n", temp->data);

    free(temp);
}

void deleteEnd(struct node **head)
{
    struct node *temp, *prev;

    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if((*head)->next == NULL)
    {
        printf("%d deleted successfully from the end of the list!\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("%d deleted successfully from the end of the list!\n", temp->data);

    free(temp);
    prev->next = NULL;
}

void deleteNode(struct node **head)
{
    int data;
    struct node *temp, *prev;

    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter data of node to be deleted: ");
    scanf("%d", &data);

    if((*head)->data == data)
    {
        temp = (*head);
        *head = (*head)->next;

        printf("%d deleted successfully from the list!\n", data);

        free(temp);
        return;
    }

    prev = NULL;
    temp = *head;

    while(temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("%d not found in the list!\n", data);
        return;
    }

    prev->next = temp->next;

    printf("%d deleted successfully from the list!\n", data);

    free(temp);
}

int main()
{
    struct node *head = NULL;
    int n, choice;

    while(1)
    {
        printf("------------------------------------\n");
        printf("    OPERATIONS ON LINKED LIST\n");
        printf("------------------------------------\n");
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node after a position\n");
        printf("6. Delete a node from the beginning\n");
        printf("7. Delete a node from the end\n");
        printf("8. Delete a node with given data\n");
        printf("9. Exit\n");
        printf("------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of nodes to be created: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                insertBegin(&head);
                break;
            case 4:
                insertEnd(&head);
                break;
            case 5:
                insertAfter(head);
                break;
            case 6:
                deleteBegin(&head);
                break;
            case 7:
                deleteEnd(&head);
                break;
            case 8:
                deleteNode(&head);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}