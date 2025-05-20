//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50

// File structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
} File;

// Directory structure
typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    int file_count;
    File files[MAX_FILES];
    struct Directory* parent;
    struct Directory* children[MAX_FILES];
    int child_count;
} Directory;

// Function declarations
Directory* create_directory(const char* name, Directory* parent);
void delete_directory(Directory* dir);
void create_file(Directory* dir, const char* name, int size);
void delete_file(Directory* dir, const char* name);
void list_files(Directory* dir);
void navigate_to_parent(Directory** current_dir);
void navigate_to_child(Directory** current_dir, const char* name);
void print_help();

int main() {
    char command[MAX_NAME_LENGTH];
    Directory* root = create_directory("root", NULL);
    Directory* current_dir = root;

    while (1) {
        printf("Current directory: %s > ", current_dir->name);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strncmp(command, "mkdir ", 6) == 0) {
            create_directory(command + 6, current_dir);
        } else if (strncmp(command, "touch ", 6) == 0) {
            char* name = command + 6;
            create_file(current_dir, name, 20); // Example file size of 20
        } else if (strncmp(command, "rm ", 3) == 0) {
            delete_file(current_dir, command + 3);
        } else if (strcmp(command, "ls") == 0) {
            list_files(current_dir);
        } else if (strcmp(command, "cd ..") == 0) {
            navigate_to_parent(&current_dir);
        } else {
            navigate_to_child(&current_dir, command);
        }
    }

    delete_directory(root);
    return 0;
}

// Create a new directory
Directory* create_directory(const char* name, Directory* parent) {
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    strncpy(dir->name, name, MAX_NAME_LENGTH);
    dir->file_count = 0;
    dir->child_count = 0;
    dir->parent = parent;

    if (parent) {
        parent->children[parent->child_count++] = dir;
    }

    printf("Directory '%s' created.\n", name);
    return dir;
}

// Delete a directory
void delete_directory(Directory* dir) {
    for (int i = 0; i < dir->child_count; i++) {
        delete_directory(dir->children[i]);
    }
    free(dir);
}

// Create a new file
void create_file(Directory* dir, const char* name, int size) {
    if (dir->file_count >= MAX_FILES) {
        printf("Cannot create file: Directory is full.\n");
        return;
    }
    strncpy(dir->files[dir->file_count].name, name, MAX_NAME_LENGTH);
    dir->files[dir->file_count].size = size;
    dir->file_count++;
    printf("File '%s' created in '%s'.\n", name, dir->name);
}

// Delete a file
void delete_file(Directory* dir, const char* name) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            printf("File '%s' deleted from directory '%s'.\n", name, dir->name);
            for (int j = i; j < dir->file_count - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }
            dir->file_count--;
            return;
        }
    }
    printf("File '%s' not found in directory '%s'.\n", name, dir->name);
}

// List files in the current directory
void list_files(Directory* dir) {
    printf("Files in '%s':\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf(" - %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
    if (dir->file_count == 0) {
        printf(" - No files\n");
    }
}

// Navigate to parent directory
void navigate_to_parent(Directory** current_dir) {
    if ((*current_dir)->parent) {
        *current_dir = (*current_dir)->parent;
        printf("Navigated to parent directory: %s\n", (*current_dir)->name);
    } else {
        printf("Already at the root directory.\n");
    }
}

// Navigate to child directory
void navigate_to_child(Directory** current_dir, const char* name) {
    for (int i = 0; i < (*current_dir)->child_count; i++) {
        if (strcmp((*current_dir)->children[i]->name, name) == 0) {
            *current_dir = (*current_dir)->children[i];
            printf("Navigated to directory: %s\n", (*current_dir)->name);
            return;
        }
    }
    printf("Directory '%s' not found.\n", name);
}

// Print help message
void print_help() {
    printf("Available commands:\n");
    printf(" mkdir <name>      : Create a new directory\n");
    printf(" touch <name>      : Create a new file\n");
    printf(" rm <name>         : Remove a file\n");
    printf(" ls                : List files\n");
    printf(" cd <name>         : Change to a subdirectory\n");
    printf(" cd ..             : Change to the parent directory\n");
    printf(" exit              : Exit the simulation\n");
}