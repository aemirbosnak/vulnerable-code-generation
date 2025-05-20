//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char character;
    int frequency;
    struct Node* next;
} Node;

void insert(Node** head, char character, int frequency)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void huffman_encode(Node* head)
{
    char* code = malloc(1024);
    int i = 0;

    while (head)
    {
        char prefix = '0' + i;
        int frequency = head->frequency;
        insert(&code, prefix, frequency);
        head = head->next;
        i++;
    }

    printf("Encoded code:\n");
    for (i = 0; code[i] != '\0'; i++)
    {
        printf("%c ", code[i]);
    }

    free(code);
}

int main()
{
    Node* head = NULL;
    insert(&head, 'a', 5);
    insert(&head, 'b', 3);
    insert(&head, 'c', 2);
    insert(&head, 'd', 4);

    huffman_encode(head);

    return 0;
}