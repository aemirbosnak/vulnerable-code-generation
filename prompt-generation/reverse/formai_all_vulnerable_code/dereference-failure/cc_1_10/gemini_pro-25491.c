//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a file name
#define MAX_FILE_NAME 256

// Define the maximum number of files in the file system
#define MAX_FILES 100

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the file system struct
typedef struct file_system {
    char *files[MAX_FILES];
    int file_sizes[MAX_FILES];
} file_system;

// Create a new file system
file_system *create_file_system() {
    file_system *fs = malloc(sizeof(file_system));
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i] = NULL;
        fs->file_sizes[i] = 0;
    }
    return fs;
}

// Destroy a file system
void destroy_file_system(file_system *fs) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL) {
            free(fs->files[i]);
        }
    }
    free(fs);
}

// Create a new file in the file system
int create_file(file_system *fs, char *file_name, int file_size) {
    if (file_size > MAX_FILE_SIZE) {
        return -1;
    }

    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] == NULL) {
            fs->files[i] = malloc(file_size);
            fs->file_sizes[i] = file_size;
            strcpy(fs->files[i], file_name);
            return 0;
        }
    }

    return -1;
}

// Delete a file from the file system
int delete_file(file_system *fs, char *file_name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i], file_name) == 0) {
            free(fs->files[i]);
            fs->files[i] = NULL;
            fs->file_sizes[i] = 0;
            return 0;
        }
    }

    return -1;
}

// Read data from a file in the file system
int read_file(file_system *fs, char *file_name, void *buffer, int buffer_size) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i], file_name) == 0) {
            if (buffer_size > fs->file_sizes[i]) {
                return -1;
            }

            memcpy(buffer, fs->files[i], buffer_size);
            return 0;
        }
    }

    return -1;
}

// Write data to a file in the file system
int write_file(file_system *fs, char *file_name, void *buffer, int buffer_size) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i], file_name) == 0) {
            if (buffer_size > fs->file_sizes[i]) {
                return -1;
            }

            memcpy(fs->files[i], buffer, buffer_size);
            return 0;
        }
    }

    return -1;
}

// List the files in the file system
void list_files(file_system *fs) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL) {
            printf("%s (%d bytes)\n", fs->files[i], fs->file_sizes[i]);
        }
    }
}

// Test the file system
int main() {
    // Create a new file system
    file_system *fs = create_file_system();

    // Create a new file
    int result = create_file(fs, "file1.txt", 100);
    if (result != 0) {
        printf("Error creating file: %d\n", result);
        return 1;
    }

    // Write data to the file
    result = write_file(fs, "file1.txt", "Hello, world!", 12);
    if (result != 0) {
        printf("Error writing file: %d\n", result);
        return 1;
    }

    // Read data from the file
    char buffer[12];
    result = read_file(fs, "file1.txt", buffer, 12);
    if (result != 0) {
        printf("Error reading file: %d\n", result);
        return 1;
    }

    // List the files in the file system
    list_files(fs);

    // Delete the file
    result = delete_file(fs, "file1.txt");
    if (result != 0) {
        printf("Error deleting file: %d\n", result);
        return 1;
    }

    // Destroy the file system
    destroy_file_system(fs);

    return 0;
}