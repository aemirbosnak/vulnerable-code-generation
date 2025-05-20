//FormAI DATASET v1.0 Category: Sorting ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

// define struct for linked list
struct node
{
    int data;           // integer data
    struct node *next;  // pointer to next node
};

// function to create a new node
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to print the linked list
void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// function to sort the linked list using insertion sort
void insertionSort(struct node** headRef)
{
    struct node* sortedList = NULL;      // sorted list
    struct node* current = *headRef;     // current node
    while(current != NULL)
    {
        struct node* next = current->next;
        if(sortedList == NULL || current->data < sortedList->data)
        {
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            struct node* temp = sortedList;
            while(temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *headRef = sortedList;
}

int main()
{
    struct node* head = createNode(4);      // create nodes
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Linked list before sorting: ");
    printList(head);
    printf("\n");

    insertionSort(&head);

    printf("Linked list after sorting: ");
    printList(head);
    printf("\n");

    return 0;
}