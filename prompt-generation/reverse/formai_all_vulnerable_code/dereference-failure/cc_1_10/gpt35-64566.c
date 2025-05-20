//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max file and directory name length
#define MAX_NAME_LENGTH 100

// Max file count and directory count
#define MAX_COUNT 100

// File system entry type
enum entry_type {
    FILE_ENTRY,
    DIRECTORY_ENTRY
};

// File system entry structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    enum entry_type type;
} entry;

// Directory structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    entry* entries[MAX_COUNT];
    int count;
} directory;

// File structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char* content;
} file;

// Global file and directory array
entry* entries[MAX_COUNT];
int entry_count = 0;

// Function declarations
int add_directory(char* name);
int add_file(char* name, char* content);
directory* find_directory(char* name);
file* find_file(char* name);

// Add a new directory entry
int add_directory(char* name) {
    // Make sure the directory does not exist already
    if (find_directory(name) != NULL) {
        printf("Directory '%s' already exists!\n", name);
        return 0;
    }

    // Create a new directory
    directory* dir = (directory*)malloc(sizeof(directory));
    strcpy(dir->name, name);
    dir->count = 0;
    entries[entry_count++] = (entry*)dir;

    printf("Directory '%s' added!\n", name);

    return 1;
}

// Add a new file entry
int add_file(char* name, char* content) {
    // Make sure the file does not exist already
    if (find_file(name) != NULL) {
        printf("File '%s' already exists!\n", name);
        return 0;
    }

    // Create a new file
    file* f = (file*)malloc(sizeof(file));
    strcpy(f->name, name);
    f->content = (char*)malloc(strlen(content) + 1);
    strcpy(f->content, content);
    entries[entry_count++] = (entry*)f;

    printf("File '%s' added!\n", name);

    return 1;
}

// Find a directory by name
directory* find_directory(char* name) {
    int i;
    for (i = 0; i < entry_count; i++) {
        if (entries[i]->type == DIRECTORY_ENTRY) {
            directory* dir = (directory*)entries[i];
            if (strcmp(dir->name, name) == 0) {
                return dir;
            }
        }
    }

    return NULL;
}

// Find a file by name
file* find_file(char* name) {
    int i;
    for (i = 0; i < entry_count; i++) {
        if (entries[i]->type == FILE_ENTRY) {
            file* f = (file*)entries[i];
            if (strcmp(f->name, name) == 0) {
                return f;
            }
        }
    }

    return NULL;
}

// Print the contents of the file system
void print_file_system() {
    int i;
    for (i = 0; i < entry_count; i++) {
        if (entries[i]->type == DIRECTORY_ENTRY) {
            directory* dir = (directory*)entries[i];
            printf("%s/\n", dir->name);

            int j;
            for (j = 0; j < dir->count; j++) {
                if (dir->entries[j]->type == FILE_ENTRY) {
                    file* f = (file*)dir->entries[j];
                    printf("\t %s\n", f->name);
                } else {
                    directory* subdir = (directory*)dir->entries[j];
                    printf("\t %s/\n", subdir->name);
                }
            }
        } else {
            file* f = (file*)entries[i];
            printf("%s\n", f->name);
        }
    }
}

int main() {
    add_directory("home");
    directory* dir = find_directory("home");

    add_directory("photos");
    directory* subdir = find_directory("photos");
    dir->entries[dir->count++] = (entry*)subdir;

    add_file("vacation.jpg", "This is a photo of my vacation.");
    file* f = find_file("vacation.jpg");
    subdir->entries[subdir->count++] = (entry*)f;

    print_file_system();

    return 0;
}