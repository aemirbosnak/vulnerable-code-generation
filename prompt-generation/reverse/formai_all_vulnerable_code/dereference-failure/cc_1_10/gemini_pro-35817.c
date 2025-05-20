//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stddef.h>
#include <stdlib.h>
#define NODESIZE sizeof(struct node)

struct node {
  char *value;
  struct node *left;
  struct node *right;
};

struct node *make_node(char *v, struct node *l, struct node *r) {
  struct node *n = malloc(NODESIZE);
  n->value = v;
  n->left = l;
  n->right = r;
  return n;
}

struct node *insert(struct node *t, char *v) {
  if (!t) return make_node(v, 0, 0);
  if (strcmp(t->value, v) > 0)
    t->left = insert(t->left, v);
  else
    t->right = insert(t->right, v);
  return t;
}

void walk(struct node *t) {
  if (!t) return;
  walk(t->left);
  printf("%s\n", t->value);
  walk(t->right);
}

void walk_free(struct node *t) {
  if (!t) return;
  walk_free(t->left);
  walk_free(t->right);
  free(t->value);
  free(t);
}

struct node *find(struct node *t, char *v) {
  while (t) {
    if (strcmp(t->value, v) == 0) return t;
    if (strcmp(t->value, v) > 0)
      t = t->left;
    else
      t = t->right;
  }
  return 0;
}

int main() {
  struct node *tree = 0;
  tree = insert(tree, "foo");
  tree = insert(tree, "bar");
  tree = insert(tree, "baz");
  walk(tree);
  struct node *f = find(tree, "foo");
  if (f) printf("found %s\n", f->value);
  walk_free(tree);
}