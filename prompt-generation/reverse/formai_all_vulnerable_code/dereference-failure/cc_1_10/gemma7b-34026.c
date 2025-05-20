//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[255];
    struct FileEntry* next;
} FileEntry;

int main() {
    FileEntry* head = NULL;
    char filename[255];
    int i = 0;

    // Allocate memory for the first file entry
    head = malloc(sizeof(FileEntry));
    head->next = NULL;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Copy the filename into the file entry
    strcpy(head->filename, filename);

    // Add the file entry to the head of the list
    head = head->next = head;

    // Loop to add more file entries if desired
    while (i++ < MAX_FILES - 1) {
        // Get the filename from the user
        printf("Enter the filename: ");
        scanf("%s", filename);

        // Allocate memory for a new file entry
        FileEntry* newEntry = malloc(sizeof(FileEntry));
        newEntry->next = NULL;

        // Copy the filename into the file entry
        strcpy(newEntry->filename, filename);

        // Add the new file entry to the end of the list
        head->next = newEntry;
        head = newEntry;
    }

    // Print the file entries
    printf("Here is a list of file entries:\n");
    for (FileEntry* current = head; current; current = current->next) {
        printf("%s\n", current->filename);
    }

    return 0;
}