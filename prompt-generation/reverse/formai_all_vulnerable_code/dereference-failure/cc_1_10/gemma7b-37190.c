//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
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

void traverse(Node* head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    char input[100];
    printf("Enter a binary number: ");
    scanf("%s", input);

    int i = 0;
    for (int length = 0; input[length] != '\0'; length++)
    {
        insertAtTail(&head, input[length] - '0');
    }

    traverse(head);

    printf("\nThe converted number is:");

    traverse(head);

    return 0;
}