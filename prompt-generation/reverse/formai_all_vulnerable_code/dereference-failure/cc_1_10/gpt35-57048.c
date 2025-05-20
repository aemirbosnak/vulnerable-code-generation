//FormAI DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SYSTEM_SIZE 1024

typedef struct _file {
    char* name;
    int size;
} File;

typedef struct _directory {
    char* name;
    int num_files;
    int max_files;
    File* files;
} Directory;

typedef struct _filesystem {
    int num_directories;
    int max_directories;
    Directory* directories;
    int file_system_size;
    int free_space;
} FileSystem;

// Function declarations
void init_file_system(FileSystem* fs, int size);
Directory* create_directory(FileSystem* fs, char* name);
File* create_file(Directory* dir, char* name, int size);
void delete_file(Directory* dir, char* name);
void print_file_system(FileSystem* fs);

int main() {
    FileSystem fs;
    init_file_system(&fs, MAX_FILE_SYSTEM_SIZE);

    // Create some directories and files
    Directory* dir1 = create_directory(&fs, "Folder 1");
    File* file1 = create_file(dir1, "File 1", 50);
    File* file2 = create_file(dir1, "File 2", 75);

    Directory* dir2 = create_directory(&fs, "Folder 2");
    File* file3 = create_file(dir2, "File 3", 100);
    File* file4 = create_file(dir2, "File 4", 25);

    // Delete a file
    delete_file(dir1, "File 2");

    // Print file system
    print_file_system(&fs);

    return 0;
}

void init_file_system(FileSystem* fs, int size) {
    fs->num_directories = 0;
    fs->max_directories = 10;
    fs->directories = malloc(fs->max_directories * sizeof(Directory));
    fs->file_system_size = size;
    fs->free_space = size;
}

Directory* create_directory(FileSystem* fs, char* name) {
    if (fs->num_directories >= fs->max_directories) {
        printf("Cannot create directory: maximum number of directories reached");
        return NULL;
    }

    Directory* dir = &fs->directories[fs->num_directories];
    dir->name = strdup(name);
    dir->num_files = 0;
    dir->max_files = 10;
    dir->files = malloc(dir->max_files * sizeof(File));

    fs->num_directories++;

    return dir;
}

File* create_file(Directory* dir, char* name, int size) {
    if (dir->num_files >= dir->max_files) {
        printf("Cannot create file: maximum number of files in directory reached");
        return NULL;
    }

    File* file = &dir->files[dir->num_files];
    file->name = strdup(name);
    file->size = size;

    dir->num_files++;
    dir->max_files -= size;
    if (dir->max_files < 0) {
        dir->max_files = 0;
    }

    return file;
}

void delete_file(Directory* dir, char* name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        File* file = &dir->files[i];
        if (strcmp(file->name, name) == 0) {
            dir->num_files--;
            dir->max_files += file->size;
            if (dir->max_files > MAX_FILE_SYSTEM_SIZE) {
                dir->max_files = MAX_FILE_SYSTEM_SIZE;
            }
            free(file->name);

            // Shift the rest of the files to fill the gap
            int j;
            for (j = i; j < dir->num_files; j++) {
                dir->files[j] = dir->files[j+1];
            }

            return;
        }
    }

    printf("File not found");
}

void print_file_system(FileSystem* fs) {
    printf("File system:\n");
    printf("  Total size: %d\n", fs->file_system_size);
    printf("  Free space: %d\n", fs->free_space);
    printf("  Directories:\n");

    int i;
    for (i = 0; i < fs->num_directories; i++) {
        Directory* dir = &fs->directories[i];
        printf("    %s (max size: %d, used size: %d, free size: %d)\n", dir->name, dir->max_files, dir->max_files - dir->num_files, dir->num_files);
        printf("    Files:\n");

        int j;
        for (j = 0; j < dir->num_files; j++) {
            File* file = &dir->files[j];
            printf("      %s (size: %d)\n", file->name, file->size);
        }
    }
}