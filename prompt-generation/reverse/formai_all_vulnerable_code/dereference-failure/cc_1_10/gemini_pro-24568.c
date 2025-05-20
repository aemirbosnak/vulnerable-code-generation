//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct node {
  char word[MAX_WORD_LENGTH];
  struct node *left;
  struct node *right;
} node;

node *root = NULL;

void insert(char *word) {
  node *new_node = (node *)malloc(sizeof(node));
  strcpy(new_node->word, word);
  new_node->left = NULL;
  new_node->right = NULL;

  if (root == NULL) {
    root = new_node;
  } else {
    node *current = root;
    while (1) {
      int comparison = strcmp(word, current->word);
      if (comparison == 0) {
        return;
      } else if (comparison < 0) {
        if (current->left == NULL) {
          current->left = new_node;
          return;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == NULL) {
          current->right = new_node;
          return;
        } else {
          current = current->right;
        }
      }
    }
  }
}

int search(char *word) {
  node *current = root;
  while (current != NULL) {
    int comparison = strcmp(word, current->word);
    if (comparison == 0) {
      return 1;
    } else if (comparison < 0) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return 0;
}

void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    insert(word);
  }

  fclose(file);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s dictionary.txt\n", argv[0]);
    exit(1);
  }

  load_dictionary(argv[1]);

  while (1) {
    printf("Enter a word to check (or q to quit): ");
    char word[MAX_WORD_LENGTH];
    scanf("%s", word);

    if (strcmp(word, "q") == 0) {
      break;
    }

    int found = search(word);
    if (found) {
      printf("%s is a valid word\n", word);
    } else {
      printf("%s is not a valid word\n", word);
    }
  }

  return 0;
}