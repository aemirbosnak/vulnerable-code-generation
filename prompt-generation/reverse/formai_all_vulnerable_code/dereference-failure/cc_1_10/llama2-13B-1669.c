//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_FILE_LENGTH 4096

typedef struct {
    char name[MAX_NAME_LENGTH];
    char contents[MAX_FILE_LENGTH];
} file_t;

typedef struct {
    file_t *files;
    int num_files;
} file_system_t;

file_system_t *create_file_system(int num_files) {
    file_system_t *fs = (file_system_t *)malloc(sizeof(file_system_t));
    fs->files = (file_t *)malloc(num_files * sizeof(file_t));
    fs->num_files = num_files;
    return fs;
}

void add_file(file_system_t *fs, char *name, char *contents) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            break;
        }
    }
    if (i == fs->num_files) {
        printf("File already exists! (%s)\n", name);
        return;
    }
    strcpy(fs->files[i].name, name);
    strcpy(fs->files[i].contents, contents);
}

void list_files(file_system_t *fs) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("%d: %s (%s)\n", i, fs->files[i].name, fs->files[i].contents);
    }
}

void delete_file(file_system_t *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            break;
        }
    }
    if (i == fs->num_files) {
        printf("File not found! (%s)\n", name);
        return;
    }
    memset(fs->files[i].name, 0, MAX_NAME_LENGTH);
    memset(fs->files[i].contents, 0, MAX_FILE_LENGTH);
    fs->num_files--;
}

int main() {
    file_system_t *fs = create_file_system(10);

    // Add some files
    add_file(fs, "example1.txt", "This is the contents of example1.txt");
    add_file(fs, "example2.txt", "This is the contents of example2.txt");

    // List all files
    list_files(fs);

    // Delete a file
    delete_file(fs, "example1.txt");

    // List all files again
    list_files(fs);

    // Free memory
    free(fs->files);
    free(fs);

    return 0;
}