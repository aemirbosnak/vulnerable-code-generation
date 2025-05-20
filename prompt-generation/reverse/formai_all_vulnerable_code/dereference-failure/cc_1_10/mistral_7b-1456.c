//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int survival_skills;
    int water;
    int food;
    struct Node* left;
    struct Node* right;
} survivor_t;

survivor_t* new_survivor(const char* name, int skills) {
    survivor_t* new = (survivor_t*)malloc(sizeof(survivor_t));
    strcpy(new->name, name);
    new->survival_skills = skills;
    new->water = 100;
    new->food = 100;
    new->left = NULL;
    new->right = NULL;
    return new;
}

survivor_t* insert_survivor(survivor_t* root, const char* name, int skills) {
    if (root == NULL) {
        root = new_survivor(name, skills);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insert_survivor(root->left, name, skills);
    } else {
        root->right = insert_survivor(root->right, name, skills);
    }

    return root;
}

void print_survivor(survivor_t* survivor) {
    printf("%s, skills: %d, water: %d, food: %d\n", survivor->name, survivor->survival_skills, survivor->water, survivor->food);
}

void inorder_traversal(survivor_t* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        print_survivor(root);
        inorder_traversal(root->right);
    }
}

int main() {
    survivor_t* apocalypse_survivors = NULL;

    apocalypse_survivors = insert_survivor(apocalypse_survivors, "John Doe", 80);
    apocalypse_survivors = insert_survivor(apocalypse_survivors, "Jane Doe", 90);
    apocalypse_survivors = insert_survivor(apocalypse_survivors, "Bob Smith", 70);

    printf("Survivors in the post-apocalyptic world:\n");
    inorder_traversal(apocalypse_survivors);

    return 0;
}