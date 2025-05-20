//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>

// Paranoid error handling macros
#define CHECK(expr)                                                \
  if (!(expr)) {                                                   \
    fprintf(stderr, "Error: %s\n", #expr);                         \
    exit(EXIT_FAILURE);                                           \
  }

#define CHECK_MALLOC(ptr)                                          \
  if ((ptr) == NULL) {                                              \
    fprintf(stderr, "Error: malloc failed\n");                       \
    exit(EXIT_FAILURE);                                           \
  }

// Paranoid string manipulation macros
#define STRDUP(dst, src)                                             \
  if ((dst) == NULL) {                                               \
    fprintf(stderr, "Error: strdup failed\n");                       \
    exit(EXIT_FAILURE);                                           \
  }                                                                  \
  (dst) = strdup(src)

// Convert a binary string to an integer
int binary_to_int(const char *str) {
  int i, len, result = 0;
  len = strlen(str);

  // Validate the binary string
  for (i = 0; i < len; i++) {
    if (str[i] != '0' && str[i] != '1') {
      fprintf(stderr, "Error: Invalid binary string\n");
      exit(EXIT_FAILURE);
    }
  }

  // Convert the binary string to an integer
  for (i = len - 1; i >= 0; i--) {
    if (str[i] == '1') {
      result += 1 << (len - 1 - i);
    }
  }

  return result;
}

// Convert an integer to a binary string
char *int_to_binary(int num) {
  char *result = NULL;
  int i, len;

  // Validate the integer
  if (num < 0 || num > INT_MAX) {
    fprintf(stderr, "Error: Invalid integer\n");
    exit(EXIT_FAILURE);
  }

  // Determine the length of the binary string
  len = 0;
  while (num > 0) {
    num /= 2;
    len++;
  }

  // Allocate memory for the binary string
  result = malloc(len + 1);
  CHECK_MALLOC(result);

  // Convert the integer to a binary string
  i = len - 1;
  while (num > 0) {
    result[i--] = (num % 2) + '0';
    num /= 2;
  }
  result[len] = '\0';

  return result;
}

// Print a usage message
void usage(void) {
  fprintf(stderr, "Usage: binary_converter <command> <number>\n");
  fprintf(stderr, "Commands:\n");
  fprintf(stderr, "  b2i: Convert a binary string to an integer\n");
  fprintf(stderr, "  i2b: Convert an integer to a binary string\n");
  exit(EXIT_FAILURE);
}

// Main function
int main(int argc, char *argv[]) {
  char *command, *number;

  // Check the number of arguments
  if (argc != 3) {
    usage();
  }

  // Get the command and the number
  command = argv[1];
  number = argv[2];

  // Validate the command
  if (strcmp(command, "b2i") != 0 && strcmp(command, "i2b") != 0) {
    usage();
  }

  // Execute the command
  if (strcmp(command, "b2i") == 0) {
    int result = binary_to_int(number);
    printf("%d\n", result);
  } else if (strcmp(command, "i2b") == 0) {
    char *result = int_to_binary(atoi(number));
    printf("%s\n", result);
    free(result);
  }

  return 0;
}