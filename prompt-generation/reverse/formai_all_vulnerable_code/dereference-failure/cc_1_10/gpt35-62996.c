//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20
#define MAX_FILE_SIZE 512

typedef struct {
    char name[MAX_FILENAME_LEN];
    int size;
    char* data;
} File;

File* createFile(char* name, int size) {
    File* file = (File*) malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME_LEN);
    file->size = size;
    file->data = (char*) malloc(sizeof(char) * size);
    return file;
}

void deleteFile(File* file) {
    free(file->data);
    free(file);
}

typedef struct {
    File** files;
    int num_files;
    int max_files;
} FileSystem;

FileSystem* createFileSystem(int num_files) {
    FileSystem* fs = (FileSystem*) malloc(sizeof(FileSystem));
    fs->num_files = 0;
    fs->max_files = num_files;
    fs->files = (File**) malloc(sizeof(File*) * num_files);
    return fs;
}

void deleteFileSystem(FileSystem* fs) {
    for (int i = 0; i < fs->num_files; i++) {
        deleteFile(fs->files[i]);
    }
    free(fs->files);
    free(fs);
}

File* getFile(FileSystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            return fs->files[i];
        }
    }
    return NULL;
}

int addFile(FileSystem* fs, char* name, int size) {
    if (fs->num_files == fs->max_files) {
        return -1; // FileSystem full
    }
    if (getFile(fs, name) != NULL) {
        return -2; // File already exists
    }
    File* file = createFile(name, size);
    fs->files[fs->num_files] = file;
    fs->num_files++;
    return 0; // Success
}

int deleteFileByName(FileSystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            deleteFile(fs->files[i]);
            fs->num_files--;
            for (int j = i; j < fs->num_files; j++) {
                fs->files[j] = fs->files[j+1];
            }
            return 0; // Success
        }
    }
    return -1; // File not found
}

int main() {
    FileSystem* fs = createFileSystem(10);
    addFile(fs, "file1", 100);
    addFile(fs, "file2", 200);
    addFile(fs, "file3", 50);
    addFile(fs, "file4", 300);
    File* file = getFile(fs, "file2");
    printf("File size: %d\n", file->size);
    deleteFileByName(fs, "file3");
    deleteFileSystem(fs);
    return 0;
}