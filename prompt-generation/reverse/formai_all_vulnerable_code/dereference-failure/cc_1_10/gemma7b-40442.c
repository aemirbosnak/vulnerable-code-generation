//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct FileHeader {
    char filename[256];
    int fileSize;
    struct FileHeader* next;
} FileHeader;

void recoverData(FILE* file, FileHeader** head) {
    FileHeader* newHeader = malloc(sizeof(FileHeader));
    newHeader->next = NULL;

    fscanf(file, "%s", newHeader->filename);
    fscanf(file, "%d", &newHeader->fileSize);

    *head = newHeader;

    while (!feof(file)) {
        newHeader = malloc(sizeof(FileHeader));
        newHeader->next = *head;

        fscanf(file, "%s", newHeader->filename);
        fscanf(file, "%d", &newHeader->fileSize);

        *head = newHeader;
    }
}

int main() {
    FileHeader* head = NULL;
    FILE* file = fopen("data.txt", "r");

    recoverData(file, &head);

    FileHeader* current = head;
    while (current) {
        printf("Filename: %s\n", current->filename);
        printf("File size: %d\n", current->fileSize);
        printf("\n");

        current = current->next;
    }

    fclose(file);

    return 0;
}