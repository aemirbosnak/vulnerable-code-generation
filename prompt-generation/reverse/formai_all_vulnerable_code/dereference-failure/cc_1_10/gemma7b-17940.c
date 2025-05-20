//Gemma-7B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ErrorHandler {
  char* message;
  int line_number;
  struct ErrorHandler* next;
} ErrorHandler;

ErrorHandler* error_handler_create(char* message, int line_number) {
  ErrorHandler* handler = malloc(sizeof(ErrorHandler));

  handler->message = strdup(message);
  handler->line_number = line_number;
  handler->next = NULL;

  return handler;
}

void error_handler_add(ErrorHandler* handler, char* message, int line_number) {
  ErrorHandler* new_handler = error_handler_create(message, line_number);

  if (handler) {
    handler->next = new_handler;
  } else {
    handler = new_handler;
  }
}

int main() {
  ErrorHandler* errors = NULL;

  char buffer[MAX_BUFFER_SIZE];
  FILE* file = fopen("test.txt", "r");

  if (!file) {
    error_handler_add(errors, "Error opening file", __LINE__);
  }

  fgets(buffer, MAX_BUFFER_SIZE, file);

  if (buffer == NULL) {
    error_handler_add(errors, "Error reading file", __LINE__);
  }

  fclose(file);

  if (errors) {
    for (ErrorHandler* current = errors; current; current = current->next) {
      fprintf(stderr, "Error at line %d: %s\n", current->line_number, current->message);
    }
  }

  return 0;
}