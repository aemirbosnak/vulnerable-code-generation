//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(char *word, int count) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    node->word = strdup(word);
    node->count = count;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert_word(Node *root, char *word, int count) {
    if (root == NULL) {
        return create_node(word, count);
    }
    if (strcmp(root->word, word) == 0) {
        root->count += count;
        return root;
    }
    if (strcmp(word, root->word) < 0) {
        root->left = insert_word(root->left, word, count);
    } else {
        root->right = insert_word(root->right, word, count);
    }
    return root;
}

void print_tree(Node *root, int space) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, space + 4);
    printf("%*s [%d]\n", space, root->word, root->count);
    print_tree(root->left, space + 4);
}

void delete_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    free(root->word);
    free(root);
}

int main() {
    char word[MAX_LEN];
    int count;
    Node *root = NULL;

    printf("Enter words (type 'done' to finish):\n");
    while (fgets(word, MAX_LEN, stdin)!= NULL) {
        if (strcmp(word, "done") == 0) {
            break;
        }
        count = atoi(strtok(word, " "));
        root = insert_word(root, word, count);
    }

    printf("Words and their counts:\n");
    print_tree(root, 0);

    delete_tree(root);

    return 0;
}