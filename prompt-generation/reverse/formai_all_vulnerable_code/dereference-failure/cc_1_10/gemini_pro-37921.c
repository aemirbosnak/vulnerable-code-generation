//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

typedef struct _FileNode {
    char *path;
    long size;
    struct _FileNode *next;
} FileNode;

FileNode *head = NULL;
FileNode *tail = NULL;

void insertFileNode(char *path, long size) {
    FileNode *new_node = malloc(sizeof(FileNode));
    new_node->path = malloc(strlen(path) + 1);
    strcpy(new_node->path, path);
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void printFileNode(FileNode *node) {
    printf("%s: %ld bytes\n", node->path, node->size);
}

long getDirectorySize(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    long size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(full_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                size += getDirectorySize(full_path);
            } else {
                size += st.st_size;
                insertFileNode(full_path, st.st_size);
            }
        }

        free(full_path);
    }

    closedir(dir);
    return size;
}

void printDirectorySize(char *path) {
    long size = getDirectorySize(path);
    if (size == -1) {
        printf("Error: Could not open directory %s\n", path);
        return;
    }

    printf("Directory size: %ld bytes\n", size);
    printf("Files:\n");

    FileNode *node = head;
    while (node != NULL) {
        printFileNode(node);
        node = node->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printDirectorySize(argv[1]);
    return EXIT_SUCCESS;
}