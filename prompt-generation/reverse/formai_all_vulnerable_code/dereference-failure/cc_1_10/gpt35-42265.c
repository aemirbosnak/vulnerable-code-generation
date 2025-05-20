//FormAI DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// define a structure for a node in the linked list to be sorted
struct node
{
    int data;
    struct node* next;
};

// function to create a new node
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// function to insert a new node into the linked list
void insertNode(struct node** head, int data)
{
    // if head is NULL, create a new node and make it the head
    if (*head == NULL)
    {
        *head = newNode(data);
        return;
    }

    // find the last node in the list
    struct node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // create a new node and insert it at the end of the list
    temp->next = newNode(data);
}

// function to print the linked list
void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to swap the data of two nodes
void swapNodes(struct node* a, struct node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// function to sort the linked list using bubble sort
void bubbleSort(struct node* head)
{
    int swapped = 0;
    struct node* ptr1;
    struct node* lptr = NULL;

    // check for empty list
    if (head == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main()
{
    // create a linked list
    struct node* head = NULL;
    insertNode(&head, 5);
    insertNode(&head, 2);
    insertNode(&head, 8);
    insertNode(&head, 1);
    insertNode(&head, 4);
    insertNode(&head, 6);
    insertNode(&head, 7);
    insertNode(&head, 3);

    // print the unsorted linked list
    printf("Unsorted Linked List: ");
    printList(head);

    // sort the linked list using bubble sort
    bubbleSort(head);

    // print the sorted linked list
    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}