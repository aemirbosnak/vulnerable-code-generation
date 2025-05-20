//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

void insert(struct Node** head, char character, int frequency)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* current = *head;
        struct Node* previous = NULL;

        while (current)
        {
            if (newNode->character < current->character)
            {
                previous = current;
                current = current->next;
            }
            else
            {
                break;
            }
        }

        if (previous)
        {
            previous->next = newNode;
        }
        else
        {
            *head = newNode;
        }
    }
}

void huffman(struct Node** head)
{
    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current)
    {
        int total = 0;

        for (struct Node* sibling = current->next; sibling; sibling)
        {
            total += sibling->frequency;
        }

        current->frequency += total;

        previous = current;
        current = current->next;
    }

    *head = previous;
}

int main()
{
    struct Node* head = NULL;

    insert(&head, 'a', 5);
    insert(&head, 'b', 3);
    insert(&head, 'c', 2);
    insert(&head, 'd', 4);
    insert(&head, 'e', 3);

    huffman(&head);

    printf("Huffman Coding:\n");
    for (struct Node* node = head; node; node = node->next)
    {
        printf("%c: %d\n", node->character, node->frequency);
    }

    return 0;
}