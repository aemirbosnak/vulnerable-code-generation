//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *word;
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char *word, int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->word = strdup(word);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insertNode(struct Node *root, char *word, int value) {
    if (root == NULL) {
        return createNode(word, value);
    }

    if (strcmp(word, root->word) < 0) {
        root->left = insertNode(root->left, word, value);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insertNode(root->right, word, value);
    }

    return root;
}

int searchNode(struct Node *root, char *word) {
    if (root == NULL) {
        return 0;
    }

    if (strcmp(word, root->word) == 0) {
        return root->value;
    }

    if (strcmp(word, root->word) < 0) {
        return searchNode(root->left, word);
    } else {
        return searchNode(root->right, word);
    }
}

struct Node *getRoot(struct Node *node) {
    if (node->left == NULL) {
        return node;
    }

    return getRoot(node->left);
}

void deleteNode(struct Node *root) {
    if (root == NULL) {
        return;
    }

    deleteNode(root->left);
    deleteNode(root->right);
    free(root->word);
    free(root);
}

int analyzeSentiment(struct Node *root, char *text) {
    if (root == NULL || text == NULL) {
        return 0;
    }

    char *word = strtok(text, " ");
    int value = 0;

    while (word != NULL) {
        value += searchNode(root, word);
        word = strtok(NULL, " ");
    }

    return value;
}

void printNode(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printNode(root->left);
    printf("%s: %d\n", root->word, root->value);
    printNode(root->right);
}

struct Node *createTree() {
    struct Node *root = NULL;

    root = insertNode(root, "bad", -1);
    root = insertNode(root, "good", 1);
    root = insertNode(root, "great", 2);
    root = insertNode(root, "terrible", -2);
    root = insertNode(root, "excellent", 3);

    return root;
}

int main() {
    struct Node *tree = createTree();
    char text[] = "The movie was really good and the acting was excellent!";

    int sentiment = analyzeSentiment(tree, text);
    printf("The sentiment of the text is: %d\n", sentiment);

    printNode(getRoot(tree));
    deleteNode(tree);

    return 0;
}