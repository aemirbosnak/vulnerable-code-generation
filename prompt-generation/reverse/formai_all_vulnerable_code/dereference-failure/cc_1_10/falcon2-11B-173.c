//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(Node* root) {
    if (root!= NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    int numNodes = rand() % 1000 + 1;

    for (int i = 0; i < numNodes; i++) {
        int data = rand() % 100;
        Node* newNode = createNode(data);
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            while (current!= NULL) {
                if (data <= current->data) {
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

    inOrderTraversal(root);
    printf("\n");
    return 0;
}