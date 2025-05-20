//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char *key;
  int value;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct BankingRecord {
  char *name;
  char *accountNumber;
  int balance;
} BankingRecord;

Node *insert(Node *root, BankingRecord *record) {
  if (root == NULL) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = record->accountNumber;
    new_node->value = record->balance;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  } else {
    int compare_result = strcmp(record->accountNumber, root->key);
    if (compare_result < 0) {
      root->left = insert(root->left, record);
    } else if (compare_result > 0) {
      root->right = insert(root->right, record);
    } else {
      root->value = record->balance;
    }
    return root;
  }
}

Node *search(Node *root, char *accountNumber) {
  if (root == NULL) {
    return NULL;
  } else {
    int compare_result = strcmp(accountNumber, root->key);
    if (compare_result < 0) {
      return search(root->left, accountNumber);
    } else if (compare_result > 0) {
      return search(root->right, accountNumber);
    } else {
      return root;
    }
  }
}

void print_tree(Node *root) {
  if (root == NULL) {
    return;
  } else {
    printf("(%s, %d)\n", root->key, root->value);
    print_tree(root->left);
    print_tree(root->right);
  }
}

int main() {
  Node *root = NULL;

  BankingRecord record1 = {"John Doe", "1234567890", 1000};
  root = insert(root, &record1);

  BankingRecord record2 = {"Jane Smith", "0987654321", 2000};
  root = insert(root, &record2);

  BankingRecord record3 = {"Bill Jones", "1122334455", 3000};
  root = insert(root, &record3);

  print_tree(root);

  Node *found_node = search(root, "1234567890");
  if (found_node != NULL) {
    printf("Found record: (%s, %d)\n", found_node->key, found_node->value);
  } else {
    printf("Record not found.\n");
  }

  return 0;
}