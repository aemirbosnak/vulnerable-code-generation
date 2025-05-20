//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, char* nodes, Node** nodesQueue, int height) {
    int i, j, k;
    int endLen = branchLen + 1;
    if (startLen == -1) {
        startLen = endLen = branchLen;
    }
    for (i = 0; i < nodesInThisLevel; i++) {
        printf("%*s", (int)((startLen + endLen) / 2), "");
        printf(nodes[i] ? "%c" : " ", nodes[i]);
        printf("%*s", (int)((nodeSpaceLen + branchLen - endLen) / 2), "");
    }
    printf("\n");
    if (height <= 1) {
        return;
    }
    for (i = 0; i < nodesInThisLevel; i++) {
        for (j = 0; j < 2; j++) {
            if (j == 0 && nodes[i]) {
                nodesQueue[i]->left = (Node*)malloc(sizeof(Node));
                nodesQueue[i]->left->data = rand() % 100;
                nodesQueue[i]->left->left = NULL;
                nodesQueue[i]->left->right = NULL;
                nodesQueue[i + nodesInThisLevel] = nodesQueue[i]->left;
                printf("%*s%c%*s", (int)(startLen / 2), "", '/', (int)(endLen / 2), "");
            }
            else if (j == 1 && nodes[i]) {
                nodesQueue[i]->right = (Node*)malloc(sizeof(Node));
                nodesQueue[i]->right->data = rand() % 100;
                nodesQueue[i]->right->left = NULL;
                nodesQueue[i]->right->right = NULL;
                nodesQueue[i + nodesInThisLevel] = nodesQueue[i]->right;
                printf("%*s%c%*s", (int)(endLen / 2), "", '\\', (int)(startLen / 2), "");
            }
            else {
                nodesQueue[i + nodesInThisLevel] = NULL;
                printf("%*s", branchLen, "");
            }
        }
        printf("%*s", nodeSpaceLen, "");
    }
    printf("\n");
    for (i = 0; i < nodesInThisLevel; i++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodes + i * 2, nodesQueue, height - 1);
    }
}

void printTree(Node* root) {
    char nodes[MAX_HEIGHT][MAX_HEIGHT * 2];
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_HEIGHT * 2; j++) {
            nodes[i][j] = ' ';
        }
    }
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    Node* nodesQueue[MAX_HEIGHT];
    for (int i = 0; i < MAX_HEIGHT; i++) {
        nodesQueue[i] = NULL;
    }
    nodesQueue[0] = root;
    int branchLen = 2;
    int nodeSpaceLen = 2;
    int startLen = -1;
    int nodesInThisLevel = 1;
    while (nodesInThisLevel > 0) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodes[0], nodesQueue, getHeight(root));
        for (int i = 0; i < nodesInThisLevel; i++) {
            Node* currentNode = nodesQueue[i];
            if (currentNode == NULL) {
                nodes[2][i * 2] = ' ';
                nodes[2][i * 2 + 1] = ' ';
                continue;
            }
            char buffer[10];
            sprintf(buffer, "%2d", currentNode->data);
            int dataLen = strlen(buffer);
            nodes[2][i * 2] = buffer[0];
            nodes[2][i * 2 + 1] = dataLen >= 2 ? buffer[1] : ' ';
        }
        for (int i = 0; i < nodesInThisLevel; i++) {
            Node* currentNode = nodesQueue[i];
            if (currentNode == NULL) {
                nodesQueue[i * 2] = NULL;
                nodesQueue[i * 2 + 1] = NULL;
                continue;
            }
            nodesQueue[i * 2] = currentNode->left;
            nodesQueue[i * 2 + 1] = currentNode->right;
        }
        nodesInThisLevel *= 2;
        branchLen = ((branchLen + 1) / 2) - 1;
        nodeSpaceLen = branchLen + 1;
        startLen = nodesInThisLevel == 1 ? 0 : ((startLen + branchLen + 1) / 2) - 1;
    }
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = rand() % 100;
    root->left = NULL;
    root->right = NULL;
    printTree(root);
    return 0;
}