//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

// Define the structure of the file system
typedef struct {
    char name[20];
    char content[100];
} File;

// Define the structure of the directory
typedef struct {
    char name[20];
    int num_files;
    File files[MAX_FILES];
} Directory;

// Function to create a new directory
Directory* createDir(char* name) {
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    strcpy(dir->name, name);
    dir->num_files = 0;
    return dir;
}

// Function to create a new file
File* createFile(char* name, char* content) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    strcpy(file->content, content);
    return file;
}

// Function to add a file to a directory
void addFile(Directory* dir, File* file) {
    dir->files[dir->num_files++] = *file;
}

// Function to remove a file from a directory
void removeFile(Directory* dir, char* name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            dir->num_files--;
            memmove(&dir->files[i], &dir->files[i+1], (dir->num_files - i) * sizeof(File));
            break;
        }
    }
}

// Function to print the contents of a directory
void printDir(Directory* dir) {
    printf("Directory: %s\n", dir->name);
    printf("Number of files: %d\n", dir->num_files);
    printf("Files:\n");
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("%s\n", dir->files[i].name);
        printf("%s\n", dir->files[i].content);
    }
}

// Function to print the contents of a file
void printFile(File* file) {
    printf("File name: %s\n", file->name);
    printf("File content:\n%s\n", file->content);
}

int main() {
    Directory* root = createDir("root");
    File* file1 = createFile("file1.txt", "Hello, world!");
    File* file2 = createFile("file2.txt", "This is a test.");
    addFile(root, file1);
    addFile(root, file2);
    printDir(root);
    removeFile(root, "file1.txt");
    printDir(root);
    return 0;
}