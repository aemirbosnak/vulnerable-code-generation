//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIRS 5
#define NAME_LENGTH 50

typedef struct File {
    char name[NAME_LENGTH];
    int size; // in bytes
} File;

typedef struct Directory {
    char name[NAME_LENGTH];
    File files[MAX_FILES];
    int file_count;
    struct Directory* subdirs[MAX_DIRS];
    int dir_count;
} Directory;

Directory* create_directory(const char* name) {
    Directory* new_dir = (Directory*)malloc(sizeof(Directory));
    strncpy(new_dir->name, name, NAME_LENGTH);
    new_dir->file_count = 0;
    new_dir->dir_count = 0;
    return new_dir;
}

File create_file(const char* name, int size) {
    File new_file;
    strncpy(new_file.name, name, NAME_LENGTH);
    new_file.size = size;
    return new_file;
}

void add_file(Directory* dir, const char* file_name, int file_size) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = create_file(file_name, file_size);
        printf("File '%s' added to directory '%s'.\n", file_name, dir->name);
    } else {
        printf("Directory '%s' is full! Cannot add more files.\n", dir->name);
    }
}

void add_subdirectory(Directory* parent_dir, Directory* subdir) {
    if (parent_dir->dir_count < MAX_DIRS) {
        parent_dir->subdirs[parent_dir->dir_count++] = subdir;
        printf("Subdirectory '%s' added to directory '%s'.\n", subdir->name, parent_dir->name);
    } else {
        printf("Directory '%s' has reached the maximum subdirectories!\n", parent_dir->name);
    }
}

void list_files_and_dirs(Directory* dir, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("Directory: %s\n", dir->name);
    
    for (int i = 0; i < dir->file_count; i++) {
        for (int j = 0; j < level + 1; j++) printf("  ");
        printf("File: %s, Size: %d bytes\n", dir->files[i].name, dir->files[i].size);
    }

    for (int i = 0; i < dir->dir_count; i++) {
        list_files_and_dirs(dir->subdirs[i], level + 1);
    }
}

void free_directory(Directory* dir) {
    for (int i = 0; i < dir->dir_count; i++) {
        free_directory(dir->subdirs[i]);
    }
    free(dir);
}

int main() {
    // Create root directory
    Directory* root = create_directory("root");
    
    // Add some files and directories to the root directory
    add_file(root, "file1.txt", 150);
    add_file(root, "file2.txt", 200);
    
    Directory* music_dir = create_directory("music");
    add_file(music_dir, "song1.mp3", 3000);
    
    Directory* images_dir = create_directory("images");
    add_file(images_dir, "photo1.png", 400);
    add_file(images_dir, "photo2.jpg", 600);
    
    add_subdirectory(root, music_dir);
    add_subdirectory(root, images_dir);
    
    // List contents of the file system
    printf("Listing file system contents:\n");
    list_files_and_dirs(root, 0);

    // Free memory allocation
    free_directory(root);

    return 0;
}