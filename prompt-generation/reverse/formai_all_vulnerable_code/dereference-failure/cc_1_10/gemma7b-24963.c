//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    int number;
    double decimal;
    char *string;
    struct JsonNode *object;
    struct JsonNode **array;
  } data;
  struct JsonNode *next;
} JsonNode;

void JsonNode_create(struct JsonNode **node) {
  *node = malloc(sizeof(struct JsonNode));
  (*node)->type = 'n';
  (*node)->data.number = 0;
  (*node)->next = NULL;
}

void JsonNode_setNumber(struct JsonNode *node, int number) {
  node->type = 'n';
  node->data.number = number;
}

void JsonNode_setString(struct JsonNode *node, char *string) {
  node->type = 's';
  node->data.string = strdup(string);
}

void JsonNode_addObject(struct JsonNode *node, struct JsonNode *child) {
  node->type = 'o';
  node->data.object = child;
}

void JsonNode_setArray(struct JsonNode *node, struct JsonNode **array) {
  node->type = 'a';
  node->data.array = array;
}

int JsonNode_getType(struct JsonNode *node) {
  return node->type;
}

int JsonNode_getNumber(struct JsonNode *node) {
  return node->data.number;
}

char *JsonNode_getString(struct JsonNode *node) {
  return node->data.string;
}

struct JsonNode *JsonNode_getObject(struct JsonNode *node) {
  return node->data.object;
}

struct JsonNode **JsonNode_getArray(struct JsonNode *node) {
  return node->data.array;
}

int main() {
  struct JsonNode *root = NULL;
  JsonNode_create(&root);

  JsonNode_setString(root, "John Doe");

  struct JsonNode *child = NULL;
  JsonNode_create(&child);
  JsonNode_setNumber(child, 30);

  JsonNode_addObject(root, child);

  struct JsonNode *anotherChild = NULL;
  JsonNode_create(&anotherChild);
  JsonNode_setString(anotherChild, "Jane Doe");

  JsonNode_addObject(root, anotherChild);

  printf("Name: %s, Age: %d\n", JsonNode_getString(root), JsonNode_getNumber(child));

  printf("Children:\n");
  for (struct JsonNode *node = root->data.object; node; node = node->next) {
    printf("- %s\n", JsonNode_getString(node));
  }

  return 0;
}