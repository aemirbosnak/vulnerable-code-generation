//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Node
{
    char data[BUFFER_SIZE];
    struct Node* next;
} Node;

Node* head = NULL;

void insert(char* data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void backup(char* filename)
{
    FILE* file = fopen(filename, "w");
    Node* temp = head;

    fprintf(file, "backup data:\n");
    while (temp)
    {
        fprintf(file, "%s\n", temp->data);
        temp = temp->next;
    }

    fclose(file);
}

int main()
{
    insert("a.txt");
    insert("b.txt");
    insert("c.txt");

    backup("backup.txt");

    return 0;
}