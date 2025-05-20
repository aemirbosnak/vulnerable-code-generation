//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    char data;
    int freq;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char ch) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = ch;
    node->freq = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, char ch) {
    if (root == NULL)
        return newNode(ch);

    if (ch < root->data)
        root->left = insert(root->left, ch);
    else if (ch > root->data)
        root->right = insert(root->right, ch);
    else
        root->freq++;

    return root;
}

void printTree(struct Node* root, char prefix[]) {
    if (root == NULL)
        return;

    prefix[0] = '\0';
    strcat(prefix, root->data);

    printTree(root->left, prefix);

    printf("%s %d\n", prefix, root->freq);

    printTree(root->right, prefix);
}

void search(struct Node* root, char key[], int index, int freq) {
    if (root == NULL)
        return;

    if (strcmp(root->data, key) == 0) {
        printf("%s %d\n", key, freq);
        return;
    }

    if (index == strlen(key) - 1) {
        struct Node* temp = root;
        while (temp!= NULL) {
            if (temp->data == key[index]) {
                if (temp->freq > freq) {
                    printf("%s %d\n", key, temp->freq);
                }
                return;
            }
            temp = temp->right;
        }
    } else {
        search(root->left, key, index + 1, freq + root->freq);
        search(root->right, key, index + 1, freq + root->freq);
    }
}

int main() {
    struct Node* root = NULL;
    char key[MAX_SIZE];
    int freq = 0;

    printf("Enter the string to search: ");
    scanf("%s", key);

    root = insert(root, key[0]);
    for (int i = 1; i < strlen(key); i++) {
        root = insert(root, key[i]);
    }

    printf("Enter the minimum frequency: ");
    scanf("%d", &freq);

    search(root, key, 0, freq);

    return 0;
}