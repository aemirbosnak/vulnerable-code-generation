//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

struct FileBackup {
    char *filename;
    int size;
    struct FileBackup *next;
};

void insertFile(struct FileBackup **head, char *filename, int size) {
    struct FileBackup *new_file = malloc(sizeof(struct FileBackup));
    new_file->filename = strdup(filename);
    new_file->size = size;
    new_file->next = NULL;

    if (*head == NULL) {
        *head = new_file;
    } else {
        (*head)->next = new_file;
    }
}

void backupFiles() {
    struct FileBackup *head = NULL;
    char filename[MAX_FILE_SIZE];
    int size;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter file size: ");
    scanf("%d", &size);

    insertFile(&head, filename, size);

    printf("File added to backup.\n");

    while (1) {
        printf("Enter 'q' to quit or 'a' to add another file: ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 'a') {
            printf("Enter file name: ");
            scanf("%s", filename);

            printf("Enter file size: ");
            scanf("%d", &size);

            insertFile(&head, filename, size);

            printf("File added to backup.\n");
        } else {
            printf("Invalid input.\n");
        }
    }

    printf("Backup complete.\n");
}

int main() {
    backupFiles();
    return 0;
}