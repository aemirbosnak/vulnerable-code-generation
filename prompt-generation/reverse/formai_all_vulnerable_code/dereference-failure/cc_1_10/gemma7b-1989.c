//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void insertNode(Node **head, char *data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main()
{
    Node *head = NULL;

    char buffer[MAX_BUFFER_SIZE];
    printf("Enter a C syntax expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    char *data = strtok(buffer, " ");

    while (data)
    {
        insertNode(&head, data);
        data = strtok(NULL, " ");
    }

    printf("Parsing result:\n");
    for (Node *node = head; node; node = node->next)
    {
        printf("%s ", node->data);
    }

    printf("\n");

    return 0;
}