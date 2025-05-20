//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256

typedef struct Node
{
    char key[MAX_KEY_LENGTH];
    struct Node* next;
} Node;

Node* insertNode(Node* head, char* key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;
        Node* previous = NULL;

        while (current)
        {
            if (strcmp(key, current->key) == 0)
            {
                return NULL;
            }

            previous = current;
            current = current->next;
        }

        previous->next = newNode;
    }

    return head;
}

int main()
{
    Node* head = NULL;

    insertNode(head, "Secret message");
    insertNode(head, "This is a secret key");
    insertNode(head, "Top secret");

    char* message = "Hello, world!";

    for (Node* current = head; current; current = current->next)
    {
        if (strcmp(message, current->key) == 0)
        {
            printf("The message is: %s", current->key);
        }
    }

    return 0;
}