//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 1024

typedef struct node {
    char name[MAX_PATH_LEN];
    long size;
    struct node *left;
    struct node *right;
} node_t;

node_t *root = NULL;

void insert(char *path, long size) {
    if (root == NULL) {
        root = malloc(sizeof(node_t));
        strcpy(root->name, path);
        root->size = size;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    node_t *current = root;
    while (1) {
        if (strcmp(path, current->name) < 0) {
            if (current->left == NULL) {
                current->left = malloc(sizeof(node_t));
                strcpy(current->left->name, path);
                current->left->size = size;
                current->left->left = NULL;
                current->left->right = NULL;
                return;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = malloc(sizeof(node_t));
                strcpy(current->right->name, path);
                current->right->size = size;
                current->right->left = NULL;
                current->right->right = NULL;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

void print_tree(node_t *node) {
    if (node == NULL) {
        return;
    }
    print_tree(node->left);
    printf("%s: %ld\n", node->name, node->size);
    print_tree(node->right);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    long total_size = 0;
    char *path = argv[1];
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    char line[MAX_PATH_LEN];
    while (fgets(line, MAX_PATH_LEN, fp) != NULL) {
        char *path = strtok(line, " ");
        long size = atol(strtok(NULL, " "));
        total_size += size;
        insert(path, size);
    }
    fclose(fp);
    printf("Total size: %ld\n", total_size);
    print_tree(root);
    return 0;
}