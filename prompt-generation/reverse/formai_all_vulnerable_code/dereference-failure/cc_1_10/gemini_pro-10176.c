//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

typedef struct _tree_node {
    char *name;
    uint64_t size;
    struct _tree_node *left;
    struct _tree_node *right;
} tree_node;

tree_node *tree_insert(tree_node *root, const char *name, uint64_t size) {
    if (root == NULL) {
        root = malloc(sizeof(tree_node));
        root->name = strdup(name);
        root->size = size;
        root->left = root->right = NULL;
    } else if (strcmp(name, root->name) < 0) {
        root->left = tree_insert(root->left, name, size);
    } else if (strcmp(name, root->name) > 0) {
        root->right = tree_insert(root->right, name, size);
    }
    return root;
}

void tree_print(tree_node *root, int depth) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s (%lu bytes)\n", root->name, root->size);
    tree_print(root->left, depth + 1);
    tree_print(root->right, depth + 1);
}

void tree_free(tree_node *root) {
    if (root == NULL) {
        return;
    }
    free(root->name);
    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char path[PATH_MAX];
    realpath(argv[1], path);

    tree_node *root = NULL;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
        struct stat statbuf;
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            tree_insert(root, entry->d_name, 0);
        } else {
            tree_insert(root, entry->d_name, statbuf.st_size);
        }
    }

    closedir(dir);

    printf("Directory scan complete.\n");
    printf("===========================\n");
    tree_print(root, 0);
    tree_free(root);

    return EXIT_SUCCESS;
}