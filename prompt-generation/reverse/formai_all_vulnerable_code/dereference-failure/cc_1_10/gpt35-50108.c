//FormAI DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 30
#define MAX_FILE_SIZE 1024

// Data structures for file system simulation
typedef struct {
    char *name;
    int size;
    char *content;
} File;

typedef struct {
    File *files;
    int num_files;
    int max_size;
} FileSystem;

// Function prototypes
void init_file_system(FileSystem *fs, int max_size);
void format_file_system(FileSystem *fs);
void create_file(FileSystem *fs, char *name, int size, char *content);
void delete_file(FileSystem *fs, char *name);
void read_file(FileSystem *fs, char *name);
void write_file(FileSystem *fs, char *name, char *content);
void list_files(FileSystem *fs);

// Main function
int main() {
    FileSystem fs;
    int max_size;

    // Get the maximum size of the file system
    printf("Enter the maximum size of the file system (in bytes): ");
    scanf("%d", &max_size);

    // Initialize and format the file system
    init_file_system(&fs, max_size);
    format_file_system(&fs);

    // Interactive menu
    while (1) {
        int choice;
        printf("\n");
        printf("1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Read a file\n");
        printf("4. Write to a file\n");
        printf("5. List all files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_FILE_NAME];
                int size;
                char content[MAX_FILE_SIZE];
                printf("Enter the name of the file: ");
                scanf("%s", name);
                printf("Enter the size of the file (in bytes): ");
                scanf("%d", &size);
                printf("Enter the content of the file: ");
                scanf("%s", content);
                create_file(&fs, name, size, content);
                break;
            }
            case 2: {
                char name[MAX_FILE_NAME];
                printf("Enter the name of the file: ");
                scanf("%s", name);
                delete_file(&fs, name);
                break;
            }
            case 3: {
                char name[MAX_FILE_NAME];
                printf("Enter the name of the file: ");
                scanf("%s", name);
                read_file(&fs, name);
                break;
            }
            case 4: {
                char name[MAX_FILE_NAME];
                char content[MAX_FILE_SIZE];
                printf("Enter the name of the file: ");
                scanf("%s", name);
                printf("Enter the new content of the file: ");
                scanf("%s", content);
                write_file(&fs, name, content);
                break;
            }
            case 5: {
                list_files(&fs);
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    }
}

// Initialize the file system with the given maximum size
void init_file_system(FileSystem *fs, int max_size) {
    fs->files = (File *) malloc(sizeof(File));
    fs->num_files = 0;
    fs->max_size = max_size;
}

// Format the file system by deleting all files
void format_file_system(FileSystem *fs) {
    fs->num_files = 0;
}

// Create a new file with the given name, size, and content
void create_file(FileSystem *fs, char *name, int size, char *content) {
    if (fs->num_files == MAX_FILE_SIZE) {
        printf("File system is full, cannot create file.\n");
        return;
    }
    if (strlen(name) + 1 > MAX_FILE_NAME) {
        printf("Name of the file is too long, cannot create file.\n");
        return;
    }
    if (size > fs->max_size - MAX_FILE_NAME) {
        printf("File size is larger than remaining space in file system, cannot create file.\n");
        return;
    }
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(name, fs->files[i].name) == 0) {
            printf("File with the same name already exists, cannot create file.\n");
            return;
        }
    }
    fs->files[fs->num_files].name = (char *) malloc(strlen(name) + 1);
    strcpy(fs->files[fs->num_files].name, name);
    fs->files[fs->num_files].size = size;
    fs->files[fs->num_files].content = (char *) malloc(size);
    memcpy(fs->files[fs->num_files].content, content, size);
    fs->num_files++;
    printf("File created successfully.\n");
}

// Delete the file with the given name
void delete_file(FileSystem *fs, char *name) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(name, fs->files[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found, cannot delete file.\n");
        return;
    }
    fs->num_files--;
    for (int i = index; i < fs->num_files; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    printf("File deleted successfully.\n");
}

// Read and print the contents of the file with the given name
void read_file(FileSystem *fs, char *name) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(name, fs->files[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found, cannot read file.\n");
        return;
    }
    printf("File contents: %s\n", fs->files[index].content);
}

// Write the given content to the file with the given name
void write_file(FileSystem *fs, char *name, char *content) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(name, fs->files[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found, cannot write to file.\n");
        return;
    }
    if (strlen(content) > fs->files[index].size) {
        printf("New content is larger than file size, cannot write to file.\n");
        return;
    }
    memcpy(fs->files[index].content, content, strlen(content) + 1);
    printf("File updated successfully.\n");
}

// List all files in the file system
void list_files(FileSystem *fs) {
    if (fs->num_files == 0) {
        printf("File system is empty.\n");
        return;
    }
    printf("Files in the file system:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}