//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} TNode;

TNode *create_node(char *word) {
    TNode *new_node = (TNode *)malloc(sizeof(TNode));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TNode *insert(TNode *root, char *word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert(root->right, word);
    } else {
        root->left = insert(root->left, word);
    }

    return root;
}

void print_tree(TNode *root, int space) {
    if (root == NULL) {
        return;
    }

    print_tree(root->right, space + 4);

    for (int i = 0; i < space; i++) {
        printf(" ");
    }

    printf("%s (%d)\n", root->word, root->count);

    print_tree(root->left, space + 4);
}

int main() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    TNode *root = NULL;
    char word[MAX_SIZE];

    while (fscanf(file, "%s", word)!= EOF) {
        root = insert(root, word);
    }

    fclose(file);

    print_tree(root, 0);

    return 0;
}