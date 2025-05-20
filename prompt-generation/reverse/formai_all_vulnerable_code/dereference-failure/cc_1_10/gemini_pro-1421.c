//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Ephemeral file backup system

// Structure to hold file metadata
typedef struct {
    char* name;
    time_t last_modified;
    size_t size;
} FileMetadata;

// Array to hold file metadata
FileMetadata* files;

// Number of files
int num_files;

// Initialize the file backup system
void init_backup_system() {
    // Allocate memory for the file metadata array
    files = malloc(sizeof(FileMetadata) * 100);

    // Initialize the number of files to 0
    num_files = 0;
}

// Add a file to the backup system
void add_file(char* name, time_t last_modified, size_t size) {
    // Check if the file already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // File already exists, update the metadata
            files[i].last_modified = last_modified;
            files[i].size = size;
            return;
        }
    }

    // File does not exist, add it to the array
    files[num_files].name = strdup(name);
    files[num_files].last_modified = last_modified;
    files[num_files].size = size;
    num_files++;
}

// Remove a file from the backup system
void remove_file(char* name) {
    // Find the index of the file in the array
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the file was found
    if (index == -1) {
        return;
    }

    // Remove the file from the array
    free(files[index].name);
    for (int i = index + 1; i < num_files; i++) {
        files[i - 1] = files[i];
    }

    // Decrement the number of files
    num_files--;
}

// List the files in the backup system
void list_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%ld\t%ld\n", files[i].name, files[i].last_modified, files[i].size);
    }
}

// Back up a file to the backup system
void backup_file(char* name) {
    // Open the file
    FILE* file = fopen(name, "rb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    // Allocate a buffer to hold the file data
    char* buffer = malloc(size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(file);
        return;
    }

    // Read the file data into the buffer
    fread(buffer, size, 1, file);

    // Close the file
    fclose(file);

    // Add the file to the backup system
    add_file(name, time(NULL), size);

    // Write the file data to the backup file
    FILE* backup_file = fopen("backup.bin", "wb");
    if (backup_file == NULL) {
        perror("fopen");
        free(buffer);
        return;
    }

    fwrite(buffer, size, 1, backup_file);

    // Close the backup file
    fclose(backup_file);

    // Free the buffer
    free(buffer);
}

// Restore a file from the backup system
void restore_file(char* name) {
    // Find the file in the backup system
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the file was found
    if (index == -1) {
        printf("File not found in backup system\n");
        return;
    }

    // Open the backup file
    FILE* backup_file = fopen("backup.bin", "rb");
    if (backup_file == NULL) {
        perror("fopen");
        return;
    }

    // Allocate a buffer to hold the file data
    char* buffer = malloc(files[index].size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(backup_file);
        return;
    }

    // Seek to the file data in the backup file
    fseek(backup_file, files[index].size * index, SEEK_SET);

    // Read the file data into the buffer
    fread(buffer, files[index].size, 1, backup_file);

    // Close the backup file
    fclose(backup_file);

    // Open the file to be restored
    FILE* file = fopen(name, "wb");
    if (file == NULL) {
        perror("fopen");
        free(buffer);
        return;
    }

    // Write the file data to the file to be restored
    fwrite(buffer, files[index].size, 1, file);

    // Close the file to be restored
    fclose(file);

    // Free the buffer
    free(buffer);
}

// Main function
int main() {
    // Initialize the file backup system
    init_backup_system();

    // Add some files to the backup system
    add_file("file1.txt", time(NULL), 100);
    add_file("file2.txt", time(NULL), 200);
    add_file("file3.txt", time(NULL), 300);

    // List the files in the backup system
    printf("Files in backup system:\n");
    list_files();

    // Back up a file to the backup system
    backup_file("file4.txt");

    // Restore a file from the backup system
    restore_file("file2.txt");

    return 0;
}