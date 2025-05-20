//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char* key;
    char* value;
    struct node* next;
} Node;

Node* head;

void createIndex(char* key, char* value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;
        while (current->next!= NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printIndex()
{
    Node* current = head;
    while (current!= NULL)
    {
        printf("%s -> %s\n", current->key, current->value);
        current = current->next;
    }
}

int main()
{
    createIndex("apple", "red");
    createIndex("banana", "yellow");
    createIndex("grapes", "purple");
    printIndex();

    return 0;
}