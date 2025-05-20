//Gemma-7B DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ((*head)->next = newNode);
    }
}

int compareStrings(char* str1, char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] - str2[i] != 0)
        {
            return str1[i] - str2[i];
        }
        i++;
    }

    return 0;
}

void sortStrings(Node** head)
{
    int size = 0;
    Node* current = *head;
    while (current)
    {
        insertAtTail(&head, current->data);
        size++;
        current = current->next;
    }

    qsort(head, size, sizeof(char*), compareStrings);

    current = *head;
    while (current)
    {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Node* head = NULL;
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'e');
    insertAtTail(&head, 'b');

    sortStrings(&head);

    return 0;
}