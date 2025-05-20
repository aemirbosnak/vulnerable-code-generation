//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct {
    char filename[50];
    char content[500];
    int fileSize;
} File;

// Function to create a new file
void createFile(File *file, const char *filename) {
    strcpy(file->filename, filename);
    file->fileSize = 0;
    file->content[0] = '\0';
}

// Function to write content to a file
void writeFile(File *file, const char *content) {
    if (file->fileSize + strlen(content) > 500) {
        printf("File size exceeded.\n");
        return;
    }
    strcpy(file->content + file->fileSize, content);
    file->fileSize += strlen(content);
}

// Function to read content from a file
char *readFile(File *file) {
    if (file->fileSize == 0) {
        printf("File is empty.\n");
        return NULL;
    }
    return file->content;
}

// Function to delete a file
void deleteFile(File *file) {
    free(file->content);
    file->content[0] = '\0';
    file->fileSize = 0;
}

int main() {
    File file;
    createFile(&file, "myfile.txt");
    writeFile(&file, "Hello, World!");
    printf("File content: %s\n", readFile(&file));
    deleteFile(&file);
    return 0;
}