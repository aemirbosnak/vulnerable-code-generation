//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Node;

typedef struct BinaryTree {
    Node data;
    struct BinaryTree *left;
    struct BinaryTree *right;
} BinaryTree;

BinaryTree* newNode(char* key, char* value) {
    BinaryTree* newNode = (BinaryTree*) malloc(sizeof(BinaryTree));
    strcpy(newNode->data.key, key);
    strcpy(newNode->data.value, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void parseLine(char* line, BinaryTree** root) {
    char key[MAX_KEY_LENGTH], value[MAX_VALUE_LENGTH];
    sscanf(line, "%s = %s", key, value);

    if (*root == NULL) {
        *root = newNode(key, value);
    } else {
        parseLine(NULL, &((*root)->left));
        if (strcmp(key, "left") == 0) {
            parseLine(NULL, &((*root)->left));
        } else if (strcmp(key, "right") == 0) {
            parseLine(NULL, &((*root)->right));
        } else {
            parseLine(NULL, root);
        }
    }
}

void parseResume(FILE* resumeFile, BinaryTree** root) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, resumeFile) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        parseLine(line, root);
    }
}

void printNode(BinaryTree* node) {
    if (node != NULL) {
        printf("%s: %s\n", node->data.key, node->data.value);
        printNode(node->left);
        printNode(node->right);
    }
}

int main() {
    FILE* resumeFile = fopen("resume.txt", "r");
    if (resumeFile == NULL) {
        printf("Error opening resume file.\n");
        return 1;
    }

    BinaryTree* root = NULL;
    parseResume(resumeFile, &root);
    fclose(resumeFile);

    printNode(root);

    free(root);
    return 0;
}