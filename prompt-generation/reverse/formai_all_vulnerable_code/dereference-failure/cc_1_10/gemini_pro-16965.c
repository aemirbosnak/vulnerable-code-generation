//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A cheerful File System Simulation!

// A directory entry
typedef struct {
    char name[32];  // File name
    int size;       // File size
} DirectoryEntry;

// The file system
typedef struct {
    DirectoryEntry entries[16];  // Directory entries
    int num_entries;             // Number of entries
} FileSystem;

// Create a new file system
FileSystem* create_filesystem() {
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->num_entries = 0;
    return fs;
}

// Add a file to the file system
void add_file(FileSystem* fs, char* name, int size) {
    // Check if the directory is full
    if (fs->num_entries == 16) {
        printf("Error: Directory is full\n");
        return;
    }

    // Add the file to the directory
    strcpy(fs->entries[fs->num_entries].name, name);
    fs->entries[fs->num_entries].size = size;
    fs->num_entries++;
}

// Print the file system
void print_filesystem(FileSystem* fs) {
    printf("File System:\n");
    for (int i = 0; i < fs->num_entries; i++) {
        printf("  %s (%d bytes)\n", fs->entries[i].name, fs->entries[i].size);
    }
}

// Main function
int main() {
    // Create a new file system
    FileSystem* fs = create_filesystem();

    // Add some files to the file system
    add_file(fs, "hello.txt", 1024);
    add_file(fs, "world.txt", 2048);
    add_file(fs, "fun.txt", 4096);

    // Print the file system
    print_filesystem(fs);

    // Clean up
    free(fs);

    return 0;
}