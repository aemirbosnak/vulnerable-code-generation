//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50
#define MAX_CONTENT_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    time_t creation_time;
    int size;
} File;

typedef struct {
    File* files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem* create_file_system();
void delete_file_system(FileSystem* fs);
int create_file(FileSystem* fs, const char* name, const char* content);
int delete_file(FileSystem* fs, const char* name);
File* get_file(FileSystem* fs, const char* name);
void display_file_info(File* file);
void list_files(FileSystem* fs);
void modify_file(FileSystem* fs, const char* name, const char* new_content);

int main() {
    FileSystem* fs = create_file_system();
    
    create_file(fs, "file1.txt", "Hello, this is the content of file1.");
    create_file(fs, "file2.txt", "This is file2's content. It is a nice day.");
    
    printf("Listing Files:\n");
    list_files(fs);
    
    printf("\nModifying file1.txt:\n");
    modify_file(fs, "file1.txt", "The content has been modified!");
    
    File* file_info = get_file(fs, "file1.txt");
    if (file_info) {
        display_file_info(file_info);
    }
    
    printf("\nDeleting file2.txt:\n");
    delete_file(fs, "file2.txt");
    
    printf("\nFinal file listing:\n");
    list_files(fs);
    
    delete_file_system(fs);
    return 0;
}

FileSystem* create_file_system() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->file_count = 0;
    return fs;
}

void delete_file_system(FileSystem* fs) {
    for (int i = 0; i < fs->file_count; i++) {
        free(fs->files[i]);
    }
    free(fs);
}

int create_file(FileSystem* fs, const char* name, const char* content) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    
    File* file = (File*)malloc(sizeof(File));
    strncpy(file->name, name, FILENAME_LENGTH);
    strncpy(file->content, content, MAX_CONTENT_LENGTH);
    file->creation_time = time(NULL);
    file->size = strlen(content);
    
    fs->files[fs->file_count++] = file;
    return 0;
}

int delete_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            fs->files[i] = fs->files[fs->file_count - 1];
            fs->file_count--;
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

File* get_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            return fs->files[i];
        }
    }
    return NULL;
}

void display_file_info(File* file) {
    printf("File Name: %s\n", file->name);
    printf("Content: %s\n", file->content);
    printf("Size: %d bytes\n", file->size);
    printf("Creation Time: %s", ctime(&file->creation_time));
}

void list_files(FileSystem* fs) {
    for (int i = 0; i < fs->file_count; i++) {
        printf("%s\n", fs->files[i]->name);
    }
}

void modify_file(FileSystem* fs, const char* name, const char* new_content) {
    File* file = get_file(fs, name);
    if (file) {
        strncpy(file->content, new_content, MAX_CONTENT_LENGTH);
        file->size = strlen(new_content);
        file->creation_time = time(NULL);
        printf("File %s modified successfully.\n", name);
    } else {
        printf("Error: File not found for modification.\n");
    }
}