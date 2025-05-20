//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define MAX_ERROR_MESSAGE_LENGTH 1024

// Global variables
int error_count = 0;
char error_messages[10][MAX_ERROR_MESSAGE_LENGTH];

void handle_error(int error_code, const char* error_message) {
  error_count++;
  sprintf(error_messages[error_count % 10], "%s (%d)", error_message, error_code);
}

int main() {
  // Some error-prone code here
  int x = 5 / 0;  // Division by zero!
  int y = strlen("hello world");  // String length overflow!
  char z = 'a' + 1;  // Char overflow!

  // Some more error-prone code here
  int* p = NULL;
  *p = 10;  // Null pointer dereference!

  // Now let's see what errors we've encountered
  if (x == -1) {
    handle_error(1, "Division by zero!");
  }

  if (y == -1) {
    handle_error(2, "String length overflow!");
  }

  if (z == -1) {
    handle_error(3, "Char overflow!");
  }

  if (*p == 10) {
    handle_error(4, "Null pointer dereference!");
  }

  // Print out all the error messages
  for (int i = 0; i < error_count; i++) {
    printf("%d: %s\n", i + 1, error_messages[i]);
  }

  return error_count;
}