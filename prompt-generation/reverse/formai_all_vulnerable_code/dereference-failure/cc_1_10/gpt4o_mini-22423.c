//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 30

typedef struct {
    char name[FILENAME_LENGTH];
    int size; // in bytes
    char *content; // the actual content of the file
} File;

typedef struct {
    File *files[MAX_FILES];
    int fileCount;
} FileSystem;

// Function declarations
FileSystem *createFileSystem();
File *createFile(const char *name, const char *content);
void addFile(FileSystem *fs, File *file);
void listFiles(const FileSystem *fs);
void accessFile(const FileSystem *fs, const char *name);
void freeFileSystem(FileSystem *fs);

int main() {
    FileSystem *myFileSystem = createFileSystem();
    char command[50];

    printf("Welcome to the Surprising File System Simulator!\n");

    while(1) {
        printf("\nEnter a command (add, list, access, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "add") == 0) {
            char fileName[FILENAME_LENGTH];
            char fileContent[256];

            printf("Enter file name: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = 0;

            printf("Enter content for file '%s': ", fileName);
            fgets(fileContent, sizeof(fileContent), stdin);
            fileContent[strcspn(fileContent, "\n")] = 0;

            File *newFile = createFile(fileName, fileContent);
            addFile(myFileSystem, newFile);

            printf("Surprising! File '%s' added to the system.\n", newFile->name);
        } 
        else if (strcmp(command, "list") == 0) {
            printf("Listing all files:\n");
            listFiles(myFileSystem);
        } 
        else if (strcmp(command, "access") == 0) {
            char fileName[FILENAME_LENGTH];
            printf("Enter the file name to access: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = 0;

            accessFile(myFileSystem, fileName);
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Surprising File System Simulator. Bye!\n");
            break;
        } 
        else {
            printf("Oops! Unrecognized command. Please try again.\n");
        }
    }

    freeFileSystem(myFileSystem);
    return 0;
}

FileSystem *createFileSystem() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->fileCount = 0;
    return fs;
}

File *createFile(const char *name, const char *content) {
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, FILENAME_LENGTH);
    file->size = strlen(content);
    file->content = (char *)malloc(file->size + 1);
    strcpy(file->content, content);
    return file;
}

void addFile(FileSystem *fs, File *file) {
    if (fs->fileCount < MAX_FILES) {
        fs->files[fs->fileCount++] = file;
    } else {
        printf("Surprise! File system is full. Cannot add more files.\n");
    }
}

void listFiles(const FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("Surprise! No files in the file system yet!\n");
    } else {
        for (int i = 0; i < fs->fileCount; i++) {
            printf("File %d: %s (Size: %d bytes)\n", i + 1, fs->files[i]->name, fs->files[i]->size);
        }
    }
}

void accessFile(const FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            printf("Accessing file '%s':\nContent: %s\n", name, fs->files[i]->content);
            return;
        }
    }
    printf("Surprising! File '%s' not found!\n", name);
}

void freeFileSystem(FileSystem *fs) {
    for (int i = 0; i < fs->fileCount; i++) {
        free(fs->files[i]->content);
        free(fs->files[i]);
    }
    free(fs);
}