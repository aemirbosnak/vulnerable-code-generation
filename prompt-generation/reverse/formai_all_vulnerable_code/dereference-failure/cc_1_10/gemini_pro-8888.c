//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024*1024  // 1MB

// File structure
typedef struct File {
    char name[256];
    char contents[MAX_FILE_SIZE];
    size_t size;
    time_t timestamp;
} File;

// Backup system structure
typedef struct BackupSystem {
    File files[MAX_FILES];
    int num_files;
} BackupSystem;

// Create a new backup system
BackupSystem* create_backup_system() {
    BackupSystem* bs = (BackupSystem*) malloc(sizeof(BackupSystem));
    bs->num_files = 0;
    return bs;
}

// Add a file to the backup system
void add_file(BackupSystem* bs, char* name, char* contents, size_t size) {
    if (bs->num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    File* file = &bs->files[bs->num_files++];
    strcpy(file->name, name);
    memcpy(file->contents, contents, size);
    file->size = size;
    file->timestamp = time(NULL);
}

// Restore a file from the backup system
void restore_file(BackupSystem* bs, char* name) {
    for (int i = 0; i < bs->num_files; i++) {
        File* file = &bs->files[i];
        if (strcmp(file->name, name) == 0) {
            printf("Restoring file: %s\n", file->name);
            fwrite(file->contents, 1, file->size, stdout);
            return;
        }
    }

    printf("Error: File not found.\n");
}

// List all files in the backup system
void list_files(BackupSystem* bs) {
    printf("Files in the backup system:\n");
    for (int i = 0; i < bs->num_files; i++) {
        File* file = &bs->files[i];
        printf("%s (%ld bytes, %s)\n", file->name, file->size, ctime(&file->timestamp));
    }
}

// Main function
int main() {
    // Create a backup system
    BackupSystem* bs = create_backup_system();

    // Add some files to the backup system
    add_file(bs, "file1.txt", "Hello, world!", 13);
    add_file(bs, "file2.txt", "This is a test file.", 20);
    add_file(bs, "file3.txt", "This is another test file.", 25);

    // List the files in the backup system
    list_files(bs);

    // Restore a file from the backup system
    restore_file(bs, "file2.txt");

    // Free the memory used by the backup system
    free(bs);

    return 0;
}