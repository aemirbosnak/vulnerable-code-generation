//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    int arr[] = {10, 2, 9, 15, 3, 7, 12, 5, 1, 17};
    Node* root = NULL;
    int i;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        root = insert(root, arr[i]);

    printf("Inorder traversal of binary search tree is : ");
    inOrder(root);

    // Cryptic part starts here

    FILE *fp;
    char fileName[] = "data.bin";
    int size = sizeof(Node);
    int fileSize;

    if ((fp = fopen(fileName, "wb")) == NULL) {
        printf("\nUnable to create file %s", fileName);
        exit(1);
    }

    fwrite(root, size, 1, fp);
    fseek(fp, 0, SEEK_SET);

    Node* temp = NULL;
    while (1) {
        temp = (Node*) malloc(sizeof(Node));
        fread(temp, size, 1, fp);
        if (feof(fp)) break;
        temp->left = NULL;
        temp->right = NULL;
        Node** curr = &root;
        while (*curr != NULL) {
            if ((*curr)->data > temp->data) curr = &((*curr)->left);
            else curr = &((*curr)->right);
        }
        *curr = temp;
    }

    inOrder(root);
    printf("\nBinary search tree restored from file is : ");

    fclose(fp);
    return 0;
}