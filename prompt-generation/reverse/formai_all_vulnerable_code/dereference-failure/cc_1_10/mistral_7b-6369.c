//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} Node;

void addNode(Node **tree, char ch, int freq) {
    if (*tree == NULL) {
        *tree = (Node *)malloc(sizeof(Node));
        (*tree)->ch = ch;
        (*tree)->freq = freq;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    } else {
        if (freq < (*tree)->freq) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->ch = ch;
            newNode->freq = freq;
            newNode->left = *tree;
            *tree = newNode;
        } else {
            Node *current = *tree;
            Node *parent;

            while (current != NULL) {
                parent = current;

                if (freq < current->freq) {
                    Node *newNode = (Node *)malloc(sizeof(Node));
                    newNode->ch = ch;
                    newNode->freq = freq;

                    if (current->freq > freq) {
                        newNode->left = current;
                        current->right = newNode;
                    } else {
                        newNode->right = current;
                        current->left = newNode;
                    }

                    current = newNode;
                } else {
                    break;
                }
            }
        }
    }
}

Node *createLeaf(char ch, int freq) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int calculateFrequency(char str[], int length) {
    int freq[MAX_CHAR] = {0};

    for (int i = 0; i < length; i++) {
        freq[(int)str[i]]++;
    }

    return freq[*(unsigned char *)str];
}

void printCodes(Node *root, char codes[], int top) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("%c : %s\n", root->ch, codes);
    }

    printCodes(root->left, codes, top + 1);
    printCodes(root->right, codes, top + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage : %s <file>\n", argv[0]);
        exit(1);
    }

    int length = strlen(argv[1]);
    Node *root = NULL;

    for (int i = 0; i < length; i++) {
        addNode(&root, argv[1][i], calculateFrequency(&argv[1][i], length));
    }

    Node *first = root;
    Node *second = root;

    while (root->freq > 0) {
        if (first->freq <= second->freq) {
            first = second;
            second = root;
        }

        root = (Node *)malloc(sizeof(Node));
        root->left = first;
        root->right = second;

        first->freq = root->freq = 0;

        if (second->left == NULL) {
            second = first;
            first = root;
        }
    }

    char codes[256] = {0};
    printCodes(root, codes, 0);

    free(root);

    return 0;
}