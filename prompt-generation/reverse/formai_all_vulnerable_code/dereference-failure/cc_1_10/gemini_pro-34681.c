//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct node {
    char *path;
    long long size;
    struct node *left;
    struct node *right;
};

struct node *create_node(char *path, long long size) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->path = path;
    new_node->size = size;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, struct node *new_node) {
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    if (new_node->size > (*root)->size) {
        insert_node(&(*root)->right, new_node);
    } else {
        insert_node(&(*root)->left, new_node);
    }
}

void print_tree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s (%lld bytes)\n", root->path, root->size);

    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root->path);
    free(root);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *path = argv[1];
    struct node *root = NULL;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
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
            continue;
        }

        struct node *new_node = create_node(full_path, statbuf.st_size);
        insert_node(&root, new_node);

        free(full_path);
    }

    closedir(dir);

    print_tree(root, 0);

    free_tree(root);

    return 0;
}