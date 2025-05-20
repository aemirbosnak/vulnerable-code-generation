//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Node *left, *right;
} Node;

void init_node(Node *node) {
    node->left = node->right = NULL;
}

Node *create_node(const char *name, int age) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->age = age;
    init_node(new_node);
    return new_node;
}

void display_node(const Node *node) {
    int i;

    printf("%s (%d): ", node->name, node->age);
    for (i = strlen(node->name); i < 30; i++) {
        printf(" ");
    }

    if (node->left != NULL) {
        printf("|");
        for (i = 15 - strlen(node->name); i > 0; i--) {
            printf(" ");
        }
        printf("/");
        display_node(node->left);
    }

    if (node->right != NULL) {
        printf("\\");
        for (i = 15 - strlen(node->name); i > 0; i--) {
            printf(" ");
        }
        display_node(node->right);
    }
}

int main() {
    Node *father = create_node("John Doe", 50);
    Node *mother = create_node("Jane Doe", 45);
    Node *son = create_node("Mike Doe", 20);
    Node *daughter = create_node("Emily Doe", 15);

    father->left = mother;
    father->right = son;
    mother->left = NULL;
    mother->right = daughter;
    son->left = NULL;
    son->right = NULL;
    daughter->left = NULL;
    daughter->right = NULL;

    printf("Family Tree:\n");
    display_node(father);

    free(father);
    free(mother);
    free(son);
    free(daughter);

    return 0;
}