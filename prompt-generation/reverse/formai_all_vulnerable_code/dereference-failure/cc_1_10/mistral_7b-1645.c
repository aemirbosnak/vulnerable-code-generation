//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct Node {
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

void createNode(Node** tree, char ch, int freq) {
    *tree = (Node*)malloc(sizeof(Node));
    (*tree)->ch = ch;
    (*tree)->freq = freq;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        if (lHeight > rHeight)
            return(lHeight + 1);
        else return(rHeight + 1);
    }
}

void printCodes(Node* root, char code[], int codeLength) {
    if (root == NULL)
        return;

    if (root->freq > 0) {
        printf("%c : %s\n", root->ch, code);
        root->freq--;

        printCodes(root->left, code, codeLength + 1);
        printCodes(root->right, code, codeLength + 1);
    }
}

int main() {
    Node* root = NULL;
    char ch;
    int freq;
    char codes[MAX_CHAR][11];

    printf("Enter the number of characters you want to encode: ");
    int num_chars;
    scanf("%d", &num_chars);

    printf("Enter the characters and their corresponding frequencies:\n");
    for (int i = 1; i <= num_chars; i++) {
        scanf(" %c %d", &ch, &freq);
        createNode(&root, ch, freq);
    }

    Node* current = root;
    while (current != NULL) {
        if (current->left == NULL && current->right == NULL) {
            int index = current->ch - '0';
            strcpy(codes[index], "");
            strcat(codes[index], &current->ch);
            break;
        }
        current = (current->freq > current->left->freq) ? current->left : current->right;
    }

    printf("\nHuffman Codes:\n");
    printCodes(root, "", 0);

    return 0;
}