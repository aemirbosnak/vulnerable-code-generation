//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct xml_node {
  char *name;
  char *value;
  struct xml_node *parent;
  struct xml_node *children;
  struct xml_node *next;
} xml_node;

xml_node *xml_parse(char *xml) {
  xml_node *root = malloc(sizeof(xml_node));
  root->name = NULL;
  root->value = NULL;
  root->parent = NULL;
  root->children = NULL;
  root->next = NULL;
  xml_node *current = root;
  char *start = xml;
  while (*start != '\0') {
    if (*start == '<') {
      start++;
      if (*start == '/') {
        start++;
        while (*start != '>') {
          start++;
        }
        current = current->parent;
      } else {
        char *name = start;
        while (*start != '>') {
          start++;
        }
        *start = '\0';
        current->name = malloc(strlen(name) + 1);
        strcpy(current->name, name);
        *start = '>';
        start++;
        if (*start == '/') {
          start++;
          while (*start != '>') {
            start++;
          }
          current = current->parent;
        } else {
          xml_node *child = malloc(sizeof(xml_node));
          child->name = NULL;
          child->value = NULL;
          child->parent = current;
          child->children = NULL;
          child->next = NULL;
          current->children = child;
          current = child;
        }
      }
    } else if (*start == '&') {
      start++;
      char *entity = start;
      while (*start != ';') {
        start++;
      }
      *start = '\0';
      if (strcmp(entity, "amp") == 0) {
        current->value = malloc(strlen("&") + 1);
        strcpy(current->value, "&");
      } else if (strcmp(entity, "lt") == 0) {
        current->value = malloc(strlen("<") + 1);
        strcpy(current->value, "<");
      } else if (strcmp(entity, "gt") == 0) {
        current->value = malloc(strlen(">") + 1);
        strcpy(current->value, ">");
      } else if (strcmp(entity, "quot") == 0) {
        current->value = malloc(strlen("\"") + 1);
        strcpy(current->value, "\"");
      } else if (strcmp(entity, "apos") == 0) {
        current->value = malloc(strlen("'") + 1);
        strcpy(current->value, "'");
      } else {
        current->value = malloc(strlen(entity) + 1);
        strcpy(current->value, entity);
      }
      *start = ';';
      start++;
    } else {
      char *value = start;
      while (*start != '<') {
        start++;
      }
      *start = '\0';
      current->value = malloc(strlen(value) + 1);
      strcpy(current->value, value);
      *start = '<';
    }
  }
  return root;
}

void xml_print(xml_node *node, int depth) {
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  if (node->name != NULL) {
    printf("<%s", node->name);
    if (node->value != NULL) {
      printf(" %s", node->value);
    }
    printf(">");
  } else {
    printf("%s", node->value);
  }
  if (node->children != NULL) {
    printf("\n");
    xml_print(node->children, depth + 1);
  }
  if (node->next != NULL) {
    printf("\n");
    xml_print(node->next, depth);
  }
}

int main() {
  char *xml = "<root><child1>value1</child1><child2>value2</child2></root>";
  xml_node *root = xml_parse(xml);
  xml_print(root, 0);
  return 0;
}