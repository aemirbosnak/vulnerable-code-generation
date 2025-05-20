//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LEN 20
#define MAX_CONTENT_LEN 100

typedef struct File {
    char name[MAX_NAME_LEN];
    char content[MAX_CONTENT_LEN];
    struct File *next;
} File;

File *files[MAX_FILES] = {0};

void createFile(const char *name) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = 0;

    for (int i = 0; i < MAX_FILES; i++) {
        if (!files[i]) {
            files[i] = newFile;
            break;
        }
    }
}

void writeFile(const char *name, const char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!strcmp(files[i]->name, name)) {
            strcpy(files[i]->content, content);
            break;
        }
    }
}

void readFile(const char *name, char *buffer, int *length) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!strcmp(files[i]->name, name)) {
            strcpy(buffer, files[i]->content);
            *length = strlen(files[i]->content);
            break;
        }
    }
}

void deleteFile(const char *name) {
    File *prev = 0;
    File *current = files[0];

    while (current && strcmp(current->name, name)) {
        prev = current;
        current = current->next;
    }

    if (!current) return;

    if (prev) prev->next = current->next;
    else files[0] = current->next;

    free(current);
}

int main() {
    createFile("file1.txt");
    createFile("file2.txt");

    writeFile("file1.txt", "Hello World!");
    writeFile("file2.txt", "Knuth style!");

    char buffer[MAX_CONTENT_LEN];
    int length;

    readFile("file1.txt", buffer, &length);
    printf("%s (length: %d)\n", buffer, length);

    readFile("file2.txt", buffer, &length);
    printf("%s (length: %d)\n", buffer, length);

    deleteFile("file1.txt");

    readFile("file2.txt", buffer, &length);
    printf("%s (length: %d)\n", buffer, length);

    return 0;
}