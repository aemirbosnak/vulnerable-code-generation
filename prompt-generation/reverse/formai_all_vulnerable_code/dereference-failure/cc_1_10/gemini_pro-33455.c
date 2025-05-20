//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OPERATIONS 10

typedef struct {
  char *name;
  unsigned int (*operation)(unsigned int, unsigned int);
} operation_t;

unsigned int add(unsigned int a, unsigned int b) {
  return a + b;
}

unsigned int subtract(unsigned int a, unsigned int b) {
  return a - b;
}

unsigned int multiply(unsigned int a, unsigned int b) {
  return a * b;
}

unsigned int divide(unsigned int a, unsigned int b) {
  return a / b;
}

unsigned int modulus(unsigned int a, unsigned int b) {
  return a % b;
}

unsigned int bitwise_and(unsigned int a, unsigned int b) {
  return a & b;
}

unsigned int bitwise_or(unsigned int a, unsigned int b) {
  return a | b;
}

unsigned int bitwise_xor(unsigned int a, unsigned int b) {
  return a ^ b;
}

unsigned int bitwise_not(unsigned int a) {
  return ~a;
}

unsigned int bitwise_shift_left(unsigned int a, unsigned int b) {
  return a << b;
}

unsigned int bitwise_shift_right(unsigned int a, unsigned int b) {
  return a >> b;
}

operation_t operations[] = {
  {"add", add},
  {"subtract", subtract},
  {"multiply", multiply},
  {"divide", divide},
  {"modulus", modulus},
  {"bitwise_and", bitwise_and},
  {"bitwise_or", bitwise_or},
  {"bitwise_xor", bitwise_xor},
  {"bitwise_not", bitwise_not},
  {"bitwise_shift_left", bitwise_shift_left},
  {"bitwise_shift_right", bitwise_shift_right}
};

void print_usage() {
  printf("Usage: ./bitwise_operations <operation> <operand1> <operand2>\n");
  printf("Available operations:\n");
  for (int i = 0; i < NUM_OPERATIONS; i++) {
    printf("  %s\n", operations[i].name);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    print_usage();
    return 1;
  }

  char *operation_name = argv[1];
  unsigned int operand1 = atoi(argv[2]);
  unsigned int operand2 = atoi(argv[3]);

  operation_t *operation = NULL;
  for (int i = 0; i < NUM_OPERATIONS; i++) {
    if (strcmp(operation_name, operations[i].name) == 0) {
      operation = &operations[i];
      break;
    }
  }

  if (operation == NULL) {
    printf("Invalid operation: %s\n", operation_name);
    print_usage();
    return 1;
  }

  unsigned int result = operation->operation(operand1, operand2);
  printf("%u %s %u = %u\n", operand1, operation_name, operand2, result);

  return 0;
}