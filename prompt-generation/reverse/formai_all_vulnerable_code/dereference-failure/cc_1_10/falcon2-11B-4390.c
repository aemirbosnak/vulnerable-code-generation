//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define MAX_LEAF 256

// Structure for the Huffman Tree
struct Node {
    int frequency;
    char symbol;
    struct Node *left;
    struct Node *right;
};

struct Node *buildHuffmanTree(char *data, int size) {
    struct Node *root = NULL;
    struct Node *newNode;

    for (int i = 0; i < size; i++) {
        int frequency = data[i];
        char symbol = data[i];

        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->frequency = frequency;
        newNode->symbol = symbol;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL) {
            root = newNode;
        } else {
            struct Node *current = root;
            struct Node *prev;

            while (1) {
                if (current->frequency > newNode->frequency) {
                    prev->right = newNode;
                    prev = current;
                    current = newNode;
                } else {
                    prev->left = newNode;
                    prev = current;
                    current = newNode;
                }

                if (current->frequency == newNode->frequency) {
                    if (strcmp(current->symbol, newNode->symbol) > 0) {
                        prev->right = newNode;
                        prev = current;
                        current = newNode;
                    } else {
                        prev->left = newNode;
                        prev = current;
                        current = newNode;
                    }
                }

                if (current->right == NULL && current->left == NULL) {
                    break;
                }
            }
        }
    }

    return root;
}

struct Node *printHuffmanTree(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("(%d) %c\n", root->frequency, root->symbol);
        return NULL;
    }

    printf("(%d) %c", root->frequency, root->symbol);
    printHuffmanTree(root->left);
    printHuffmanTree(root->right);
    return NULL;
}

void compressData(char *data, int size, struct Node *root) {
    int i;
    char buffer[MAX_SIZE];

    for (i = 0; i < size; i++) {
        if (root->symbol == data[i]) {
            sprintf(buffer, "%d", root->frequency);
            for (int j = strlen(buffer) - 1; j >= 0; j--) {
                printf("%c", buffer[j]);
            }
        } else {
            sprintf(buffer, "%c", data[i]);
            printf("%c", data[i]);
        }
    }
}

int main() {
    char data[] = "abracadabra";
    int size = sizeof(data) - 1;

    struct Node *root = buildHuffmanTree(data, size);
    printHuffmanTree(root);
    printf("\n");

    compressData(data, size, root);
    return 0;
}