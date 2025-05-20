//FormAI DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_FILE_NAME_LENGTH 50

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    time_t lastModified;
} File;

typedef struct FileList {
    File data;
    struct FileList* next;
} FileList;

FileList* head = NULL;
FileList* tail = NULL;

void printMenu() {
    printf("Enter one of the following commands:\n");
    printf("1. Add a file\n");
    printf("2. Remove a file\n");
    printf("3. List all files\n");
    printf("4. Quit\n");
}

File createFile(char* name) {
    File file;
    strcpy(file.name, name);
    file.lastModified = time(NULL);
    return file;
}

FileList* createNode(File file) {
    FileList* node = malloc(sizeof(FileList));
    node->data = file;
    node->next = NULL;
    return node;
}

void insertFile(File file) {
    FileList* node = createNode(file);
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void removeFile(char* name) {
    FileList* current = head;
    FileList* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Could not find file: %s\n", name);
}

void printFiles() {
    if (head == NULL) {
        printf("No files have been added.\n");
    } else {
        FileList* current = head;
        printf("Files:\n");
        while (current != NULL) {
            printf("- %s (last modified: %s)", current->data.name, ctime(&current->data.lastModified));
            current = current->next;
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    int keepRunning = 1;
    while (keepRunning) {
        printMenu();
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        switch (command[0]) {
            case '1': {
                char fileName[MAX_FILE_NAME_LENGTH];
                printf("Enter file name: ");
                fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                File file = createFile(fileName);
                insertFile(file);
                printf("File added.\n");
                break;
            }
            case '2': {
                char fileName[MAX_FILE_NAME_LENGTH];
                printf("Enter file name: ");
                fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                removeFile(fileName);
                break;
            }
            case '3': {
                printFiles();
                break;
            }
            case '4': {
                printf("Exiting program.\n");
                keepRunning = 0;
                break;
            }
            default: {
                printf("Invalid command.\n");
                break;
            }
        }
    }
    return 0;
}