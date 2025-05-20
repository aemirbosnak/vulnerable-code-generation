//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *value;
} attribute;

typedef struct node {
  char *data;
  struct node *parent;
  struct node *child;
  attribute *attributes;
} node;

void parse_attributes(char *line, node *current_node) {
  char *attr = strtok(line, " ");
  while (attr) {
    current_node->attributes = realloc(current_node->attributes, sizeof(attribute) * (strlen(line) - 1));
    int idx = strchr(attr, '=') - attr;
    current_node->attributes->name = strndup(attr, idx);
    current_node->attributes->value = strndup(attr + idx + 2, strlen(attr) - idx - 3);
    attr = strtok(line + idx, " ");
  }
}

node *build_tree(FILE *xml_file, node *parent_node) {
  char buffer[1000];
  node *current_node = NULL;

  while (fgets(buffer, 1000, xml_file)) {
    if (buffer[0] == '<' && buffer[1] == '/') {
      return parent_node;
    } else if (buffer[0]  == '<') {
      current_node = (node*) malloc(sizeof(node));
      current_node->data = NULL;
      current_node->parent = parent_node;
      current_node->child = NULL;
      current_node->attributes = NULL;

      int idx = strcspn(&buffer[1], " >\n");
      current_node->data = strndup(&buffer[1], idx);
      parse_attributes(&buffer[idx+1], current_node);

      if (parent_node) {
        node *child_node = build_tree(xml_file, current_node);
        child_node->parent = current_node;
        current_node->child = child_node;
      }
    } else {
      if (current_node->data == NULL) {
        current_node->data = strdup(buffer);
      } else {
        current_node->data = realloc(current_node->data, strlen(current_node->data) + strlen(buffer) + 1);
        strcat(current_node->data, buffer);
      }
    }
  }

  return NULL;
}

void print_node(node *current_node, int depth) {
  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
  printf("<%s", current_node->data);
  attribute *attr = current_node->attributes;
  while (attr && attr->name != NULL) {
    printf(" %s=\"%s\"", attr->name, attr->value);
    attr++;
  }
  printf(">\n");

  node *child_node = current_node->child; 
  while (child_node) { 
    print_node(child_node, depth + 1); 
    child_node = child_node->child; 
  } 

  if (current_node->data && current_node->data[0] != '/') {
    for (int i = 0; i < depth; i++) {
      printf(" ");
    }
    printf("</%s>\n", current_node->data);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <xml_file>\n", argv[0]);
    return 1;
  }

  FILE *xml_file = fopen(argv[1], "r");
  if (!xml_file) {
    printf("Unable to open XML file.\n");
    return 1;
  }

  node *root_node = build_tree(xml_file, NULL);
  fclose(xml_file);

  print_node(root_node, 0);

  return 0;
}