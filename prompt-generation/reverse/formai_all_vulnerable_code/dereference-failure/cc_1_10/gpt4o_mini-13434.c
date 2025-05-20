//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    size_t size;
} File;

typedef struct {
    File* files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem* create_file_system() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->file_count = 0;
    return fs;
}

void delete_file_system(FileSystem* fs) {
    for (int i = 0; i < fs->file_count; i++) {
        free(fs->files[i]);
    }
    free(fs);
}

int create_file(FileSystem* fs, const char* filename) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    
    File* file = (File*)malloc(sizeof(File));
    strncpy(file->name, filename, MAX_FILENAME_LENGTH);
    file->size = 0; // Initially size is zero
    fs->files[fs->file_count++] = file;
    printf("File '%s' created successfully.\n", filename);
    return 0;
}

int write_file(FileSystem* fs, const char* filename, const char* content) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, filename) == 0) {
            size_t content_length = strlen(content);
            if (content_length + fs->files[i]->size > MAX_FILE_SIZE) {
                printf("Error: File size limit exceeded.\n");
                return -1;
            }
            strcat(fs->files[i]->data, content);
            fs->files[i]->size += content_length;
            printf("Data written to file '%s'.\n", filename);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", filename);
    return -1;
}

int read_file(FileSystem* fs, const char* filename) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, filename) == 0) {
            printf("Contents of file '%s':\n%s\n", filename, fs->files[i]->data);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", filename);
    return -1;
}

int delete_file(FileSystem* fs, const char* filename) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, filename) == 0) {
            free(fs->files[i]);
            fs->files[i] = fs->files[fs->file_count - 1]; // Replace with last file
            fs->file_count--;
            printf("File '%s' deleted successfully.\n", filename);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", filename);
    return -1;
}

void display_all_files(FileSystem* fs) {
    if (fs->file_count == 0) {
        printf("No files found in the file system.\n");
        return;
    }
    printf("Currently available files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("- %s (%zu bytes)\n", fs->files[i]->name, fs->files[i]->size);
    }
}

int main() {
    FileSystem* fs = create_file_system();

    create_file(fs, "test1.txt");
    create_file(fs, "test2.txt");
    write_file(fs, "test1.txt", "Hello, World!\n");
    write_file(fs, "test2.txt", "File System Simulation in C.\n");

    read_file(fs, "test1.txt");
    read_file(fs, "test2.txt");

    display_all_files(fs);

    delete_file(fs, "test1.txt");
    display_all_files(fs);

    delete_file_system(fs);
    return 0;
}