//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct file_node {
  char name[256];
  struct file_node* next;
  struct file_node* parent;
  int size;
  FILE* fp;
} file_node;

file_node* file_system_init() {
  file_node* root = malloc(sizeof(file_node));
  root->name[0] = '/';
  root->next = NULL;
  root->parent = NULL;
  root->size = 0;
  root->fp = NULL;

  return root;
}

void file_system_add_file(file_node* root, char* filename, int size) {
  file_node* new_file = malloc(sizeof(file_node));
  strcpy(new_file->name, filename);
  new_file->next = NULL;
  new_file->parent = root;
  new_file->size = size;
  new_file->fp = fopen(filename, "w");

  if (root->next == NULL) {
    root->next = new_file;
  } else {
    file_system_add_file(root->next, filename, size);
  }
}

void file_system_list_files(file_node* root) {
  for (file_node* file = root->next; file; file = file->next) {
    printf("%s\n", file->name);
  }
}

int main() {
  file_node* root = file_system_init();

  file_system_add_file(root, "test.txt", 10);
  file_system_add_file(root, "another.txt", 20);

  file_system_list_files(root);

  return 0;
}