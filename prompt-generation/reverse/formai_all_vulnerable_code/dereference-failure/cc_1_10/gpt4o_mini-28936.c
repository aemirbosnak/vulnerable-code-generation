//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100

typedef struct File {
    char name[MAX_FILENAME];
    struct File *next;
} File;

typedef struct FileSystem {
    File *head;
} FileSystem;

// Function prototypes
FileSystem *createFileSystem();
void addFile(FileSystem *fs, const char *filename);
void deleteFile(FileSystem *fs, const char *filename);
void listFiles(FileSystem *fs);
void freeFileSystem(FileSystem *fs);

int main() {
    FileSystem *fs = createFileSystem();
    int choice;
    char filename[MAX_FILENAME];

    do {
        printf("\nSimple File System Simulation\n");
        printf("1. Add File\n");
        printf("2. Delete File\n");
        printf("3. List Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to create: ");
                scanf("%s", filename);
                addFile(fs, filename);
                break;
            case 2:
                printf("Enter the filename to delete: ");
                scanf("%s", filename);
                deleteFile(fs, filename);
                break;
            case 3:
                listFiles(fs);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeFileSystem(fs);
    return 0;
}

FileSystem *createFileSystem() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->head = NULL;
    return fs;
}

void addFile(FileSystem *fs, const char *filename) {
    File *newFile = (File *)malloc(sizeof(File));
    if (newFile == NULL) {
        printf("Error allocating memory for new file.\n");
        return;
    }
    strcpy(newFile->name, filename);
    newFile->next = fs->head;
    fs->head = newFile;
    printf("File '%s' created successfully.\n", filename);
}

void deleteFile(FileSystem *fs, const char *filename) {
    File *current = fs->head;
    File *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, filename) == 0) {
            if (previous == NULL) {
                fs->head = current->next; // File is at the head
            } else {
                previous->next = current->next; // Bypass the file to be deleted
            }
            free(current);
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("File '%s' not found.\n", filename);
}

void listFiles(FileSystem *fs) {
    File *current = fs->head;
    if (current == NULL) {
        printf("No files in the system.\n");
        return;
    }
    printf("Files in the system:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

void freeFileSystem(FileSystem *fs) {
    File *current = fs->head;
    while (current != NULL) {
        File *temp = current;
        current = current->next;
        free(temp);
    }
    free(fs);
}