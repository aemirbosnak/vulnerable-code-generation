//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DEPTH 100
#define MAX_LENGTH 1000

struct node {
    char word[MAX_LENGTH];
    int depth;
    struct node *left, *right;
};

struct node *new_node(char *word, int depth) {
    struct node *n = malloc(sizeof(struct node));
    strcpy(n->word, word);
    n->depth = depth;
    n->left = n->right = NULL;
    return n;
}

void print_node(struct node *n) {
    printf("%s %d\n", n->word, n->depth);
    if (n->left != NULL) print_node(n->left);
    if (n->right != NULL) print_node(n->right);
}

void insert_word(struct node **root, char *word) {
    struct node *n = *root;
    if (n == NULL) {
        *root = new_node(word, 1);
        return;
    }
    if (strcmp(word, n->word) < 0) {
        insert_word(&n->left, word);
    } else {
        insert_word(&n->right, word);
    }
}

void find_word(struct node **root, char *word) {
    struct node *n = *root;
    while (n != NULL) {
        if (strcmp(word, n->word) == 0) {
            printf("%s %d\n", n->word, n->depth);
            return;
        }
        n = n->left != NULL ? n->left : n->right;
    }
    printf("Not found\n");
}

int main() {
    struct node *root = NULL;
    char word[MAX_LENGTH];
    int i, depth = 1;

    // Insert words
    for (i = 0; i < 10; i++) {
        printf("Insert word: ");
        fgets(word, MAX_LENGTH, stdin);
        insert_word(&root, word);
    }

    // Find words
    for (i = 0; i < 10; i++) {
        printf("Find word: ");
        fgets(word, MAX_LENGTH, stdin);
        find_word(&root, word);
    }

    return 0;
}