//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 50
#define FILE_SIZE 1024

typedef struct {
    char name[FILE_NAME_LENGTH];
    int size;
    char *content;
} File;

typedef struct {
    File *files[MAX_FILES];
    int fileCount;
} FileSystem;

FileSystem *createFileSystem() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->fileCount = 0;
    return fs;
}

void createFile(FileSystem *fs, const char *name, int size) {
    if (fs->fileCount >= MAX_FILES) {
        printf("File system full, cannot add more files.\n");
        return;
    }
    File *newFile = (File *)malloc(sizeof(File));
    strncpy(newFile->name, name, FILE_NAME_LENGTH);
    newFile->size = size;
    newFile->content = (char *)malloc(size * sizeof(char));
    memset(newFile->content, 0, size);
    fs->files[fs->fileCount++] = newFile;
    printf("File '%s' created with size %d bytes.\n", name, size);
}

File *findFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            return fs->files[i];
        }
    }
    return NULL;
}

void readFile(File *file) {
    if (file != NULL) {
        printf("Reading file '%s':\n", file->name);
        printf("%s\n", file->content);
    } else {
        printf("File not found.\n");
    }
}

void writeFile(File *file, const char *content) {
    if (file != NULL) {
        snprintf(file->content, file->size, "%s", content);
        printf("Written to file '%s': %s\n", file->name, content);
    } else {
        printf("File not found for writing.\n");
    }
}

void deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]->content);
            free(fs->files[i]);
            fs->files[i] = fs->files[--fs->fileCount];  // Replace with last file
            printf("File '%s' deleted.\n", name);
            return;
        }
    }
    printf("File '%s' not found for deletion.\n", name);
}

void listFiles(FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("No files in the system.\n");
        return;
    }
    printf("Listing files in the system:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("File: '%s' Size: %d bytes\n", fs->files[i]->name, fs->files[i]->size);
    }
}

void freeFileSystem(FileSystem *fs) {
    for (int i = 0; i < fs->fileCount; i++) {
        free(fs->files[i]->content);
        free(fs->files[i]);
    }
    free(fs);
}

int main() {
    FileSystem *myFileSystem = createFileSystem();

    createFile(myFileSystem, "watson.txt", FILE_SIZE);
    createFile(myFileSystem, "sherlock.txt", FILE_SIZE);
    
    writeFile(findFile(myFileSystem, "watson.txt"), "A case of mistaken identity.");
    writeFile(findFile(myFileSystem, "sherlock.txt"), "Elementary, my dear Watson.");

    listFiles(myFileSystem);

    readFile(findFile(myFileSystem, "watson.txt"));
    readFile(findFile(myFileSystem, "sherlock.txt"));

    deleteFile(myFileSystem, "watson.txt");
    listFiles(myFileSystem);

    freeFileSystem(myFileSystem);
    
    return 0;
}