//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char *message;
  struct node *next;
} node_t;

typedef struct logger {
  node_t *head;
  node_t *tail;
  int size;
} logger_t;

void logger_init(logger_t *logger) {
  logger->head = NULL;
  logger->tail = NULL;
  logger->size = 0;
}

void logger_log(logger_t *logger, char *message) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->message = message;
  new_node->next = NULL;

  if (logger->head == NULL) {
    logger->head = new_node;
    logger->tail = new_node;
  } else {
    logger->tail->next = new_node;
    logger->tail = new_node;
  }

  logger->size++;
}

void logger_print(logger_t *logger) {
  node_t *current_node = logger->head;

  while (current_node != NULL) {
    printf("%s\n", current_node->message);
    current_node = current_node->next;
  }
}

int main() {
  logger_t logger;
  logger_init(&logger);

  logger_log(&logger, "Hello, world!");
  logger_log(&logger, "This is a test.");
  logger_log(&logger, "Goodbye!");

  logger_print(&logger);

  return 0;
}