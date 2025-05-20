//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: unmistakable
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structures

typedef struct {
    char name[256];
    int size;
    int block_count;
    int *blocks;
} File;

typedef struct {
    int block_size;
    int block_count;
    int *free_blocks;
    int free_block_count;
    File *files;
    int file_count;
} FileSystem;

// Prototypes

FileSystem* create_file_system(int block_size, int block_count);
void destroy_file_system(FileSystem* fs);
File* create_file(FileSystem* fs, char* name, int size);
void destroy_file(FileSystem* fs, File* file);
int allocate_blocks(FileSystem* fs, File* file, int block_count);
void deallocate_blocks(FileSystem* fs, File* file);
void print_file_system(FileSystem* fs);
void print_file(File* file);

// Main

int main() {
    // Create a file system
    FileSystem* fs = create_file_system(512, 1000);

    // Create some files
    File* file1 = create_file(fs, "file1.txt", 1024);
    File* file2 = create_file(fs, "file2.txt", 2048);
    File* file3 = create_file(fs, "file3.txt", 4096);

    // Print the file system
    print_file_system(fs);

    // Destroy the file system
    destroy_file_system(fs);

    return 0;
}

// Functions

FileSystem* create_file_system(int block_size, int block_count) {
    // Allocate memory for the file system
    FileSystem* fs = malloc(sizeof(FileSystem));

    // Initialize the file system
    fs->block_size = block_size;
    fs->block_count = block_count;
    fs->free_blocks = malloc(sizeof(int) * block_count);
    fs->free_block_count = block_count;
    for (int i = 0; i < block_count; i++) {
        fs->free_blocks[i] = i;
    }
    fs->files = NULL;
    fs->file_count = 0;

    // Return the file system
    return fs;
}

void destroy_file_system(FileSystem* fs) {
    // Free the memory allocated for the file system
    free(fs->free_blocks);
    for (int i = 0; i < fs->file_count; i++) {
        destroy_file(fs, &fs->files[i]);
    }
    free(fs->files);
    free(fs);
}

File* create_file(FileSystem* fs, char* name, int size) {
    // Allocate memory for the file
    File* file = malloc(sizeof(File));

    // Initialize the file
    strcpy(file->name, name);
    file->size = size;
    file->block_count = (size + fs->block_size - 1) / fs->block_size;
    file->blocks = malloc(sizeof(int) * file->block_count);

    // Allocate blocks for the file
    if (!allocate_blocks(fs, file, file->block_count)) {
        free(file->blocks);
        free(file);
        return NULL;
    }

    // Add the file to the file system
    fs->files = realloc(fs->files, sizeof(File) * (fs->file_count + 1));
    fs->files[fs->file_count++] = *file;

    // Return the file
    return file;
}

void destroy_file(FileSystem* fs, File* file) {
    // Deallocate the blocks allocated for the file
    deallocate_blocks(fs, file);

    // Remove the file from the file system
    for (int i = 0; i < fs->file_count; i++) {
        if (&fs->files[i] == file) {
            fs->files[i] = fs->files[fs->file_count - 1];
            fs->file_count--;
            break;
        }
    }

    // Free the memory allocated for the file
    free(file->blocks);
    free(file);
}

int allocate_blocks(FileSystem* fs, File* file, int block_count) {
    // Check if there are enough free blocks
    if (block_count > fs->free_block_count) {
        return 0;
    }

    // Allocate the blocks
    for (int i = 0; i < block_count; i++) {
        file->blocks[i] = fs->free_blocks[fs->free_block_count - 1];
        fs->free_blocks[fs->free_block_count - 1] = -1;
        fs->free_block_count--;
    }

    // Return success
    return 1;
}

void deallocate_blocks(FileSystem* fs, File* file) {
    // Deallocate the blocks allocated for the file
    for (int i = 0; i < file->block_count; i++) {
        fs->free_blocks[fs->free_block_count++] = file->blocks[i];
    }
}

void print_file_system(FileSystem* fs) {
    printf("File system:\n");
    printf("  Block size: %d\n", fs->block_size);
    printf("  Block count: %d\n", fs->block_count);
    printf("  Free blocks: %d\n", fs->free_block_count);
    printf("  Files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("    %s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

void print_file(File* file) {
    printf("File: %s\n", file->name);
    printf("  Size: %d bytes\n", file->size);
    printf("  Blocks:\n");
    for (int i = 0; i < file->block_count; i++) {
        printf("    %d\n", file->blocks[i]);
    }
}