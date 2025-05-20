//FormAI DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20
#define MAX_FILE_SIZE 1024
#define MAX_FILES 10

// Define file metadata struct
typedef struct file_meta {
    char filename[MAX_FILENAME_LEN];
    unsigned int size;
    char* data;
} file_meta;

// Define file system struct
typedef struct file_system {
    file_meta files[MAX_FILES];
    unsigned int num_files;
    unsigned int total_size;
} file_system;

// Function to initialize file system
void init_file_system(file_system* fs) {
    fs->num_files = 0;
    fs->total_size = 0;
}

// Function to create new file
int create_file(file_system* fs, char* filename, char* data, unsigned int size) {
    // Check if file with same name already exists
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            printf("Error: File with name '%s' already exists.\n", filename);
            return -1;
        }
    }
    
    // Check if file system has enough space to store file
    if (fs->total_size + size > MAX_FILES * MAX_FILE_SIZE) {
        printf("Error: File system does not have enough space to store file '%s'.\n", filename);
        return -1;
    }
    
    // Create new file
    file_meta new_file;
    strcpy(new_file.filename, filename);
    new_file.size = size;
    new_file.data = (char*)malloc(size * sizeof(char));
    memcpy(new_file.data, data, size);
    
    // Add new file to file system
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->total_size += size;
    
    return 0;
}

// Function to delete file
int delete_file(file_system* fs, char* filename) {
    int deleted = 0;
    
    // Find file with matching name and remove it from file system
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            free(fs->files[i].data);
            fs->total_size -= fs->files[i].size;
            fs->num_files--;
            deleted = 1;
        } else if (deleted) {
            // If file was removed, shift remaining files back one slot in array
            fs->files[i-1] = fs->files[i];
        }
    }
    
    if (deleted) {
        printf("File '%s' deleted.\n", filename);
        return 0;
    } else {
        printf("Error: Could not find file with name '%s'.\n", filename);
        return -1;
    }
}

// Function to list all files in file system
void list_files(file_system* fs) {
    printf("Files in file system:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf(" '%s' (%d bytes)\n", fs->files[i].filename, fs->files[i].size);
    }
}

int main() {
    file_system fs;
    init_file_system(&fs);
    
    // Create some test files
    create_file(&fs, "file1.txt", "This is the contents of file 1.\n", 30);
    create_file(&fs, "file2.txt", "This is the contents of file 2.\n", 30);
    create_file(&fs, "file3.txt", "This is the contents of file 3.\n", 30);
    
    // List all files in file system
    list_files(&fs);
    
    // Delete file2.txt
    delete_file(&fs, "file2.txt");
    
    // List all files in file system again
    list_files(&fs);
    
    return 0;
}