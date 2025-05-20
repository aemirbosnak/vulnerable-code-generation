//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 10

typedef struct ListNode
{
    char name[20];
    struct ListNode* next;
} ListNode;

void addToList(struct ListNode** head, char* name)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void printList(struct ListNode* head)
{
    while (head)
    {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* head = NULL;

    addToList(&head, "John Doe");
    addToList(&head, "Jane Doe");
    addToList(&head, "Peter Pan");

    printList(head);

    return 0;
}