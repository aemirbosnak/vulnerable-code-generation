//Gemma-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileRecord {
    char *filename;
    int size;
    struct FileRecord *next;
} FileRecord;

FileRecord *insertFile(FileRecord *head, char *filename, int size)
{
    FileRecord *newRecord = malloc(sizeof(FileRecord));
    newRecord->filename = strdup(filename);
    newRecord->size = size;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = insertFile(head->next, filename, size);
    }

    return head;
}

void printFiles(FileRecord *head)
{
    FileRecord *current = head;

    while (current) {
        printf("%s (size: %d) ", current->filename, current->size);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    FileRecord *files = NULL;

    files = insertFile(files, "a.txt", 10);
    files = insertFile(files, "b.txt", 20);
    files = insertFile(files, "c.txt", 30);

    printFiles(files);

    return 0;
}