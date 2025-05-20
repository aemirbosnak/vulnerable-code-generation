//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <memory.h>
#include <stdbool.h>

struct Node {
    char *word;
    int count;
    struct Node *next;
};

struct Tree {
    struct Node *root;
};

struct Tree *createTree() {
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    tree->root = NULL;
    return tree;
}

struct Node *createNode(char *word) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->word = strdup(word);
    node->count = 0;
    node->next = NULL;
    return node;
}

void insertNode(struct Tree *tree, char *word) {
    struct Node *node = createNode(word);
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }
    struct Node *curr = tree->root;
    while (curr->next != NULL && strcmp(curr->word, word) != 0) {
        curr = curr->next;
    }
    if (strcmp(curr->word, word) == 0) {
        curr->count++;
    } else {
        curr->next = node;
    }
}

void printTree(struct Tree *tree) {
    if (tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct Node *curr = tree->root;
    while (curr != NULL) {
        printf("%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    }
}

void freeTree(struct Tree *tree) {
    if (tree->root == NULL) {
        return;
    }
    struct Node *curr = tree->root;
    while (curr != NULL) {
        struct Node *next = curr->next;
        free(curr->word);
        free(curr);
        curr = next;
    }
    free(tree);
}

int main() {
    struct Tree *tree = createTree();
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    for (int i = 0; i < 9; i++) {
        insertNode(tree, words[i]);
    }
    printTree(tree);
    freeTree(tree);
    return 0;
}