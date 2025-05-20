//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct xml_element {
  char name[MAX_SIZE];
  char value[MAX_SIZE];
};

struct xml_node {
  struct xml_element element;
  struct xml_node* next;
};

void print_node(struct xml_node* node) {
  printf("<%s>%s</%s>\n", node->element.name, node->element.value, node->element.name);
}

void print_tree(struct xml_node* node, int depth) {
  if (node == NULL) {
    return;
  }
  for (int i = 0; i < depth; i++) {
    printf("\t");
  }
  print_node(node);
  print_tree(node->next, depth + 1);
}

int main() {
  struct xml_node* root = NULL;
  struct xml_node* current_node = NULL;
  char str[MAX_SIZE];
  FILE* fp = fopen("example.xml", "r");

  while (fgets(str, MAX_SIZE, fp)) {
    if (str[0] == '<') { // start tag
      struct xml_node* new_node = malloc(sizeof(struct xml_node));
      char* value = strchr(str, '>') + 1;
      int len = strlen(value) - strlen("</>") - 1;
      strncpy(new_node->element.value, value, len);
      new_node->element.value[len] = '\0';
      if (root == NULL) {
        root = new_node;
        current_node = root;
      }
      else {
        current_node->next = new_node;
        current_node = new_node;
      }
    }
    else if (str[0] == '<' && str[1] == '/') { // end tag
      // do nothing
    }
    else { // element name
      char* value = strchr(str, '<') + 1;
      int len = strlen(value) - strlen(">\n");
      strncpy(current_node->element.name, value, len);
      current_node->element.name[len] = '\0';
    }
  }

  fclose(fp);

  print_tree(root, 0);

  return 0;
}