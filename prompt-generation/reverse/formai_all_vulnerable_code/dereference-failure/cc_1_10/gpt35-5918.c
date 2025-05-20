//FormAI DATASET v1.0 Category: File system simulation ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Struct that represents a file entry in the file system
typedef struct file_entry {
    char name[20];
    int size;
    char content[100];
} FileEntry;

// Struct that represents a directory entry in the file system
typedef struct directory_entry {
    char name[20];
    int num_files;
    struct directory_entry* subdirectories[10];
    FileEntry* files[10];
} DirectoryEntry;

// Function to add a directory to the file system
DirectoryEntry* create_directory(char name[]) {
    DirectoryEntry* dir = (DirectoryEntry*) malloc(sizeof(DirectoryEntry));
    strcpy(dir->name, name);
    dir->num_files = 0;
    for (int i = 0; i < 10; i++) {
        dir->subdirectories[i] = NULL;
        dir->files[i] = NULL;
    }
    return dir;
}

// Function to add a file to the file system
FileEntry* create_file(char name[], int size, char content[]) {
    FileEntry* file = (FileEntry*) malloc(sizeof(FileEntry));
    strcpy(file->name, name);
    file->size = size;
    strcpy(file->content, content);
    return file;
}

// Function to add a file or directory to a given directory
void add_to_directory(DirectoryEntry* dir, void* item, int is_file) {
    if (is_file) {
        if (dir->num_files < 10) {
            dir->files[dir->num_files++] = (FileEntry*) item;
        } else {
            printf("Error: directory is full!\n");
        }
    } else {
        if (dir->num_files < 10) {
            dir->subdirectories[dir->num_files++] = (DirectoryEntry*) item;
        } else {
            printf("Error: directory is full!\n");
        }
    }
}

// Recursive function to print the file system tree
void print_directory(DirectoryEntry* dir, int level) {
    for (int i = 0; i < level; i++) printf("\t");
    printf("- %s (dir)\n", dir->name);
    for (int i = 0; i < dir->num_files; i++) {
        for (int j = 0; j < level + 1; j++) printf("\t");
        printf("- %s (file, %d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
    for (int i = 0; i < dir->num_files; i++) {
        if (dir->subdirectories[i] != NULL) {
            print_directory(dir->subdirectories[i], level + 1);
        }
    }
}

int main() {
    // Create root directory
    DirectoryEntry* root = create_directory("root");

    // Create subdirectories
    DirectoryEntry* dir1 = create_directory("dir1");
    DirectoryEntry* dir2 = create_directory("dir2");
    DirectoryEntry* dir3 = create_directory("dir3");

    // Create files
    FileEntry* file1 = create_file("file1.txt", 100, "This is file 1");
    FileEntry* file2 = create_file("file2.txt", 50, "This is file 2");
    FileEntry* file3 = create_file("file3.txt", 75, "This is file 3");

    // Add files and subdirectories to root directory
    add_to_directory(root, dir1, 0);
    add_to_directory(root, dir2, 0);
    add_to_directory(root, dir3, 0);
    add_to_directory(root, file1, 1);
    add_to_directory(root, file2, 1);

    // Add files to subdirectories
    add_to_directory(dir1, file3, 1);

    // Print file system tree
    print_directory(root, 0);

    return 0;
}