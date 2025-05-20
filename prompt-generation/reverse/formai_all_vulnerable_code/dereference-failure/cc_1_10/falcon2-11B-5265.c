//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void insert(int data, int *head);
int delete(int data, int *head);
void display(int *head);

// Structure to represent a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node with the given data at the beginning of the linked list
void insert(int data, int *head)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with the given data from the linked list
int delete(int data, int *head)
{
    struct Node *current = *head;
    struct Node *prev = NULL;
    
    while (current!= NULL && current->data!= data)
    {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL)
    {
        printf("Node not found\n");
        return 0;
    }
    
    if (prev == NULL)
    {
        *head = current->next;
        free(current);
        return 1;
    }
    
    prev->next = current->next;
    free(current);
    return 1;
}

// Function to display the linked list
void display(int *head)
{
    struct Node *current = *head;
    
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int choice, data, flag = 0;
    int *head = NULL;
    
    printf("Linked List Operations Program\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(data, &head);
                break;
                
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                flag = delete(data, &head);
                break;
                
            case 3:
                display(head);
                break;
                
            case 4:
                break;
                
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    
    return 0;
}