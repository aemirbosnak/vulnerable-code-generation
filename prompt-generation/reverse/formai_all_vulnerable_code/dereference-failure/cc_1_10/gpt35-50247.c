//FormAI DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

struct node *rootNode = NULL;

void insertNode(int data) {
   struct node *tempNode = NULL;
   struct node *currentNode = NULL;
   struct node *parentNode = NULL;

   tempNode = (struct node*)malloc(sizeof(struct node));
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   if(rootNode == NULL) {
      rootNode = tempNode;
   } else {
      currentNode = rootNode;
      parentNode = NULL;

      while(1) {
         parentNode = currentNode;

         if(data < parentNode->data) {
            currentNode = currentNode->leftChild;

            if(currentNode == NULL) {
               parentNode->leftChild = tempNode;
               return;
            }
         } else {
            currentNode = currentNode->rightChild;

            if(currentNode == NULL) {
               parentNode->rightChild = tempNode;
               return;
            }
         }
      }
   }
}

void search(int data) {
   struct node *currentNode = rootNode;
   printf("Visiting elements: ");

   while(currentNode != NULL) {
      printf("%d ",currentNode->data);

      if(currentNode->data == data) {
         printf("\n");
         return;
      }

      if(currentNode->data > data) {
         currentNode = currentNode->leftChild;
      } else {
         currentNode = currentNode->rightChild;
      }
   }

   printf("\n");
}

void inorderTraversal(struct node *currentNode) {
   if(currentNode != NULL) {
      inorderTraversal(currentNode->leftChild);
      printf("%d ",currentNode->data);
      inorderTraversal(currentNode->rightChild);
   }
}

void preorderTraversal(struct node *currentNode) {
   if(currentNode != NULL) {
      printf("%d ",currentNode->data);
      preorderTraversal(currentNode->leftChild);
      preorderTraversal(currentNode->rightChild);
   }
}

void postorderTraversal(struct node *currentNode) {
   if(currentNode != NULL) {
      postorderTraversal(currentNode->leftChild);
      postorderTraversal(currentNode->rightChild);
      printf("%d ", currentNode->data);
   }
}

int main() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(i = 0; i < 7; i++)
      insertNode(array[i]);

   printf("\nInorder traversal: ");
   inorderTraversal(rootNode);

   printf("\nPreorder traversal: ");
   preorderTraversal(rootNode);

   printf("\nPostorder traversal: ");
   postorderTraversal(rootNode);

   printf("\n");

   search(31);
   search(15);

   return 0;
}