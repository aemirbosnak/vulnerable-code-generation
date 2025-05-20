//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

struct node {
  char *name;
  struct node *next;
};

struct tree {
  struct node *root;
};

void add_node(struct tree *t, char *name) {
  struct node *n = malloc(sizeof(struct node));
  n->name = malloc(strlen(name) + 1);
  strcpy(n->name, name);
  n->next = NULL;
  if (t->root == NULL) {
    t->root = n;
  } else {
    struct node *p = t->root;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = n;
  }
}

void print_tree(struct tree *t, int level) {
  struct node *p = t->root;
  while (p != NULL) {
    for (int i = 0; i < level; i++) {
      printf("  ");
    }
    printf("%s\n", p->name);
    print_tree(&p->next, level + 1);
    p = p->next;
  }
}

void free_tree(struct tree *t) {
  struct node *p = t->root;
  while (p != NULL) {
    struct node *n = p->next;
    free(p->name);
    free(p);
    p = n;
  }
}

int main() {
  struct tree t;
  t.root = NULL;
  struct dirent *dp;
  DIR *dirp = opendir(".");
  while ((dp = readdir(dirp)) != NULL) {
    if (dp->d_type == DT_DIR) {
      add_node(&t, dp->d_name);
    }
  }
  closedir(dirp);
  print_tree(&t, 0);
  free_tree(&t);
  return 0;
}