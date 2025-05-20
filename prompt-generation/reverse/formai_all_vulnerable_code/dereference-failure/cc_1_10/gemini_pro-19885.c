//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct Node {
    char *name;
    struct Node *parent;
    struct Node *children;
    size_t size;
};

struct Node *root;

void add_node(struct Node *parent, char *name, size_t size) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->name = name;
    new_node->parent = parent;
    new_node->children = NULL;
    new_node->size = size;
    if (parent == NULL) {
        root = new_node;
    } else {
        parent->children = new_node;
    }
}

void print_tree(struct Node *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("%s (%lu)\n", node->name, node->size);
    if (node->children != NULL) {
        print_tree(node->children, depth + 1);
    }
}

void free_tree(struct Node *node) {
    if (node->children != NULL) {
        free_tree(node->children);
    }
    free(node->name);
    free(node);
}

int main() {
    struct DIR *dir;
    struct dirent *ent;
    struct stat st;
    char path[PATH_MAX];

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", ".", ent->d_name);
        if (lstat(path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            add_node(NULL, ent->d_name, 0);
        } else if (S_ISREG(st.st_mode)) {
            add_node(NULL, ent->d_name, st.st_size);
        }
    }

    closedir(dir);

    print_tree(root, 0);

    free_tree(root);

    return EXIT_SUCCESS;
}