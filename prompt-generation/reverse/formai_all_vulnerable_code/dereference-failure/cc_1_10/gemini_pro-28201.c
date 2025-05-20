//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Stack data structure
typedef struct stack {
  node_t *top;
  int size;
} stack_t;

// Queue data structure
typedef struct queue {
  node_t *front, *rear;
  int size;
} queue_t;

// Binary tree node structure
typedef struct btree {
  int data;
  struct btree *left, *right;
} btree_t;

// Hash table data structure
typedef struct hash {
  int size;
  node_t **table;
} hash_t;

// Post-apocalyptic theme functions
void print_wasteland(int size) {
  for (int i = 0; i < size; i++) {
    printf("#");
  }
  printf("\n");
}

void print_ruin(char *name) {
  printf("\n===[%s]===\n", name);
}

// Data structure operations
void stack_push(stack_t *stack, int data) {
  // Create new node
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  // Push node onto stack
  if (stack->top == NULL) {
    stack->top = new_node;
  } else {
    new_node->next = stack->top;
    stack->top = new_node;
  }

  stack->size++;
}

int stack_pop(stack_t *stack) {
  if (stack->top == NULL) {
    return -1;  // Underflow
  }

  int data = stack->top->data;
  node_t *temp = stack->top;

  // Pop node from stack
  stack->top = stack->top->next;
  free(temp);

  stack->size--;
  return data;
}

void queue_enqueue(queue_t *queue, int data) {
  // Create new node
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  // Enqueue node onto queue
  if (queue->rear == NULL) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }

  queue->size++;
}

int queue_dequeue(queue_t *queue) {
  if (queue->front == NULL) {
    return -1;  // Underflow
  }

  int data = queue->front->data;
  node_t *temp = queue->front;

  // Dequeue node from queue
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(temp);

  queue->size--;
  return data;
}

void btree_inorder(btree_t *tree) {
  if (tree != NULL) {
    btree_inorder(tree->left);
    printf("%d ", tree->data);
    btree_inorder(tree->right);
  }
}

int hash_insert(hash_t *hash, int key, int data) {
  // Create new node
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  // Calculate hash index
  int index = key % hash->size;

  // Insert node into hash table
  if (hash->table[index] == NULL) {
    hash->table[index] = new_node;
  } else {
    node_t *temp = hash->table[index];
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }

  return 0;
}

void hash_print(hash_t *hash) {
  for (int i = 0; i < hash->size; i++) {
    node_t *temp = hash->table[i];
    printf("[%d]: ", i);
    while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

// Main function
int main() {
  // Create data structures
  stack_t stack;
  queue_t queue;
  btree_t *tree = NULL;
  hash_t hash;

  // Initialize data structures
  stack.top = NULL;
  stack.size = 0;
  queue.front = queue.rear = NULL;
  queue.size = 0;
  hash.size = 100;
  hash.table = malloc(sizeof(node_t *) * hash.size);
  for (int i = 0; i < hash.size; i++) {
    hash.table[i] = NULL;
  }

  // Populate data structures
  stack_push(&stack, 1);
  stack_push(&stack, 2);
  stack_push(&stack, 3);

  queue_enqueue(&queue, 4);
  queue_enqueue(&queue, 5);
  queue_enqueue(&queue, 6);

  // Create binary tree
  tree = malloc(sizeof(btree_t));
  tree->data = 10;
  tree->left = malloc(sizeof(btree_t));
  tree->left->data = 5;
  tree->left->left = NULL;
  tree->left->right = NULL;
  tree->right = malloc(sizeof(btree_t));
  tree->right->data = 15;
  tree->right->left = NULL;
  tree->right->right = NULL;

  // Insert into hash table
  hash_insert(&hash, 1, 10);
  hash_insert(&hash, 2, 20);
  hash_insert(&hash, 3, 30);

  // Print data structures
  print_ruin("Stack");
  print_wasteland(10);
  while (stack.size > 0) {
    printf("[%d] ", stack_pop(&stack));
  }
  printf("\n");

  print_ruin("Queue");
  print_wasteland(10);
  while (queue.size > 0) {
    printf("[%d] ", queue_dequeue(&queue));
  }
  printf("\n");

  print_ruin("Binary Tree");
  print_wasteland(10);
  btree_inorder(tree);
  printf("\n");

  print_ruin("Hash Table");
  print_wasteland(10);
  hash_print(&hash);

  // Free memory
  free(stack.top);
  free(queue.front);
  free(tree);
  for (int i = 0; i < hash.size; i++) {
    node_t *temp = hash.table[i];
    while (temp != NULL) {
      node_t *next = temp->next;
      free(temp);
      temp = next;
    }
  }
  free(hash.table);

  return 0;
}