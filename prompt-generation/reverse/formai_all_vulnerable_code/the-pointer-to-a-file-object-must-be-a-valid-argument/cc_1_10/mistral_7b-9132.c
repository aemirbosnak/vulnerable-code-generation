//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *left, *right;
} Node;

Node* newNode(char* str) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, str);
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, char* word) {
    if (root == NULL) {
        root = newNode(word);
    } else {
        int cmp = strcmp(word, root->word);
        if (cmp < 0) {
            root->left = insert(root->left, word);
        } else if (cmp > 0) {
            root->right = insert(root->right, word);
        }
    }
    return root;
}

int search(Node* root, char* word) {
    while (root != NULL) {
        int cmp = strcmp(word, root->word);
        if (cmp < 0) {
            root = root->left;
        } else if (cmp > 0) {
            root = root->right;
        } else {
            return 1;
        }
    }
    return 0;
}

void readDictionary(Node** root, char filename[]) {
    FILE* fp = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';
        *root = insert(*root, line);
    }
    fclose(fp);
}

int main() {
    Node* root = NULL;
    char word[MAX_WORD_LENGTH];

    readDictionary(&root, "dictionary.txt");

    while (1) {
        printf("Enter a word to check its spelling (or type 'exit' to quit): ");
        scanf("%s", word);

        if (strcmp(word, "exit") == 0) {
            break;
        }

        int is_valid = search(root, word);

        if (!is_valid) {
            printf("Error: '%s' is not a valid word.\n", word);
        }
    }

    return 0;
}