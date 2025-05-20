//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KiB 1024
#define MiB (KiB * 1024)
#define GiB (MiB * 1024)

typedef struct _Directory {
    char *name;
    size_t size;
    struct _Directory *next;
} Directory;

int isDirectory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

Directory* createNode(char *name, size_t size) {
    Directory *node = (Directory *)malloc(sizeof(Directory));
    node->name = strdup(name);
    node->size = size;
    node->next = NULL;
    return node;
}

void addNodeToList(Directory **head, Directory **current, Directory *node) {
    if (*head == NULL) {
        *head = node;
        *current = node;
    } else {
        (*current)->next = node;
        *current = node;
    }
}

size_t listFilesInDirectory(char *path, Directory **head) {
    struct dirent *dp;
    DIR *dir = opendir(path);
    size_t totalSize = 0;
    Directory *current = NULL;

    if (!dir) {
        fprintf(stderr, "Cannot open directory '%s'\n", path);
        return 0;
    }

    while ((dp = readdir(dir)) != NULL) {
        char *name = dp->d_name;
        if (!strcmp(name, ".") || !strcmp(name, ".."))
            continue;
        char *fullPath = (char *)malloc(strlen(path) + strlen(name) + 2);
        sprintf(fullPath, "%s/%s", path, name);
        if (isDirectory(fullPath)) {
            size_t size = listFilesInDirectory(fullPath, head);
            totalSize += size;
            addNodeToList(head, &current, createNode(fullPath, size));
        } else {
            struct stat st;
            if (stat(fullPath, &st) == 0) {
                totalSize += st.st_size;
                addNodeToList(head, &current, createNode(fullPath, st.st_size));
            } else {
                fprintf(stderr, "Cannot stat '%s'\n", fullPath);
            }
        }
        free(fullPath);
    }

    closedir(dir);
    return totalSize;
}

void printSize(size_t size) {
    if (size < KiB) {
        printf("%ld B", size);
    } else if (size < MiB) {
        printf("%.2f KiB", (double)size / KiB);
    } else if (size < GiB) {
        printf("%.2f MiB", (double)size / MiB);
    } else {
        printf("%.2f GiB", (double)size / GiB);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];
    size_t totalSize = 0;
    Directory *head = NULL;
    totalSize = listFilesInDirectory(path, &head);

    while (head != NULL) {
        printf("%s: ", head->name);
        printSize(head->size);
        printf("\n");
        head = head->next;
    }
    printf("Total directory size: ");
    printSize(totalSize);
    printf("\n");

    return 0;
}