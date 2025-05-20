//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum file size
#define MAX_FILE_SIZE 1024

// Define the maximum number of files
#define MAX_FILES 10

// Define the file backup system structure
typedef struct {
    char files[MAX_FILES][MAX_FILE_SIZE];
    int num_files;
} file_backup_system;

// Create a new file backup system
file_backup_system* create_file_backup_system() {
    file_backup_system* system = malloc(sizeof(file_backup_system));
    system->num_files = 0;
    return system;
}

// Add a file to the file backup system
void add_file_to_backup_system(file_backup_system* system, char* file_name) {
    // Check if the file backup system is full
    if (system->num_files >= MAX_FILES) {
        printf("Error: File backup system is full!\n");
        return;
    }

    // Check if the file already exists in the file backup system
    for (int i = 0; i < system->num_files; i++) {
        if (strcmp(system->files[i], file_name) == 0) {
            printf("Error: File already exists in the file backup system!\n");
            return;
        }
    }

    // Copy the file name to the file backup system
    strcpy(system->files[system->num_files], file_name);
    system->num_files++;
}

// Remove a file from the file backup system
void remove_file_from_backup_system(file_backup_system* system, char* file_name) {
    // Find the index of the file in the file backup system
    int index = -1;
    for (int i = 0; i < system->num_files; i++) {
        if (strcmp(system->files[i], file_name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the file was found
    if (index == -1) {
        printf("Error: File not found in the file backup system!\n");
        return;
    }

    // Remove the file from the file backup system
    for (int i = index; i < system->num_files - 1; i++) {
        strcpy(system->files[i], system->files[i + 1]);
    }

    system->num_files--;
}

// Print the files in the file backup system
void print_files_in_backup_system(file_backup_system* system) {
    printf("Files in the file backup system:\n");
    for (int i = 0; i < system->num_files; i++) {
        printf("%s\n", system->files[i]);
    }
}

// Free the memory allocated for the file backup system
void free_file_backup_system(file_backup_system* system) {
    free(system);
}

// Main function
int main() {
    // Create a new file backup system
    file_backup_system* system = create_file_backup_system();

    // Add files to the file backup system
    add_file_to_backup_system(system, "file1.txt");
    add_file_to_backup_system(system, "file2.txt");
    add_file_to_backup_system(system, "file3.txt");

    // Print the files in the file backup system
    print_files_in_backup_system(system);

    // Remove a file from the file backup system
    remove_file_from_backup_system(system, "file2.txt");

    // Print the files in the file backup system
    print_files_in_backup_system(system);

    // Free the memory allocated for the file backup system
    free_file_backup_system(system);

    return 0;
}