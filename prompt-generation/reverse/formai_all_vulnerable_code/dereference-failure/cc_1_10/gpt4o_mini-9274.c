//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File {
    char name[50];
    struct File* next;
} File;

typedef struct Directory {
    char name[50];
    File* files;
    struct Directory* next;
} Directory;

Directory* head = NULL;

void createDirectory(char* name) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->files = NULL;
    newDir->next = head;
    head = newDir;
}

void createFile(char* dirName, char* fileName) {
    Directory* dir = head;
    while (dir != NULL) {
        if (strcmp(dir->name, dirName) == 0) {
            File* newFile = (File*)malloc(sizeof(File));
            strcpy(newFile->name, fileName);
            newFile->next = dir->files;
            dir->files = newFile;
            printf("File '%s' created in directory '%s'.\n", fileName, dirName);
            return;
        }
        dir = dir->next;
    }
    printf("Directory '%s' not found.\n", dirName);
}

void deleteFile(char* dirName, char* fileName) {
    Directory* dir = head;
    while (dir != NULL) {
        if (strcmp(dir->name, dirName) == 0) {
            File* temp = dir->files;
            File* prev = NULL;
            while (temp != NULL) {
                if (strcmp(temp->name, fileName) == 0) {
                    if (prev == NULL) {
                        dir->files = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    free(temp);
                    printf("File '%s' deleted from directory '%s'.\n", fileName, dirName);
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            printf("File '%s' not found in directory '%s'.\n", fileName, dirName);
            return;
        }
        dir = dir->next;
    }
    printf("Directory '%s' not found.\n", dirName);
}

void listFiles(char* dirName) {
    Directory* dir = head;
    while (dir != NULL) {
        if (strcmp(dir->name, dirName) == 0) {
            printf("Files in directory '%s':\n", dirName);
            File* temp = dir->files;
            if (temp == NULL) {
                printf("  (No files)\n");
            }
            while (temp != NULL) {
                printf("  - %s\n", temp->name);
                temp = temp->next;
            }
            return;
        }
        dir = dir->next;
    }
    printf("Directory '%s' not found.\n", dirName);
}

void printDirectories() {
    Directory* dir = head;
    printf("Directories:\n");
    while (dir != NULL) {
        printf("- %s\n", dir->name);
        dir = dir->next;
    }
}

void cleanup() {
    Directory* dir = head;
    while (dir != NULL) {
        File* file = dir->files;
        while (file != NULL) {
            File* temp = file;
            file = file->next;
            free(temp);
        }
        Directory* temp = dir;
        dir = dir->next;
        free(temp);
    }
}

int main() {
    int choice;
    char dirName[50];
    char fileName[50];

    do {
        printf("\nFile System Simulation Menu:\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. List Files\n");
        printf("5. List Directories\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                createDirectory(dirName);
                break;
            case 2:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                printf("Enter file name: ");
                scanf("%s", fileName);
                createFile(dirName, fileName);
                break;
            case 3:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                printf("Enter file name: ");
                scanf("%s", fileName);
                deleteFile(dirName, fileName);
                break;
            case 4:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                listFiles(dirName);
                break;
            case 5:
                printDirectories();
                break;
            case 6:
                cleanup();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}