//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    else if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

Node* findMin(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int data){
    if(root == NULL)
        return root;
    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int search(Node* root, int data){
    if(root == NULL)
        return 0;
    else if(root->data == data)
        return 1;
    else if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main(){
    Node* root = NULL;
    int option, data;

    while(1){
        printf("\nChoose one option below:");
        printf("\n1. Insert element in the Binary Search Tree");
        printf("\n2. Delete element from the Binary Search Tree");
        printf("\n3. Search element in the Binary Search Tree");
        printf("\n4. Print the elements of the Binary Search Tree(inorder traversal)");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("\nEnter element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("\nEnter element to search: ");
                scanf("%d", &data);
                if(search(root, data))
                    printf("\nElement found in the Binary Search Tree");
                else
                    printf("\nElement not found in the Binary Search Tree");
                break;
            case 4:
                printf("\nElements of Binary Search Tree: ");
                inorder(root);
                break;
            case 5:
                printf("\nExiting....");
                exit(0);
            default:
                printf("\nEnter a valid option!");
        }
    }
    return 0;
}