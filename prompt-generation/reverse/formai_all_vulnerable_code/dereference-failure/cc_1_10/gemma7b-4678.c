//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* child;
} Node;

void createFile(Node** head, char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->child = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void listFiles(Node* head)
{
    while (head)
    {
        printf("%s ", head->name);
        listFiles(head->child);
    }
}

int main()
{
    Node* head = NULL;

    // Create some files
    createFile(&head, "a.txt");
    createFile(&head, "b.txt");
    createFile(&head, "c.txt");
    createFile(&head, "dir1");

    // List all files
    listFiles(head);

    return 0;
}