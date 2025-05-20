//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

typedef struct Node {
    char name[256];
    struct stat st;
    struct Node *next, *parent;
} Node;

Node *root = NULL;
Node *current = NULL;

void add_node(Node *parent, const char *name) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    stat(name, &new_node->st);
    new_node->next = parent->next;
    new_node->parent = parent;
    parent->next = new_node;
}

void traverse_directory(const char *path, Node *parent) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        Node *new_node = malloc(sizeof(Node));
        strcpy(new_node->name, entry->d_name);
        new_node->parent = parent;
        traverse_directory(full_path, new_node);
        add_node(parent, new_node->name);
        free(new_node);
    }

    closedir(dir);
}

void print_tree(Node *node, int depth) {
    for (int i = 0; i < depth; i++)
        printf("  ");

    if (S_ISDIR(node->st.st_mode))
        printf("+%s/\n", node->name);
    else
        printf("  %s: %lld bytes\n", node->name, node->st.st_size);

    Node *child = node->next;
    while (child != NULL) {
        print_tree(child, depth + 1);
        child = child->next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    current = malloc(sizeof(Node));
    strcpy(current->name, ".");
    root = current;

    traverse_directory(argv[1], current);

    printf("Directory %s:\n", argv[1]);
    print_tree(root, 0);

    Node *node = root;
    while (node != NULL) {
        Node *temp = node->next;
        free(node);
        node = temp;
    }

    free(root);

    return 0;
}