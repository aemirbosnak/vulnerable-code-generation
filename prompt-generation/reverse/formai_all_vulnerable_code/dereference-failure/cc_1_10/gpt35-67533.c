//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 100

typedef struct node {
  char name[256];
  int size;
  struct node *children;
  int num_children;
} Node;

/* function declarations */
Node* create_node(char name[], int size);
void display_tree(Node* root, int depth);
void free_tree(Node* root);

/* main function */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char command[512];
  sprintf(command, "du -d 1 %s", argv[1]);

  FILE *fp = popen(command, "r");
  if (fp == NULL) {
    printf("Error: could not execute command\n");
    exit(EXIT_FAILURE);
  }

  Node *root = create_node(argv[1], 0);
  Node *current_node = root;

  char line[512];
  while (fgets(line, sizeof(line), fp) != NULL) {
    strtok(line, "\n"); // remove newline character

    char *token = strtok(line, "\t");
    int size = strtol(token, NULL, 10);
    token = strtok(NULL, "\t");

    char *path = token + strlen(argv[1]); // trim directory prefix
    if (strcmp(path, "") == 0) {
      continue; // skip directory itself
    }

    if (path[0] == '/') {
      path++; // remove leading slash
    }

    while (current_node != root) {
      if (strncmp(path, current_node->name, strlen(current_node->name)) == 0 &&
          (path[strlen(current_node->name)] == '\0' || path[strlen(current_node->name)] == '/')) {
        break; // found parent node
      } else {
        current_node = current_node->children + current_node->num_children - 1;
      }
    }

    if (current_node == root) {
      current_node = create_node(strtok(path, "/"), 0);
    } else {
      path += strlen(current_node->name);
      if (path[0] == '/') {
        path++; // remove leading slash (again)
      }

      while (path[0] != '\0') {
        char *token = strtok(path, "/");
        current_node->num_children++;
        current_node->children = (Node*) realloc(current_node->children, current_node->num_children * sizeof(Node));
        current_node = current_node->children + current_node->num_children - 1;
        current_node = create_node(token, 0);
        path += strlen(token) + 1;
      }
    }

    current_node->size += size;
    current_node = root;
  }

  pclose(fp);

  display_tree(root, 0);

  free_tree(root);

  return EXIT_SUCCESS;
}

/* function definitions */
Node* create_node(char name[], int size) {
  Node *node = (Node*) malloc(sizeof(Node));
  strncpy(node->name, name, sizeof(node->name) - 1);
  node->size = size;
  node->children = NULL;
  node->num_children = 0;
  return node;
}

void display_tree(Node *root, int depth) {
  int i;

  for (i = 0; i < depth; i++) { printf("  "); }
  printf("%s: %d KB\n", root->name, root->size);

  for (i = 0; i < root->num_children; i++) {
    display_tree(root->children + i, depth + 1);
  }
}

void free_tree(Node *root) {
  int i;
  for (i = 0; i < root->num_children; i++) {
    free_tree(root->children + i);
  }
  free(root->children);
  free(root);
}