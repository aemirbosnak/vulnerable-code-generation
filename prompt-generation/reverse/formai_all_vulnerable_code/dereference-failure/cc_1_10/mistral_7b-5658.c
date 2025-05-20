//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct Node {
    char name[50];
    int age;
    float weight;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(const char* name, int age, float weight) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->weight = weight;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, Node* new_node) {
    if (root == NULL) {
        return new_node;
    }

    if (strcmp(new_node->name, root->name) < 0) {
        root->left = insert(root->left, new_node);
    } else if (strcmp(new_node->name, root->name) > 0) {
        root->right = insert(root->right, new_node);
    } else {
        printf("Name already exists in the tree.\n");
        free(new_node);
    }

    return root;
}

void print_tree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("-%s-\n", root->name);
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    srand(time(NULL));

    int num_nodes = 10;
    Node* root = NULL;

    for (int i = 0; i < num_nodes; i++) {
        int random_age = rand() % 100;
        float random_weight = (float) rand() / RAND_MAX;
        char random_name[50];
        sprintf(random_name, "Surrealist %d", i);

        Node* new_node = create_node(random_name, random_age, random_weight);
        root = insert(root, new_node);
    }

    printf("Surrealist Binary Search Tree:\n");
    print_tree(root, 0);

    return 0;
}