//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct tree {
  struct node* root;
};

void insert(struct tree* t, int data) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  if (t->root == NULL) {
    t->root = newNode;
  } else {
    insert(t, data);
  }
}

void search(struct tree* t, int data) {
  if (t->root != NULL) {
    struct node* current = t->root;

    while (current) {
      if (current->data == data) {
        printf("Found!\n");
        return;
      } else if (current->data < data) {
        current = current->right;
      } else {
        current = current->left;
      }
    }

    printf("Not found.\n");
  } else {
    printf("Tree is empty.\n");
  }
}

int main() {
  struct tree* t = malloc(sizeof(struct tree));
  t->root = NULL;

  insert(t, 20);
  insert(t, 10);
  insert(t, 30);
  insert(t, 40);
  insert(t, 50);

  search(t, 20);
  search(t, 30);
  search(t, 60);

  return 0;
}