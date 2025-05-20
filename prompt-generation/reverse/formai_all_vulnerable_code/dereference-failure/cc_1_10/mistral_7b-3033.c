//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTENT_LENGTH 100

typedef struct File {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct File *next;
} File;

File *fileSystem = NULL;

void createFile(char *name) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = fileSystem;
    fileSystem = newFile;
}

void deleteFile(char *name) {
    File *current = fileSystem;
    File *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                fileSystem = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void saveContentToFile(char *name, char *content) {
    File *current = fileSystem;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->content, content);
            break;
        }
        current = current->next;
    }
}

void printFileSystem() {
    File *current = fileSystem;

    printf("Funny File System:\n");
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->content);
        current = current->next;
    }
}

int main() {
    createFile("myFunnyFile.txt");
    createFile("I_Am_Not_Sorry.txt");
    createFile("funninessLevel:10.txt");

    saveContentToFile("myFunnyFile.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    saveContentToFile("I_Am_Not_Sorry.txt", "Potato, tomato, pasta, pizza!");
    saveContentToFile("funninessLevel:10.txt", "11/10 would laugh again.");

    printFileSystem();

    deleteFile("I_Am_Not_Sorry.txt");

    printFileSystem();

    return 0;
}