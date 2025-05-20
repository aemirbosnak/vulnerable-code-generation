//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct FileData
{
    char filename[256];
    FILE *file;
    int size;
    struct FileData *next;
} FileData;

void insertFile(FileData **head, char *filename, int size)
{
    FileData *new_node = malloc(sizeof(FileData));
    strcpy(new_node->filename, filename);
    new_node->file = fopen(filename, "r");
    new_node->size = size;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
}

void recoverData(FileData **head)
{
    FILE *file;
    int size, i;
    char buffer[MAX_BUFFER_SIZE];

    for (FileData *current = *head; current; current = current->next)
    {
        file = current->file;
        size = current->size;

        printf("File: %s, Size: %d\n", current->filename, size);

        for (i = 0; i < size; i++)
        {
            fread(buffer, 1, MAX_BUFFER_SIZE, file);
            printf("%s", buffer);
        }

        fclose(file);
    }
}

int main()
{
    FileData *head = NULL;

    insertFile(&head, "test.txt", 10);
    insertFile(&head, "another.txt", 20);

    recoverData(&head);

    return 0;
}