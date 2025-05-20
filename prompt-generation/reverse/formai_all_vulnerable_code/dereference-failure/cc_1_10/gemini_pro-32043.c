//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
  char word[MAX_WORD_LENGTH];
  struct node *left;
  struct node *right;
} node;

node *root = NULL;

void insert(char *word) {
  node *new_node = malloc(sizeof(node));
  strcpy(new_node->word, word);
  new_node->left = NULL;
  new_node->right = NULL;

  if (root == NULL) {
    root = new_node;
  } else {
    node *current_node = root;
    while (1) {
      int comparison = strcmp(word, current_node->word);
      if (comparison == 0) {
        return;
      } else if (comparison < 0) {
        if (current_node->left == NULL) {
          current_node->left = new_node;
          return;
        } else {
          current_node = current_node->left;
        }
      } else {
        if (current_node->right == NULL) {
          current_node->right = new_node;
          return;
        } else {
          current_node = current_node->right;
        }
      }
    }
  }
}

int search(char *word) {
  node *current_node = root;
  while (current_node != NULL) {
    int comparison = strcmp(word, current_node->word);
    if (comparison == 0) {
      return 1;
    } else if (comparison < 0) {
      current_node = current_node->left;
    } else {
      current_node = current_node->right;
    }
  }
  return 0;
}

int main() {
  FILE *dictionary = fopen("dictionary.txt", "r");
  if (dictionary == NULL) {
    printf("Error opening dictionary file.\n");
    return 1;
  }

  char word[MAX_WORD_LENGTH];
  while (fscanf(dictionary, "%s", word) != EOF) {
    insert(word);
  }

  fclose(dictionary);

  while (1) {
    printf("Enter a word to check: ");
    scanf("%s", word);

    if (strcmp(word, "quit") == 0) {
      break;
    }

    if (search(word)) {
      printf("%s is a valid word.\n", word);
    } else {
      printf("%s is not a valid word.\n", word);
    }
  }

  return 0;
}