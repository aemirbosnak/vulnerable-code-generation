//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define CHUNK_SIZE 1024 * 1024

typedef struct node_t {
    char *name;
    struct node_t *left;
    struct node_t *right;
    size_t size;
} node_t;

node_t *create_node(char *name, size_t size) {
    node_t *node = malloc(sizeof(node_t));
    node->name = strdup(name);
    node->left = NULL;
    node->right = NULL;
    node->size = size;
    return node;
}

void insert_node(node_t **root, node_t *node) {
    if (*root == NULL) {
        *root = node;
        return;
    }

    if (node->size < (*root)->size) {
        insert_node(&(*root)->left, node);
    } else {
        insert_node(&(*root)->right, node);
    }
}

void print_node(node_t *node) {
    printf("%s: %ld bytes\n", node->name, node->size);
}

void free_node(node_t *node) {
    if (node == NULL) {
        return;
    }

    free(node->name);
    free(node->left);
    free(node->right);
    free(node);
}

void analyze_directory(char *path, node_t **root) {
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
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            free(full_path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path, root);
        } else {
            node_t *node = create_node(full_path, statbuf.st_size);
            insert_node(root, node);
        }

        free(full_path);
    }

    closedir(dir);
}

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    print_node(root);
    print_tree(root->left);
    print_tree(root->right);
}

void free_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    free_node(root->left);
    free_node(root->right);
    free_node(root);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    node_t *root = NULL;
    analyze_directory(argv[1], &root);
    print_tree(root);
    free_tree(root);

    return EXIT_SUCCESS;
}