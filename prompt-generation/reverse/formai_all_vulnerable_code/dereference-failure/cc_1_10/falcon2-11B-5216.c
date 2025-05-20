//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 100

struct file_system {
    char path[MAX_PATH_LENGTH];
    char content[MAX_PATH_LENGTH];
};

void create_file(struct file_system *fs, const char *path, const char *content) {
    fs->path[0] = '\0';
    strcpy(fs->path, path);
    fs->content[0] = '\0';
    strcpy(fs->content, content);
    printf("Created file %s with content %s\n", fs->path, fs->content);
}

void delete_file(struct file_system *fs) {
    printf("Deleted file %s\n", fs->path);
    free(fs);
}

void read_file(struct file_system *fs) {
    printf("Reading file %s\n", fs->path);
    printf("Content: %s\n", fs->content);
}

void write_file(struct file_system *fs, const char *content) {
    fs->path[0] = '\0';
    strcpy(fs->path, ".");
    fs->content[0] = '\0';
    strcpy(fs->content, content);
    printf("Writing to file %s with content %s\n", fs->path, fs->content);
}

int main() {
    struct file_system *fs;
    char path[MAX_PATH_LENGTH];
    char content[MAX_PATH_LENGTH];

    printf("Enter file path: ");
    scanf("%s", path);
    printf("Enter file content: ");
    scanf("%s", content);

    fs = malloc(sizeof(struct file_system));
    strcpy(fs->path, path);
    strcpy(fs->content, content);

    create_file(fs, path, content);
    read_file(fs);
    write_file(fs, "Hello, world!");
    delete_file(fs);

    return 0;
}