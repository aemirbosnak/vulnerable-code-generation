//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file
typedef struct {
    char* name;
    char* content;
    int size;
} File;

// Function to create a new file
File* createFile(char* name, char* content) {
    File* newFile = (File*)malloc(sizeof(File));
    if (newFile == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    newFile->name = strdup(name);
    newFile->content = strdup(content);
    newFile->size = strlen(newFile->content);
    return newFile;
}

// Function to read a file
char* readFile(File* file) {
    if (file == NULL) {
        perror("File is NULL");
        exit(1);
    }
    return file->content;
}

// Function to write to a file
void writeFile(File* file, char* content) {
    if (file == NULL) {
        perror("File is NULL");
        exit(1);
    }
    file->content = strdup(content);
    file->size = strlen(file->content);
}

// Function to delete a file
void deleteFile(File* file) {
    if (file == NULL) {
        perror("File is NULL");
        exit(1);
    }
    free(file->name);
    free(file->content);
    free(file);
}

int main() {
    File* file = createFile("test.txt", "Hello, world!");
    printf("File name: %s\n", file->name);
    printf("File content: %s\n", readFile(file));
    writeFile(file, "This is a new line.");
    printf("File content after writing: %s\n", readFile(file));
    deleteFile(file);
    return 0;
}