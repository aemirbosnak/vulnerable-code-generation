//FormAI DATASET v1.0 Category: Binary search trees ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* createNewNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}

Node* addToTree(Node* root, int value){
    if(root == NULL){
        root = createNewNode(value);
    }
    else if(value <= root->data){
        root->leftChild = addToTree(root->leftChild, value);
    }
    else{
        root->rightChild = addToTree(root->rightChild, value);
    }
    return root;
}

int findMinimum(Node* root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return -1;
    }
    while(root->leftChild != NULL){
        root = root->leftChild;
    }
    return root->data;
}

int findMaximum(Node* root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return -1;
    }
    while(root->rightChild != NULL){
        root = root->rightChild;
    }
    return root->data;
}

Node* deleteNode(Node* root, int value){
    if(root == NULL){
        return root;
    }
    else if(value < root->data){
        root->leftChild = deleteNode(root->leftChild, value);
    }
    else if(value > root->data){
        root->rightChild = deleteNode(root->rightChild, value);
    }
    else{//Node to be deleted found
        //Case 1: Node has no child
        if(root->leftChild == NULL && root->rightChild == NULL){
            free(root);
            root = NULL;
        }
        //Case 2: Node has one child
        else if(root->leftChild == NULL){
            Node* temp = root;
            root = root->rightChild;
            free(temp);
        }
        else if(root->rightChild == NULL){
            Node* temp = root;
            root = root->leftChild;
            free(temp);
        }
        //Case 3: Node has two children
        else{
            int minValue = findMinimum(root->rightChild);
            root->data = minValue;
            root->rightChild = deleteNode(root->rightChild, minValue);
        }
    }
    return root;
}

void inOrderTraversal(Node* root){
    if(root != NULL){
        inOrderTraversal(root->leftChild);
        printf("%d ", root->data);
        inOrderTraversal(root->rightChild);
    }
}

void preOrderTraversal(Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(Node* root){
    if(root != NULL){
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ", root->data);
    }
}

int main(){
    Node* root = NULL;
    root = addToTree(root, 5);
    root = addToTree(root, 3);
    root = addToTree(root, 7);
    root = addToTree(root, 1);
    root = addToTree(root, 8);
    root = addToTree(root, 6);

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Minimum Value: %d\n", findMinimum(root));
    printf("Maximum Value: %d\n", findMaximum(root));

    printf("Deleting 6 from tree...\n");
    root = deleteNode(root, 6);

    printf("In-order Traversal after deleting 6: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Deleting 5 from tree...\n");
    root = deleteNode(root, 5);

    printf("In-order Traversal after deleting 5: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}