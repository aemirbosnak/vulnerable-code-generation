//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct node {
    char *name;
    struct node *next;
} node_t;

typedef struct {
    char *path;
    node_t *files;
    long long int size;
} dir_t;

void free_node(node_t *node) {
    if (node == NULL) {
        return;
    }
    free(node->name);
    free(node);
}

void free_dir(dir_t *dir) {
    if (dir == NULL) {
        return;
    }
    free(dir->path);
    node_t *node = dir->files;
    while (node != NULL) {
        node_t *next = node->next;
        free_node(node);
        node = next;
    }
    free(dir);
}

void print_node(node_t *node) {
    if (node == NULL) {
        return;
    }
    printf("%s\n", node->name);
}

void print_dir(dir_t *dir) {
    if (dir == NULL) {
        return;
    }
    printf("%s (%lld bytes)\n", dir->path, dir->size);
    node_t *node = dir->files;
    while (node != NULL) {
        print_node(node);
        node = node->next;
    }
}

long long int get_dir_size(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }
    long long int size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);
        struct stat statbuf;
        if (lstat(full_path, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                size += get_dir_size(full_path);
            } else {
                size += statbuf.st_size;
            }
        }
        free(full_path);
    }
    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    char *path = argv[1];
    dir_t *dir = malloc(sizeof(dir_t));
    dir->path = strdup(path);
    dir->files = NULL;
    dir->size = get_dir_size(path);
    print_dir(dir);
    free_dir(dir);
    return 0;
}