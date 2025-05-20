//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Donald Knuth
// Disk space analyzer in the style of Donald Knuth.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

// A node in the directory tree.
typedef struct node {
  char *name;
  struct node *parent;
  struct node *children;
  struct node *next;
  int size;
} node;

// Create a new node.
node *new_node(char *name, node *parent) {
  node *n = malloc(sizeof(node));
  n->name = strdup(name);
  n->parent = parent;
  n->children = NULL;
  n->next = NULL;
  n->size = 0;
  return n;
}

// Add a node to the directory tree.
void add_node(node *tree, node *n) {
  if (tree->children == NULL) {
    tree->children = n;
  } else {
    node *child = tree->children;
    while (child->next != NULL) {
      child = child->next;
    }
    child->next = n;
  }
}

// Compute the size of a node.
void compute_size(node *n) {
  if (n->children == NULL) {
    struct stat st;
    stat(n->name, &st);
    n->size = st.st_size;
  } else {
    node *child = n->children;
    while (child != NULL) {
      compute_size(child);
      n->size += child->size;
      child = child->next;
    }
  }
}

// Print the directory tree.
void print_tree(node *tree) {
  node *n = tree->children;
  while (n != NULL) {
    printf("%s (%d bytes)\n", n->name, n->size);
    print_tree(n);
    n = n->next;
  }
}

// Free the directory tree.
void free_tree(node *tree) {
  if (tree->children != NULL) {
    node *child = tree->children;
    while (child != NULL) {
      free_tree(child);
      child = child->next;
    }
  }
  free(tree->name);
  free(tree);
}

// Main function.
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return 1;
  }

  // Create the root node.
  node *tree = new_node("/", NULL);

  // Add the files in the specified directory to the tree.
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "%s/%s", argv[1], entry->d_name);

    node *n = new_node(path, tree);
    add_node(tree, n);
  }

  closedir(dir);

  // Compute the size of the directory tree.
  compute_size(tree);

  // Print the directory tree.
  print_tree(tree);

  // Free the directory tree.
  free_tree(tree);

  return 0;
}