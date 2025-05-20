//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

Node *createNode(char data, int freq) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void encode(Node *root, char *code, int length) {
    if (root == NULL)
        return;

    if (!root->left && !root->right) {
        code[length] = '\0';
        printf("%c : %s\n", root->data, code);
    }

    encode(root->left, code, length + 1);
    encode(root->right, code, length + 1);
}

int getFrequency(char input[], int length) {
    int frequency = 0;
    for (int i = 0; i < length; i++)
        frequency += (isalpha(input[i]) ? 1 : 0);
    return frequency;
}

int main() {
    char input[100];
    printf("Enter the input string : ");
    scanf("%s", input);

    int length = strlen(input);
    int *freq = (int *)calloc(MAX_CHAR, sizeof(int));

    for (int i = 0; i < length; i++)
        freq[(int)input[i]]++;

    Node **queue = (Node **)calloc(MAX_CHAR, sizeof(Node *));

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            Node *newNode = createNode((char)i, freq[i]);
            queue[i] = newNode;
        }
    }

    while (queue[0] && queue[MAX_CHAR / 2]) {
        Node *leftNode = queue[0];
        Node *rightNode = queue[MAX_CHAR / 2];

        int sum = leftNode->freq + rightNode->freq;
        Node *newNode = createNode('\0', sum);

        newNode->left = leftNode;
        newNode->right = rightNode;

        int i = 0;
        while (queue[i] != NULL)
            i++;
        queue[i] = newNode;

        leftNode = rightNode;
        rightNode = newNode;

        free(leftNode);
        free(rightNode);
    }

    Node *root = queue[0];
    char code[256] = {0};
    encode(root, code, 0);

    free(queue);
    free(freq);

    return 0;
}