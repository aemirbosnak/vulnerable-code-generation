//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JSON_Node {
  char type;
  union {
    int number;
    double decimal;
    char* string;
    struct JSON_Node* object;
    struct JSON_Node* array;
  } data;
  struct JSON_Node* next;
} JSON_Node;

JSON_Node* json_node_create(char type) {
  JSON_Node* node = malloc(sizeof(JSON_Node));
  node->type = type;
  node->next = NULL;

  switch (type) {
    case 'o':
      node->data.object = NULL;
      break;
    case 'a':
      node->data.array = NULL;
      break;
    default:
      break;
  }

  return node;
}

void json_node_add(JSON_Node* node, JSON_Node* new_node) {
  if (node->next == NULL) {
    node->next = new_node;
  } else {
    json_node_add(node->next, new_node);
  }
}

void json_node_print(JSON_Node* node) {
  switch (node->type) {
    case 'n':
      printf("Integer: %d\n", node->data.number);
      break;
    case 'd':
      printf("Decimal: %.2lf\n", node->data.decimal);
      break;
    case 's':
      printf("String: %s\n", node->data.string);
      break;
    case 'o':
      printf("Object:\n");
      json_node_print(node->data.object);
      break;
    case 'a':
      printf("Array:\n");
      for (JSON_Node* i = node->data.array; i; i = i->next) {
        json_node_print(i);
      }
      break;
  }
}

int main() {
  JSON_Node* root = json_node_create('o');

  JSON_Node* name = json_node_create('s');
  name->data.string = "John Doe";
  json_node_add(root, name);

  JSON_Node* age = json_node_create('n');
  age->data.number = 30;
  json_node_add(root, age);

  JSON_Node* hobbies = json_node_create('a');
  JSON_Node* hobby1 = json_node_create('s');
  hobby1->data.string = "Reading";
  json_node_add(hobbies, hobby1);
  JSON_Node* hobby2 = json_node_create('s');
  hobby2->data.string = "Hiking";
  json_node_add(hobbies, hobby2);
  json_node_add(root, hobbies);

  json_node_print(root);

  return 0;
}