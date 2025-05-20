//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *name;
  struct node *parent;
  struct node *next;
  struct node *child;
} node;

node *root;

void ls(node *dir) {
  node *p;
  for (p = dir->child; p != NULL; p = p->next) {
    printf("%s ", p->name);
  }
}

void cd(node *dir) {
  root = dir;
}

void mkdir(char *name) {
  node *new = malloc(sizeof(node));
  new->name = name;
  new->parent = root;
  new->next = root->child;
  root->child = new;
}

int main() {
  root = malloc(sizeof(node));
  root->name = "/";
  root->parent = NULL;
  root->next = NULL;
  root->child = NULL;

  mkdir("bin");
  mkdir("dev");
  mkdir("etc");
  mkdir("home");
  mkdir("lib");
  mkdir("media");
  mkdir("mnt");
  mkdir("opt");
  mkdir("proc");
  mkdir("root");
  mkdir("sbin");
  mkdir("srv");
  mkdir("tmp");
  mkdir("usr");
  mkdir("var");

  cd(root);
  ls(root);

  return 0;
}