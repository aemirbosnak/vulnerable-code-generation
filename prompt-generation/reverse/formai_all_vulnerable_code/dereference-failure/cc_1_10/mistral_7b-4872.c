//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 10
#define MAX_CHARS 50

typedef struct File {
    char name[MAX_CHARS];
    char content[MAX_CHARS];
    struct File *next;
} File;

File *files = NULL;
File *current = NULL;

void createFile(char *name) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    if (files == NULL) {
        files = newFile;
        current = newFile;
    } else {
        current->next = newFile;
        current = newFile;
    }
}

void openFile(char *name) {
    File *temp = files;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            current = temp;
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("File not found.\n");
        return;
    }
    printf("File %s opened.\n", name);
}

void writeFile(char *content, int length) {
    if (current == NULL) {
        printf("No file is currently open.\n");
        return;
    }
    strncat(current->content, content, length);
    printf("Content written to file %s.\n", current->name);
}

void closeFile() {
    if (current == NULL) {
        printf("No file is currently open.\n");
        return;
    }
    if (files == current) {
        files = files->next;
    } else {
        File *temp = files;
        while (temp->next != current) {
            temp = temp->next;
        }
        temp->next = current->next;
    }
    free(current);
    current = NULL;
    printf("File %s closed.\n", current->name);
}

int main() {
    createFile("file1.txt");
    createFile("file2.txt");

    openFile("file1.txt");
    writeFile("Hello World!", 13);
    closeFile();

    openFile("file1.txt");
    printf("%s\n", current->content);
    closeFile();

    openFile("file2.txt");
    writeFile("This is a test.", 15);
    closeFile();

    openFile("file1.txt");
    printf("%s\n", current->content);

    return 0;
}