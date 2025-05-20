//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

typedef struct node {
    char *name;
    size_t size;
    time_t mtime;
    struct node *parent;
    struct node *children;
    struct node *next;
} node_t;

node_t *root = NULL;

void add_node(node_t *parent, char *name, size_t size, time_t mtime) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->size = size;
    new_node->mtime = mtime;
    new_node->parent = parent;
    new_node->children = NULL;
    new_node->next = NULL;

    if (parent == NULL) {
        root = new_node;
    } else {
        node_t *last_child = parent->children;
        if (last_child == NULL) {
            parent->children = new_node;
        } else {
            while (last_child->next != NULL) {
                last_child = last_child->next;
            }
            last_child->next = new_node;
        }
    }
}

void free_tree(node_t *node) {
    if (node == NULL) {
        return;
    }

    free_tree(node->children);
    free(node->name);
    free(node);
}

void print_tree(node_t *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%s (%ld bytes, %s)\n", node->name, node->size, ctime(&node->mtime));

    node_t *child = node->children;
    while (child != NULL) {
        print_tree(child, depth + 1);
        child = child->next;
    }
}

void analyze_directory(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            free(full_path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            add_node(NULL, entry->d_name, 0, statbuf.st_mtime);
            analyze_directory(full_path);
        } else {
            add_node(NULL, entry->d_name, statbuf.st_size, statbuf.st_mtime);
        }

        free(full_path);
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);
    print_tree(root, 0);
    free_tree(root);

    return 0;
}