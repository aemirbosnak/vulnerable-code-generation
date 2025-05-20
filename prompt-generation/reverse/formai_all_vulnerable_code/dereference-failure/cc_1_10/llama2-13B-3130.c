//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 256
#define MAX_FILES 100

// Struct to represent a file in the file system
struct file {
    char *name;
    int size;
    int permissions;
};

// Global variables to keep track of the file system
struct file *files[MAX_FILES];
int num_files = 0;

// Function to create a new file
void create_file(char *name, int size, int permissions) {
    struct file *file = malloc(sizeof(struct file));
    file->name = name;
    file->size = size;
    file->permissions = permissions;
    files[num_files] = file;
    num_files++;
}

// Function to delete a file
void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            free(files[i]);
            num_files--;
            break;
        }
    }
}

// Function to list all files in the file system
void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d, %o)\n", files[i]->name, files[i]->size, files[i]->permissions);
    }
}

// Function to check if a file exists
int file_exists(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to create a new directory
void create_directory(char *name) {
    struct file *dir = malloc(sizeof(struct file));
    dir->name = name;
    dir->size = 0;
    dir->permissions = 0755;
    files[num_files] = dir;
    num_files++;
}

// Function to delete a directory
void delete_directory(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            // Free all the files in the directory
            int j;
            for (j = 0; j < num_files; j++) {
                if (files[j]->name != name) {
                    continue;
                }
                free(files[j]);
                num_files--;
                break;
            }
            free(files[i]);
            num_files--;
            break;
        }
    }
}

int main() {
    // Create some files and directories
    create_file("file1.txt", 1024, 0644);
    create_file("file2.txt", 2048, 0644);
    create_file("file3.txt", 3072, 0644);
    create_directory("directory1");
    create_directory("directory2");

    // List all files and directories
    list_files();

    // Delete some files and directories
    delete_file("file1.txt");
    delete_file("file2.txt");
    delete_directory("directory1");

    // Check if a file exists
    if (file_exists("file3.txt")) {
        printf("File 'file3.txt' exists\n");
    } else {
        printf("File 'file3.txt' does not exist\n");
    }

    return 0;
}