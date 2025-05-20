//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50
#define MAX_CONTENT 1024

typedef struct {
    char name[MAX_FILENAME];
    char content[MAX_CONTENT];
} File;

typedef struct {
    File* files[MAX_FILES];
    int fileCount;
} FileSystem;

FileSystem* createFileSystem() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->fileCount = 0;
    return fs;
}

void deleteFileSystem(FileSystem* fs) {
    for (int i = 0; i < fs->fileCount; i++) {
        free(fs->files[i]);
    }
    free(fs);
}

File* createFile(const char* name, const char* content) {
    File* file = (File*)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME);
    strncpy(file->content, content, MAX_CONTENT);
    return file;
}

void addFile(FileSystem* fs, const char* name, const char* content) {
    if (fs->fileCount < MAX_FILES) {
        fs->files[fs->fileCount++] = createFile(name, content);
        printf("File '%s' added successfully!\n", name);
    } else {
        printf("File system is full! Cannot add more files.\n");
    }
}

void removeFile(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            fs->files[i] = fs->files[fs->fileCount - 1]; // Move last file here
            fs->fileCount--;
            printf("File '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

void displayFiles(FileSystem* fs) {
    printf("Current Files in the File System:\n");
    if (fs->fileCount == 0) {
        printf("No files available.\n");
    } else {
        for (int i = 0; i < fs->fileCount; i++) {
            printf(" - %s\n", fs->files[i]->name);
        }
    }
}

void modifyFileContent(FileSystem* fs, const char* name, const char* newContent) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            strncpy(fs->files[i]->content, newContent, MAX_CONTENT);
            printf("File '%s' content updated successfully!\n", name);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

void readFileContent(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            printf("Content of '%s':\n%s\n", name, fs->files[i]->content);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

int main() {
    FileSystem* fs = createFileSystem();
    addFile(fs, "example.txt", "Hello, this is an example file.");
    addFile(fs, "test.txt", "This is a test file content.");
    
    displayFiles(fs);
    
    readFileContent(fs, "example.txt");

    modifyFileContent(fs, "example.txt", "Updated content of example file.");
    readFileContent(fs, "example.txt");

    removeFile(fs, "example.txt");
    displayFiles(fs);

    deleteFileSystem(fs);
    return 0;
}