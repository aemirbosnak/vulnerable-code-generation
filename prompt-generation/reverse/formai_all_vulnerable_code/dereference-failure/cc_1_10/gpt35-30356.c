//FormAI DATASET v1.0 Category: Binary search trees ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};

struct node* new_node(int data) {
   struct node* node = (struct node*)malloc(sizeof(struct node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return(node);
}

void inorder(struct node* node) {
   if(node == NULL)
      return;
   inorder(node->left);
   printf("%d -> ", node->data);
   inorder(node->right);
}

void preorder(struct node* node) {
   if(node == NULL)
      return;
   printf("%d -> ", node->data);
   preorder(node->left);  
   preorder(node->right);
}

void postorder(struct node* node) {
   if(node == NULL)
      return;
   postorder(node->left);  
   postorder(node->right);
   printf("%d -> ", node->data);
}

struct node* insert(struct node* node, int data) {
   if(node == NULL) {
      return(new_node(data));
   } else {
      if(data <= node->data)
         node->left = insert(node->left, data);
      else
         node->right = insert(node->right, data);
      return(node);
   }
}

struct node* search(struct node* node, int data) {
    if(node == NULL || node->data == data) {           
        return node;
    }else if(node->data < data) {                  
        return search(node->right, data);
    }else {                                                
        return search(node->left, data); 
    }
}

void main() {
   struct node *root = NULL;
   root = insert(root, 10);
   insert(root, 20);
   insert(root, 30);
   insert(root, 40);
   insert(root, 50);
   insert(root, 60);

   printf("\nIn-order traversal:\n");
   inorder(root);

   printf("\nPre-order traversal:\n");
   preorder(root);

   printf("\nPost-order traversal:\n");
   postorder(root);

   int search_key = 20;
   if(search(root, search_key) != NULL) {
        printf("\n%d is present in the binary search tree!\n", search_key);
   }else {
        printf("\n%d is not present in the binary search tree!\n", search_key);
   }
}