//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

//Structure for creating a node in Linked List
struct node
{
    int value;
    struct node* next;
};

//Function to create a new node
struct node* newNode(int val)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->value = val;
    temp->next = NULL;
    return temp;
}

//Function to add a node at the end of linked list
void append(struct node** head, int val)
{
    struct node* current = *head;
    if(*head == NULL)
    {
        *head = newNode(val);
        return;
    }
    while(current->next != NULL)
        current = current->next;
    current->next = newNode(val);
}

//Function to print the linked list
void printList(struct node* head)
{
    printf("Linked List: ");
    while(head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

//Function to delete all nodes in linked list
void deleteList(struct node** head)
{
    if(*head == NULL)
        return;
    deleteList(&((*head)->next));
    free(*head);
    *head = NULL;
}

int main()
{
    struct node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printList(head);

    deleteList(&head);

    printList(head);

    return 0;
}