//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *left;
   struct node *right;
} Node;

Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

Node* insert(Node* node, int data) {
   if (node == NULL) return createNode(data);
   if (data < node->data) node->left = insert(node->left, data);
   else node->right = insert(node->right, data);
   return node;
}

Node* search(Node* node, int data) {
   if (node == NULL || node->data == data) return node;
   if (node->data < data) return search(node->right, data);
   return search(node->left, data);
}

Node* findMinimum(Node* node) {
   Node* current = node;
   while (current->left != NULL)
      current = current->left;
   return current;
}

Node* delete(Node* node, int data) {
   if (node == NULL) return node;
   if (data < node->data) node->left = delete(node->left, data);
   else if (data > node->data) node->right = delete(node->right, data);
   else {
      if (node->left == NULL) {
         Node* temp = node->right;
         free(node);
         return temp;
      }
      else if (node->right == NULL) {
         Node* temp = node->left;
         free(node);
         return temp;
      }
      Node* temp = findMinimum(node->right);
      node->data = temp->data;
      node->right = delete(node->right, temp->data);
   }
   return node;
}

void inorder(Node* node) {
   if (node != NULL) {
      inorder(node->left);
      printf("%d ", node->data);
      inorder(node->right);
   }
}

int main() {
   Node* root = NULL;
   int choice, item;
   while (1) {
      printf("\n1. Insert element");
      printf("\n2. Delete element");
      printf("\n3. Search element");
      printf("\n4. Display elements in inorder");
      printf("\n5. Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("\nEnter an element: ");
            scanf("%d", &item);
            root = insert(root, item);
            break;
         case 2:
            printf("\nEnter an element to delete: ");
            scanf("%d", &item);
            root = delete(root, item);
            break;
         case 3:
            printf("\nEnter an element to search: ");
            scanf("%d", &item);
            if (search(root, item) == NULL)
               printf("\nElement not found");
            else
               printf("\nElement found");
            break;         
         case 4:
            printf("\nElements in inorder: ");
            inorder(root);
            break;
         case 5:
            exit(0);
         default:
            printf("\nInvalid choice!");
      }
   }
   return 0;
}