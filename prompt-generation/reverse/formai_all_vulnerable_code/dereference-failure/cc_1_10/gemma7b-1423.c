//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

void parser(char* str)
{
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = str[i];
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;

    for (Node* current = head; current; current = current->next)
    {
        printf("%c ", current->data);
    }

    printf("\n");
}

int main()
{
    parser("abc");
    parser("123");
    parser("abc123");

    return 0;
}