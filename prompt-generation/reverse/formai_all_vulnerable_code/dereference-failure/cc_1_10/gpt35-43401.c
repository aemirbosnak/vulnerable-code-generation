//FormAI DATASET v1.0 Category: Binary search trees ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert_node(struct node* root, int value){
    if(root==NULL){
        root = create_node(value);
        return root;
    }
    else if(value < root->data){
        root->left = insert_node(root->left,value);
    }
    else{
        root->right = insert_node(root->right,value);
    }
    return root;
}

struct node* search_node(struct node* root, int value){
    if(root==NULL || root->data==value){
        return root;
    }
    else if(value < root->data){
        return search_node(root->left,value);
    }
    else{
        return search_node(root->right,value);
    }
}

void preorder_traversal(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main(){
    struct node* root = NULL;
    int option, value;
    do{
        printf("\n *** Welcome to Binary Search Tree Program *** \n");
        printf("Choose an option:\n1.Insert a node\n2.Search for a node\n3.Preorder Traversal\n4.Exit\nOption: ");
        scanf("%d",&option);
        switch(option){
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&value);
                    root = insert_node(root,value);
                    printf("\nNode with value %d has been inserted successfully!\n",value);
                    break;
            case 2: printf("Enter the value to be searched: ");
                    scanf("%d",&value);
                    if(search_node(root,value)!=NULL){
                        printf("\nNode with value %d is present in the BST!\n",value);
                    }
                    else{
                        printf("\nNode with value %d is not present in the BST!\n",value);
                    }
                    break;
            case 3: printf("\nThe Preorder Traversal of the BST is: ");
                    preorder_traversal(root);
                    printf("\n");
                    break;
            case 4: printf("\nThank you for using Binary Search Tree Program!\n");
                    break;
            default: printf("\nInvalid option! Please choose a valid option.\n");
                     break;
        }
    }while(option != 4);

    return 0;
}