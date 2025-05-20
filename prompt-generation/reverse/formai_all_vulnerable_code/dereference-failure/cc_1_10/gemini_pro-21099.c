//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the maximum number of files
#define MAX_FILES 10

// Define the maximum length of a file name
#define MAX_FILE_NAME_LENGTH 32

// Define the maximum number of directories
#define MAX_DIRECTORIES 10

// Define the maximum length of a directory name
#define MAX_DIRECTORY_NAME_LENGTH 32

// Define the root directory
#define ROOT_DIRECTORY "/"

// Define the current directory
#define CURRENT_DIRECTORY "."

// Define the parent directory
#define PARENT_DIRECTORY ".."

// Define the file system structure
typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    time_t last_modified;
} file;

typedef struct {
    char name[MAX_DIRECTORY_NAME_LENGTH];
    file files[MAX_FILES];
    int num_files;
} directory;

// Define the file system
directory file_system[MAX_DIRECTORIES];
int num_directories;

// Initialize the file system
void init_file_system() {
    // Create the root directory
    strcpy(file_system[0].name, ROOT_DIRECTORY);
    file_system[0].num_files = 0;

    // Set the current directory to the root directory
    strcpy(CURRENT_DIRECTORY, ROOT_DIRECTORY);

    // Set the number of directories to 1
    num_directories = 1;
}

// Create a new file
file *create_file(char *name, int size) {
    // Check if the file already exists
    for (int i = 0; i < file_system[num_directories - 1].num_files; i++) {
        if (strcmp(file_system[num_directories - 1].files[i].name, name) == 0) {
            return NULL;
        }
    }

    // Create the new file
    file *new_file = &file_system[num_directories - 1].files[file_system[num_directories - 1].num_files];
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->last_modified = time(NULL);

    // Increment the number of files in the current directory
    file_system[num_directories - 1].num_files++;

    // Return the new file
    return new_file;
}

// Delete a file
void delete_file(char *name) {
    // Find the file
    for (int i = 0; i < file_system[num_directories - 1].num_files; i++) {
        if (strcmp(file_system[num_directories - 1].files[i].name, name) == 0) {
            // Delete the file
            for (int j = i + 1; j < file_system[num_directories - 1].num_files; j++) {
                file_system[num_directories - 1].files[j - 1] = file_system[num_directories - 1].files[j];
            }
            file_system[num_directories - 1].num_files--;
            return;
        }
    }
}

// Create a new directory
directory *create_directory(char *name) {
    // Check if the directory already exists
    for (int i = 0; i < num_directories; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            return NULL;
        }
    }

    // Create the new directory
    directory *new_directory = &file_system[num_directories];
    strcpy(new_directory->name, name);
    new_directory->num_files = 0;

    // Increment the number of directories
    num_directories++;

    // Return the new directory
    return new_directory;
}

// Delete a directory
void delete_directory(char *name) {
    // Find the directory
    for (int i = 0; i < num_directories; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            // Delete the directory
            for (int j = i + 1; j < num_directories; j++) {
                file_system[j - 1] = file_system[j];
            }
            num_directories--;
            return;
        }
    }
}

// Change the current directory
void change_directory(char *name) {
    // Check if the directory exists
    for (int i = 0; i < num_directories; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            // Set the current directory to the new directory
            strcpy(CURRENT_DIRECTORY, name);
            return;
        }
    }
}

// List the files and directories in the current directory
void ls() {
    // Print the files
    for (int i = 0; i < file_system[num_directories - 1].num_files; i++) {
        printf("%s\n", file_system[num_directories - 1].files[i].name);
    }

    // Print the directories
    for (int i = 0; i < num_directories; i++) {
        printf("%s\n", file_system[i].name);
    }
}

// Print the working directory
void pwd() {
    printf("%s\n", CURRENT_DIRECTORY);
}

// Main function
int main() {
    // Initialize the file system
    init_file_system();

    // Create a new file
    file *new_file = create_file("test.txt", 1024);

    // Print the file size
    printf("File size: %d\n", new_file->size);

    // Delete the file
    delete_file("test.txt");

    // Create a new directory
    directory *new_directory = create_directory("test_directory");

    // Change the current directory
    change_directory("test_directory");

    // List the files and directories in the current directory
    ls();

    // Print the working directory
    pwd();

    return 0;
}