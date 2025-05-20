//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: mind-bending
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
    File *files[MAX_FILES];
    int file_count;
} Directory;

Directory *create_directory(const char *name) {
    Directory *dir = malloc(sizeof(Directory));
    strcpy(dir->name, name);
    dir->file_count = 0;
    return dir;
}

File *create_file(const char *name, const char *content) {
    File *file = malloc(sizeof(File));
    strcpy(file->name, name);
    strcpy(file->content, content);
    file->size = strlen(content);
    return file;
}

void add_file(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = file;
        printf("File '%s' added to directory '%s'\n", file->name, dir->name);
    } else {
        printf("Cannot add file '%s': directory '%s' is full\n", file->name, dir->name);
    }
}

void list_files(Directory *dir) {
    printf("Directory '%s' contains:\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("  %s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

File *find_file(Directory *dir, const char *file_name) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i]->name, file_name) == 0) {
            return dir->files[i];
        }
    }
    return NULL;
}

void read_file(Directory *dir, const char *file_name) {
    File *file = find_file(dir, file_name);
    if (file) {
        printf("Reading file '%s':\n%s\n", file->name, file->content);
    } else {
        printf("File '%s' not found in directory '%s'\n", file_name, dir->name);
    }
}

void delete_file(Directory *dir, const char *file_name) {
    int found = 0;
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i]->name, file_name) == 0) {
            free(dir->files[i]);
            dir->files[i] = dir->files[dir->file_count - 1];
            dir->file_count--;
            found = 1;
            printf("File '%s' deleted from directory '%s'\n", file_name, dir->name);
            break;
        }
    }
    if (!found) {
        printf("File '%s' not found in directory '%s'\n", file_name, dir->name);
    }
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i]);
    }
    free(dir);
}

void mystical_file_system() {
    Directory *root = create_directory("root");

    add_file(root, create_file("magic.txt", "In the woods of coding, where the functions flow."));
    add_file(root, create_file("riddle.txt", "What has keys but can't open locks?"));

    list_files(root);
    
    read_file(root, "magic.txt");

    delete_file(root, "riddle.txt");
    list_files(root);

    read_file(root, "riddle.txt");

    delete_file(root, "nonexistent.txt");

    free_directory(root);
}

int main() {
    mystical_file_system();
    return 0;
}