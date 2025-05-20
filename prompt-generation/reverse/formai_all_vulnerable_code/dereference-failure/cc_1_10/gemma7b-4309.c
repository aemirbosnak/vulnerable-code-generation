//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main()
{
    Node* head = NULL;
    char input[1024];
    int i, j, length = 0;

    printf("Enter a C syntax expression: ");
    fgets(input, 1024, stdin);

    // Calculate the length of the input string
    for (i = 0; input[i] != '\0'; i++)
    {
        length++;
    }

    // Allocate memory for each node
    for (i = 0; i < length; i++)
    {
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->data = input[i];

        if (head == NULL)
        {
            printf("Error allocating memory.");
            exit(1);
        }

        if (head != NULL)
        {
            head = head->next;
        }
    }

    // Traverse the linked list
    for (j = 0; head; j++)
    {
        printf("%c ", head->data);
        head = head->next;
    }

    printf("\n");

    return 0;
}