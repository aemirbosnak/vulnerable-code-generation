//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include<stdio.h>  

struct node{  
    int data;  
    struct node *rightChild;  
    struct node *leftChild;  
};  

struct node *root = NULL;  

void insert(int data) {  
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));  
    struct node *current;  
    struct node *parent;  

    tempNode->data = data;  
    tempNode->leftChild = NULL;  
    tempNode->rightChild = NULL;  

    if(root == NULL) {  
        root = tempNode;  
    } else {  
        current = root;  
        parent = NULL;  

        while(1) {  
            parent = current;  

            if(data < parent->data) {  
                current = current->leftChild;  
                if(current == NULL) {  
                    parent->leftChild = tempNode;  
                    return;  
                }  
            } else {  
                current = current->rightChild;  

                if(current == NULL) {  
                    parent->rightChild = tempNode;  
                    return;  
                }  
            }  
        }  
    }  
}  

struct node* search(int data) {  
    struct node *current = root;  
    printf("Visiting elements: ");  

    while(current->data != data) {  

        if(current != NULL)  
            printf("%d ",current->data);  

        if(current->data > data) {  
            current = current->leftChild;  
        } else {  
            current = current->rightChild;  
        }  

        if(current == NULL) {  
            return NULL;  
        }  
    }  
    return current;  
}  

void preorder(struct node *root) {  
    if(root != NULL) {  
        printf("%d ",root->data);  
        preorder(root->leftChild);  
        preorder(root->rightChild);  
    }  
}  

void inorder(struct node *root) {  
    if(root != NULL) {  
        inorder(root->leftChild);  
        printf("%d ",root->data);  
        inorder(root->rightChild);  
    }  
}  

void postorder(struct node *root) {  
    if(root != NULL) {  
        postorder(root->leftChild);  
        postorder(root->rightChild);  
        printf("%d ", root->data);  
    }  
}  

int main() {  
    int i;  
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };  

    for(i = 0; i < 7; i++)  
        insert(array[i]);  

    printf("\nInorder traversal: ");  
    inorder(root);  

    printf("\nPreorder traversal: ");  
    preorder(root);  

    printf("\nPost order traversal: ");  
    postorder(root);  

    struct node *temp = search(31);  

    if(temp != NULL) {  
        printf("\nElement with value %d found", temp->data);  
    } else {  
        printf("\nElement not found in the tree");  
    }  

    return 0;  
}