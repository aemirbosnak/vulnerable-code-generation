//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* addToList(node* head, int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

node* createList(int size)
{
    node* head = NULL;
    node* tail = NULL;
    for (int i = 0; i < size; i++)
    {
        head = addToList(head, i);
    }
    return head;
}

node* reverseList(node* head)
{
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    node* list = createList(5);
    printf("Original List: ");
    while (list!= NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");

    node* reversedList = reverseList(list);
    printf("Reversed List: ");
    while (reversedList!= NULL)
    {
        printf("%d ", reversedList->data);
        reversedList = reversedList->next;
    }
    printf("\n");

    free(list);
    free(reversedList);
    return 0;
}