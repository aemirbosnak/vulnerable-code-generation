//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#define MAX_SIZE 100

struct Stack {
   int items[MAX_SIZE];
   int top;
};

typedef struct TreeNode {
   char* data;
   struct TreeNode* left;
   struct TreeNode* right;
} TreeNode;

void initialize(struct Stack* stack) {
   stack->top = -1;
}

int isFull(struct Stack* stack) {
   return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
   return stack->top == -1;
}

void push(struct Stack* stack, int value) {
   if (isFull(stack)) {
       printf("Stack is full");
   } else {
      stack->top++;
      stack->items[stack->top] = value;
   }
}

int pop(struct Stack* stack) {
   if (isEmpty(stack)) {
      printf("Stack is empty");
      return -1;
   } else {
      int value = stack->items[stack->top];
      stack->top--;
      return value;
   }
}

void inorderTraversal(TreeNode* root, struct Stack* stack) {
   if (root == NULL) return;
   inorderTraversal(root->left, stack);
   push(stack, atoi(root->data));
   inorderTraversal(root->right, stack);
}

TreeNode* newNode(char* data) {
   TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return node;
}

TreeNode* insert(TreeNode* root, char* data) {
   if (root == NULL) {
      root = newNode(data);
      return root;
   }
   if (atoi(data) < atoi(root->data)) {
      root->left = insert(root->left, data);
   } else {
      root->right = insert(root->right, data);
   }
   return root;
}

void visualizeTree(TreeNode* root) {
   struct Stack s;
   initialize(&s);
   inorderTraversal(root, &s);
   printf("\n\nTree Visualization: \n\n");
   while (!isEmpty(&s))
   {
      int item = pop(&s);
      for (int i = 0; i < item; i++)
      {
         printf(" ");
      }
      printf("*\n");
   }
}

int main() {
   TreeNode* root = NULL;
   root = insert(root, "3");
   insert(root, "1");
   insert(root, "7");
   insert(root, "5");
   insert(root, "9");
   visualizeTree(root);
   return 0;
}