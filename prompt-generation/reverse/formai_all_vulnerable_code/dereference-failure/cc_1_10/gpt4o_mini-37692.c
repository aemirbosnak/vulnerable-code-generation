//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTENT_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    int size;
} File;

typedef struct {
    char name[MAX_NAME_LENGTH];
    File files[MAX_FILES];
    int file_count;
} Directory;

Directory* create_directory(const char* name) {
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    strncpy(dir->name, name, MAX_NAME_LENGTH);
    dir->file_count = 0;
    return dir;
}

void free_directory(Directory* dir) {
    free(dir);
}

void create_file(Directory* dir, const char* name, const char* content) {
    if (dir->file_count >= MAX_FILES) {
        printf("Error: Maximum number of files reached in directory.\n");
        return;
    }

    File* new_file = &dir->files[dir->file_count++];
    strncpy(new_file->name, name, MAX_NAME_LENGTH);
    strncpy(new_file->content, content, MAX_CONTENT_LENGTH);
    new_file->size = strlen(content);
    printf("File '%s' created in directory '%s'.\n", name, dir->name);
}

void delete_file(Directory* dir, const char* name) {
    int found = 0;
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < dir->file_count - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }
            dir->file_count--;
            printf("File '%s' deleted from directory '%s'.\n", name, dir->name);
            break;
        }
    }
    if (!found) {
        printf("Error: File '%s' not found in directory '%s'.\n", name, dir->name);
    }
}

void display_files(Directory* dir) {
    if (dir->file_count == 0) {
        printf("Directory '%s' is empty.\n", dir->name);
        return;
    }
    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("  %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

void read_file(Directory* dir, const char* name) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            printf("Contents of file '%s':\n%s\n", name, dir->files[i].content);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

int main() {
    Directory* myDirectory = create_directory("MyDocuments");
    create_file(myDirectory, "resume.txt", "This is my resume content.");
    create_file(myDirectory, "cover_letter.txt", "This is my cover letter content.");
    create_file(myDirectory, "notes.txt", "These are my notes.");

    display_files(myDirectory);

    read_file(myDirectory, "resume.txt");
    delete_file(myDirectory, "cover_letter.txt");
    display_files(myDirectory);

    read_file(myDirectory, "cover_letter.txt");

    // Free resources
    free_directory(myDirectory);
    return 0;
}