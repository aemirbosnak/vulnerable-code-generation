//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

void getFrequency(char input[], int length, int frequencies[]) {
    for (int i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            int index = input[i] - 'a';
            frequencies[index]++;
        }
    }
}

Node* createNode(char ch, int freq) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void encode(Node* root, char codes[], int top) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        codes[top] = root->ch;
        printf("%c: %s\n", root->ch, codes);
        return;
    }

    encode(root->left, codes, top + 1);
    encode(root->right, codes, top + 1);
}

int main() {
    char input[100];
    printf("Enter the text to encode: ");
    scanf("%s", input);

    int length = strlen(input);
    int frequencies[26];

    getFrequency(input, length, frequencies);

    Node *root = NULL;

    for (int i = 0; i < 26; i++) {
        if (frequencies[i] > 0) {
            Node* newNode = createNode('a' + i, frequencies[i]);
            if (root == NULL) {
                root = newNode;
            } else {
                Node* current = root;
                while (current != NULL) {
                    if (current->freq > newNode->freq) {
                        if (current->left == NULL) {
                            current->left = newNode;
                            break;
                        } else {
                            current = current->left;
                        }
                    } else {
                        if (current->right == NULL) {
                            current->right = newNode;
                            break;
                        } else {
                            current = current->right;
                        }
                    }
                }
            }
        }
    }

    char codes[100];
    encode(root, codes, 0);

    printf("The encoded text is: ");
    for (int i = 0; input[i] != '\0'; i++) {
        char code;
        if (isalpha(input[i])) {
            code = codes[input[i] - 'a'];
            printf("%c", code);
        } else {
            printf("%c", input[i]);
        }
    }
    printf("\n");

    return 0;
}