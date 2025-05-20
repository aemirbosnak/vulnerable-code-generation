//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char name[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

int main() {
    FileEntry* head = NULL;
    FILE* file;

    // Create a new file entry
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    newEntry->next = NULL;

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", newEntry->name);

    // Open the file
    file = fopen(newEntry->name, "r");

    // Check if the file is open
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Add the file entry to the head of the list
    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }

    // Close the file
    fclose(file);

    // Print the file list
    FileEntry* currentEntry = head;
    while (currentEntry) {
        printf("%s\n", currentEntry->name);
        currentEntry = currentEntry->next;
    }

    return 0;
}