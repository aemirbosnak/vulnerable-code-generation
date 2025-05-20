//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node_t;

typedef struct list {
  node_t *head;
  node_t *tail;
} list_t;

list_t *create_list() {
  list_t *list = (list_t *)malloc(sizeof(list_t));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void add_to_list(list_t *list, char *data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

char *join_list(list_t *list) {
  node_t *current = list->head;
  size_t size = 0;
  while (current != NULL) {
    size += strlen(current->data);
    current = current->next;
  }
  char *joined = (char *)malloc(sizeof(char) * (size + 1));
  joined[0] = '\0';
  current = list->head;
  while (current != NULL) {
    strcat(joined, current->data);
    current = current->next;
  }
  return joined;
}

void free_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
  free(list);
}

int main() {
  char *html = "<html><head><title>My Website</title></head><body><h1>Hello World!</h1></body></html>";
  list_t *list = create_list();
  char *token = strtok(html, "<");
  while (token != NULL) {
    add_to_list(list, token);
    token = strtok(NULL, "<");
  }
  char *beautified_html = join_list(list);
  printf("%s\n", beautified_html);
  free_list(list);
  free(beautified_html);
  return 0;
}