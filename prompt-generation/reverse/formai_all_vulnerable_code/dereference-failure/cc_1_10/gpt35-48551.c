//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_KEYS 10 // Maximum number of keys
#define MAX_VALUES 20 // Maximum number of values for each key
#define MAX_LEN 101 // Maximum length of a string

struct index {
    char key[MAX_LEN];
    int value[MAX_VALUES];
    int num_values;
};

struct node {
    struct index idx;
    struct node* left;
    struct node* right;
};

struct node* create_node(struct index idx) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->idx = idx;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* root, struct index idx) {
    if (!root) {
        return create_node(idx);
    }
    
    if (strcmp(idx.key, root->idx.key) < 0) {
        root->left = insert(root->left, idx);
    }
    else if (strcmp(idx.key, root->idx.key) > 0) {
        root->right = insert(root->right, idx);
    }
    else {
        if (root->idx.num_values < MAX_VALUES) {
            root->idx.value[root->idx.num_values++] = idx.value[0];
        }
        else {
            printf("Error: maximum number of values reached for key %s\n", idx.key);
        }
    }
    return root;
}

void search(struct node* root, char* key) {
    if (!root) {
        printf("Key not found\n");
        return;
    }
    
    if (strcmp(key, root->idx.key) < 0) {
        search(root->left, key);
    }
    else if (strcmp(key, root->idx.key) > 0) {
        search(root->right, key);
    }
    else {
        printf("Values for key %s:\n", root->idx.key);
        for (int i = 0; i < root->idx.num_values; i++) {
            printf("%d ", root->idx.value[i]);
        }
        printf("\n");
    }
}

int main() {
    struct node* root = NULL;
    
    struct index idx_array[MAX_KEYS] = {
        {"apple", {1}, 1},
        {"banana", {2, 3}, 2},
        {"orange", {4, 5, 6}, 3},
        {"pear", {7, 8, 9, 10}, 4},
        {"grape", {11, 12, 13, 14, 15}, 5}
    };
    
    for (int i = 0; i < MAX_KEYS; i++) {
        root = insert(root, idx_array[i]);
    }
    
    search(root, "orange");
    search(root, "peach");
    
    return 0;
}