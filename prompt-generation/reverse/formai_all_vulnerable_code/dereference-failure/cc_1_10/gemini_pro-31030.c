//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct node {
  char *name;
  struct node *left;
  struct node *right;
} node;

node *tree = NULL;

void insert(char *name) {
  node *new_node = malloc(sizeof(node));
  new_node->name = strdup(name);
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree == NULL) {
    tree = new_node;
    return;
  }

  node *current = tree;
  while (1) {
    int cmp = strcmp(name, current->name);
    if (cmp == 0) {
      free(new_node);
      return;
    } else if (cmp < 0) {
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

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }

  print_tree(root->left);
  printf("%s\n", root->name);
  print_tree(root->right);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    fprintf(stderr, "Error: could not open directory '%s'\n", argv[1]);
    return EXIT_FAILURE;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_DIR) {
      continue;
    }

    char *name = entry->d_name;
    struct stat statbuf;
    if (stat(name, &statbuf) == -1) {
      fprintf(stderr, "Error: could not stat file '%s'\n", name);
      continue;
    }

    insert(name);
  }

  closedir(dir);

  print_tree(tree);

  return EXIT_SUCCESS;
}