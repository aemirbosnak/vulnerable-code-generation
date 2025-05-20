//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

void print_space(int num) {
    for (int i = 0; i < num; i++) putchar(' ');
}

void create_file(int depth, int space_num) {
    char filename[10];
    sprintf(filename, "tree%d.txt", depth);
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < depth; i++) putchar('\t');
    putchar('-');
    putchar('\n');
    close(fd);
}

Node* new_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node** tree, int key) {
    if (*tree == NULL) {
        *tree = new_node(key);
        return;
    }

    if (key < (*tree)->key) {
        insert(&(*tree)->left, key);
    } else {
        insert(&(*tree)->right, key);
    }
}

void print_tree(Node* tree, int depth) {
    if (tree == NULL) return;

    print_tree(tree->right, depth + 1);
    create_file(depth, 2 * (depth + 1) + 1);
    print_space(2 * depth + 1);
    printf("%d\n", tree->key);
    print_tree(tree->left, depth + 1);
}

int main() {
    srand(time(NULL));

    Node* tree = NULL;
    for (int i = 0; i < 15; i++) {
        int key = rand() % 50 + 1;
        insert(&tree, key);
    }

    printf("Binary Search Tree:\n");
    print_tree(tree, 0);

    for (int i = 0; i < 15; i++) {
        char filename[10];
        sprintf(filename, "tree%d.txt", i);
        int fd = open(filename, O_RDONLY);
        if (fd < 0) {
            perror("Error opening file");
            exit(1);
        }
        char buffer[256];
        read(fd, buffer, sizeof(buffer));
        printf("%s", buffer);
        close(fd);
        printf("\n");
    }

    return 0;
}