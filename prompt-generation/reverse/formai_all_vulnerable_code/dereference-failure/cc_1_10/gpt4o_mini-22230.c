//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define BUFFER_SIZE 256

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char *data;
} File;

typedef struct {
    File *files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem* create_file_system() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->file_count = 0;
    return fs;
}

File* create_file(const char *name, const char *data) {
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME_LENGTH);
    file->size = strlen(data);
    file->data = (char *)malloc(file->size + 1);
    strcpy(file->data, data);
    return file;
}

int add_file(FileSystem *fs, File *file) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: File system is full.\n");
        return -1;
    }
    fs->files[fs->file_count++] = file;
    return 0;
}

void display_files(FileSystem *fs) {
    printf("=== File System ===\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("File %d: %s (Size: %d bytes)\n", i + 1, fs->files[i]->name, fs->files[i]->size);
    }
    printf("===================\n");
}

File* find_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            return fs->files[i];
        }
    }
    return NULL;
}

void delete_file(FileSystem *fs, const char *name) {
    int idx = -1;
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("Error: File not found.\n");
        return;
    }
    free(fs->files[idx]->data);
    free(fs->files[idx]);
    for (int i = idx; i < fs->file_count - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->file_count--;
    printf("File '%s' deleted successfully.\n", name);
}

void cleanup(FileSystem *fs) {
    for (int i = 0; i < fs->file_count; i++) {
        free(fs->files[i]->data);
        free(fs->files[i]);
    }
    free(fs);
}

int main() {
    FileSystem *fs = create_file_system();
    
    add_file(fs, create_file("file1.txt", "This is the content of file 1."));
    add_file(fs, create_file("file2.txt", "This is the content of file 2."));
    add_file(fs, create_file("file3.txt", "This is the content of file 3."));
    
    display_files(fs);
    
    File *search = find_file(fs, "file2.txt");
    if (search) {
        printf("Found: %s (Size: %d bytes)\n", search->name, search->size);
    } else {
        printf("File not found!\n");
    }

    delete_file(fs, "file1.txt");
    display_files(fs);
    
    delete_file(fs, "file3.txt");
    display_files(fs);
    
    cleanup(fs);
    return 0;
}