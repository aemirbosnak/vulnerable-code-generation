//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *root = NULL;
pthread_mutex_t lock;

void insert(int data) {
  pthread_mutex_lock(&lock);
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  if (root == NULL) {
    root = new_node;
  } else {
    node *current = root;
    node *parent = NULL;

    while (current != NULL) {
      parent = current;
      if (data < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    if (data < parent->data) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  }
  pthread_mutex_unlock(&lock);
}

void *search(void *arg) {
  int data = *(int *)arg;

  pthread_mutex_lock(&lock);
  node *current = root;

  while (current != NULL) {
    if (data == current->data) {
      printf("Found %d in the tree.\n", data);
      break;
    } else if (data < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  if (current == NULL) {
    printf("Could not find %d in the tree.\n", data);
  }
  pthread_mutex_unlock(&lock);

  return NULL;
}

int main() {
  pthread_t threads[10];
  int data[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < 10; i++) {
    insert(data[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, search, &data[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&lock);

  return 0;
}