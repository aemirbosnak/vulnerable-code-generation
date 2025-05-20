//FormAI DATASET v1.0 Category: File system simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char name[50];
  int isDir;
  int size;
  struct node *next;
  struct node *child;
};

void printFileSystem(struct node *root, int depth) {
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < depth; i++) {
    printf("\t");
  }

  if (root->isDir) {
    printf("[dir] %s\n", root->name);
    printFileSystem(root->child, depth+1);
  } else {
    printf("[file] %s (%d bytes)\n", root->name, root->size);
  }

  printFileSystem(root->next, depth);
}

int main() {
  struct node *root = calloc(1, sizeof(struct node));
  strcpy(root->name, "/");
  root->isDir = 1;

  struct node *dir1 = calloc(1, sizeof(struct node));
  strcpy(dir1->name, "Documents");
  dir1->isDir = 1;

  struct node *dir2 = calloc(1, sizeof(struct node));
  strcpy(dir2->name, "Downloads");
  dir2->isDir = 1;

  struct node *file1 = calloc(1, sizeof(struct node));
  strcpy(file1->name, "resume.pdf");
  file1->isDir = 0;
  file1->size = 1024;

  struct node *file2 = calloc(1, sizeof(struct node));
  strcpy(file2->name, "report.docx");
  file2->isDir = 0;
  file2->size = 2048;

  root->child = dir1;
  dir1->next = dir2;
  dir2->next = file1;
  file1->next = file2;

  printFileSystem(root, 0);

  return 0;
}