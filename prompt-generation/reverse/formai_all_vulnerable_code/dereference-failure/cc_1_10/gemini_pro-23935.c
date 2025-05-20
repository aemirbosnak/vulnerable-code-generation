//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  struct node *next;
  char *str;
};

struct list {
  struct node *head;
  struct node *tail;
};

void add_node(struct list *list, char *str) {
  struct node *node = malloc(sizeof(struct node));
  node->str = strdup(str);
  node->next = NULL;
  if (list->tail == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
}

void print_list(struct list *list) {
  for (struct node *node = list->head; node != NULL; node = node->next) {
    printf("%s\n", node->str);
  }
}

void free_list(struct list *list) {
  for (struct node *node = list->head; node != NULL;) {
    struct node *next = node->next;
    free(node->str);
    free(node);
    node = next;
  }
  list->head = NULL;
  list->tail = NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct list list;
  list.head = NULL;
  list.tail = NULL;
  for (int i = 1; i < argc; i++) {
    add_node(&list, argv[i]);
  }

  for (struct node *node = list.head; node != NULL; node = node->next) {
    for (int i = 0; i < strlen(node->str); i++) {
      if (i % 2 == 0) {
        node->str[i] = toupper(node->str[i]);
      } else {
        node->str[i] = tolower(node->str[i]);
      }
    }
  }
  
  print_list(&list);

  free_list(&list);

  return EXIT_SUCCESS;
}