//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LEN 50

typedef struct {
    char name[FILENAME_LEN];
    int size;  // Size of the file in bytes
    char *data; // Pointer to file data
} File;

typedef struct {
    char name[FILENAME_LEN];
    File *files[MAX_FILES];
    int file_count;
} Directory;

Directory *create_directory(const char *name) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    strcpy(dir->name, name);
    dir->file_count = 0;
    return dir;
}

File *create_file(const char *name, const char *data) {
    File *file = (File *)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = strlen(data);
    file->data = (char *)malloc(file->size + 1);
    strcpy(file->data, data);
    return file;
}

void add_file_to_directory(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = file;
    } else {
        printf("Directory is full! Cannot add more files.\n");
    }
}

void list_files(Directory *dir) {
    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("%s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

void delete_file(Directory *dir, const char *filename) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i]->name, filename) == 0) {
            free(dir->files[i]->data);
            free(dir->files[i]);
            for (int j = i; j < dir->file_count - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }
            dir->file_count--;
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
    }
    printf("File '%s' not found!\n", filename);
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i]->data);
        free(dir->files[i]);
    }
    free(dir);
}

int main() {
    Directory *myDir = create_directory("MyDocuments");
    
    add_file_to_directory(myDir, create_file("file1.txt", "Hello, this is file 1."));
    add_file_to_directory(myDir, create_file("file2.txt", "Hello, this is file 2."));
    add_file_to_directory(myDir, create_file("file3.txt", "Hello, this is file 3."));
    
    list_files(myDir);
    
    delete_file(myDir, "file2.txt");
    
    list_files(myDir);
    
    delete_file(myDir, "file4.txt");
    
    free_directory(myDir);
    
    return 0;
}