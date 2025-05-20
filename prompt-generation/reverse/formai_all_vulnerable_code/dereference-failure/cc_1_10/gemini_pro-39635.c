//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct node {
  char *name;
  long long size;
  struct node *children;
  struct node *next;
};

struct node *create_node(char *name, long long size) {
  struct node *node = malloc(sizeof(struct node));
  node->name = name;
  node->size = size;
  node->children = NULL;
  node->next = NULL;
  return node;
}

void insert_node(struct node **root, struct node *node) {
  if (*root == NULL) {
    *root = node;
  } else {
    struct node *current = *root;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }
}

void free_node(struct node *node) {
  free(node->name);
  free(node->children);
  free(node);
}

void free_tree(struct node *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->children);
  free_node(root);
}

void print_tree(struct node *root, int depth) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  printf("%s (%lld bytes)\n", root->name, root->size);
  print_tree(root->children, depth + 1);
}

long long get_size(char *path) {
  struct stat statbuf;
  if (stat(path, &statbuf) == -1) {
    return 0;
  }
  return statbuf.st_size;
}

void analyze_directory(char *path, struct node **root) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    return;
  }
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    char *fullpath = malloc(strlen(path) + strlen(entry->d_name) + 2);
    sprintf(fullpath, "%s/%s", path, entry->d_name);
    struct stat statbuf;
    if (stat(fullpath, &statbuf) == -1) {
      free(fullpath);
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) {
      struct node *child = create_node(entry->d_name, 0);
      insert_node(root, child);
      analyze_directory(fullpath, &child->children);
    } else {
      struct node *node = create_node(entry->d_name, statbuf.st_size);
      insert_node(root, node);
    }
    free(fullpath);
  }
  closedir(dir);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <path>\n", argv[0]);
    return 1;
  }
  struct node *root = NULL;
  analyze_directory(argv[1], &root);
  print_tree(root, 0);
  free_tree(root);
  return 0;
}