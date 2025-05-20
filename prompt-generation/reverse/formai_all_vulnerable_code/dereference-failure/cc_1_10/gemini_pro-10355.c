//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
  char *name;
  char *value;
  struct node *next;
} node;

typedef struct {
  node *root;
  int size;
} tree;

tree *create_tree() {
  tree *t = malloc(sizeof(tree));
  t->root = NULL;
  t->size = 0;
  return t;
}

void free_tree(tree *t) {
  node *curr = t->root;
  while (curr != NULL) {
    node *next = curr->next;
    free(curr->name);
    free(curr->value);
    free(curr);
    curr = next;
  }
  free(t);
}

node *create_node(char *name, char *value) {
  node *n = malloc(sizeof(node));
  n->name = strdup(name);
  n->value = strdup(value);
  n->next = NULL;
  return n;
}

void add_node(tree *t, char *name, char *value) {
  node *n = create_node(name, value);
  if (t->root == NULL) {
    t->root = n;
    t->size++;
    return;
  }
  node *curr = t->root;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = n;
  t->size++;
}

void print_tree(tree *t) {
  node *curr = t->root;
  while (curr != NULL) {
    printf("%s: %s\n", curr->name, curr->value);
    curr = curr->next;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <xml_file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: could not open file %s\n", argv[1]);
    return 1;
  }

  char buf[MAX_SIZE];
  tree *t = create_tree();

  while (fgets(buf, MAX_SIZE, fp) != NULL) {
    char *start = strchr(buf, '<');
    if (start == NULL) {
      continue;
    }
    char *end = strchr(start, '>');
    if (end == NULL) {
      continue;
    }
    *end = '\0';
    char *name = start + 1;
    char *value = end + 1;
    add_node(t, name, value);
  }

  fclose(fp);
  print_tree(t);
  free_tree(t);
  return 0;
}