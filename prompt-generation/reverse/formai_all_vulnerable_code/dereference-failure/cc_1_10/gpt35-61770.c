//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
typedef struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}Node; 
  
Node* newNode(int data) 
{ 
    Node* node;
    node = (Node*) malloc(sizeof(Node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
}

void traverseInOrder(Node *node)
{
    if(node->left!=NULL)
    {
        traverseInOrder(node->left);
    }
    
    printf("%d ", node->data);
    
    if(node->right!=NULL)
    {
        traverseInOrder(node->right);
    }
}

void traversePreOrder(Node* node)
{
    printf("%d ", node->data);
     
    if(node->left!=NULL)
    {
        traversePreOrder(node->left);
    }
    
    if(node->right!=NULL)
    {
        traversePreOrder(node->right);
    }
}

void traversePostOrder(Node* node)
{
    if(node->left!=NULL)
    {
        traversePostOrder(node->left);
    }
    
    if(node->right!=NULL)
    {
        traversePostOrder(node->right);
    }
    
    printf("%d ", node->data);
}

void asyncTraverse(Node *node)
{
    int c1 = fork();
    int c2;
    if (c1 == 0)
    {
        traverseInOrder(node);
        exit(0);
    } 
    else
    {
        c2 = fork();
        if (c2 == 0)
        {
            traversePreOrder(node);
            exit(0);
        } 
        else
        {
            traversePostOrder(node);
            waitpid(c1, NULL, 0);
        }
    }
}

int main() 
{ 
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
 
    printf("-----In Order traversal-----\n");
    traverseInOrder(root);
    
    printf("\n-----Pre Order traversal-----\n");
    traversePreOrder(root);
    
    printf("\n-----Post Order traversal-----\n");
    traversePostOrder(root);
    
    printf("\n-----Asynchronous traversal-----\n");
    asyncTraverse(root);
    
    return 0; 
}