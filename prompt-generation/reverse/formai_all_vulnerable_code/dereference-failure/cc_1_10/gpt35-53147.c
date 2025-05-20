//FormAI DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct Node* insert(struct Node* node, int data){
    if(node == NULL){
        return(newNode(data));
    }
    else{
        if(data <= node->data){
            node->left = insert(node->left, data);
        }
        else if(data > node->data){
            node->right = insert(node->right, data);
        }
        return node;
    }
}
  
void printInorder(struct Node* node){
    if(node == NULL){
        return;
    } 
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int search(struct Node* node, int data){
    if(node == NULL){
        return 0;
    }
    if(node->data == data){
        return 1;
    }
    if(node->data < data){
        return search(node->right, data);
    }
    else{
        return search(node->left, data);
    }
}

int main(){
    struct Node* root = NULL;
    int choice=0, data=0;
    while(1){
        printf("\nMenu:\n1. Insert\n2. Search\n3. Display\n4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("\n%d is inserted\n", data);
                break;
            case 2:
                printf("Enter the element you want to search: ");
                scanf("%d", &data);
                if(search(root, data)) {
                    printf("%d is present in the tree\n", data);
                }
                else{
                    printf("%d is not present in the tree\n", data);
                }
                break;
            case 3:
                printf("Inorder traversal of Binary search tree is: ");
                printInorder(root);
                printf("\n");
                break;
            case 4:
                printf("Thanks for playing, Puzzle Solved!\n");
                exit(0);
            default:
                printf("Please enter a valid choice!\n");
                break;
        }
    }
    return 0;
}