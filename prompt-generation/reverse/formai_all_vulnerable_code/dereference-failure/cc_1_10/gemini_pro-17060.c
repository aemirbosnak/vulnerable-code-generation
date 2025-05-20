//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

typedef struct file_node {
  char name[MAX_PATH_LENGTH];
  int is_directory;
  struct file_node *parent;
  struct file_node *children;
} file_node;

file_node *create_file_node(char *name, int is_directory, file_node *parent) {
  file_node *node = malloc(sizeof(file_node));
  strcpy(node->name, name);
  node->is_directory = is_directory;
  node->parent = parent;
  node->children = NULL;
  return node;
}

void print_file_node(file_node *node, int depth) {
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  printf("%s\n", node->name);
  if (node->is_directory) {
    file_node *child = node->children;
    while (child) {
      print_file_node(child, depth + 1);
      child = child->children;
    }
  }
}

int main() {
  // Create the root directory
  file_node *root = create_file_node("/", 1, NULL);

  // Create some subdirectories
  file_node *bin = create_file_node("bin", 1, root);
  file_node *home = create_file_node("home", 1, root);
  file_node *usr = create_file_node("usr", 1, root);

  // Create some files in the subdirectories
  file_node *bash = create_file_node("bash", 0, bin);
  file_node *ls = create_file_node("ls", 0, bin);
  file_node *user1 = create_file_node("user1", 1, home);
  file_node *user2 = create_file_node("user2", 1, home);
  file_node *xorg = create_file_node("xorg", 0, usr);

  // Print the file system
  print_file_node(root, 0);

  return 0;
}