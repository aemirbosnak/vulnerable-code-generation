//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
   struct Node *left, *right;
   int data;
} Node;

Node *createNode(int data) 
{
   Node *newNode = malloc(sizeof(Node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;

   return newNode;
}

Node *insertNode(Node *currNode, int data) 
{
   if (currNode == NULL)
      return createNode(data);

   if (data < currNode->data)
      currNode->left = insertNode(currNode->left, data);
   else if (data > currNode->data)
      currNode->right = insertNode(currNode->right, data);

   return currNode;
}

Node *searchNode(Node *currNode, int data) 
{
   if (currNode == NULL || currNode->data == data)
      return currNode;

   if (data < currNode->data)
      return searchNode(currNode->left, data);
   else
      return searchNode(currNode->right, data);
}

void inorderTraversal(Node *currNode) 
{
   if (currNode == NULL)
      return;

   inorderTraversal(currNode->left);
   printf("%d ", currNode->data);
   inorderTraversal(currNode->right);
}

int main() 
{
   Node *root = NULL;
   int choice, data;

   printf("\n*** Binary Search Tree ***\n\n");
   printf("1. Insert Node\n");
   printf("2. Search Node\n");
   printf("3. Inorder Traversal\n");
   printf("4. Exit\n");
   printf("\nEnter your choice (1-4): ");

   do 
   {
      scanf("%d", &choice);

      switch (choice) 
      {
         case 1: printf("Enter data to insert: ");
                 scanf("%d", &data);
                 root = insertNode(root, data);
                 break;

         case 2: printf("Enter data to search: ");
                 scanf("%d", &data);
                 if (searchNode(root, data) != NULL)
                    printf("%d found in the tree.\n", data);
                 else
                    printf("%d not found in the tree.\n", data);
                 break;

         case 3: inorderTraversal(root);
                 printf("\n");
                 break;

         case 4: printf("Exiting...\n");
                 break;

         default: printf("Invalid Choice. Try Again.\n");
                  break;
      }

      printf("\nEnter your choice (1-4): ");
   } while (choice != 4);

   return 0;
}