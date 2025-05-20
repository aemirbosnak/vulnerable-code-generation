//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MIN_PROGRAM_SIZE 100

void analyze_program(char *program) {
  // 1. Tokenize the program
  char *token = strtok(program, " ");
  int num_tokens = 0;
  while (token != NULL && token[0] != '\0') {
    num_tokens++;
    token = strtok(NULL, " ");
  }

  // 2. Calculate the program's Cyclomatic complexity
  int cyclomatic_complexity = calculate_cyclomatic_complexity(program);
  printf("Cyclomatic complexity: %d\n", cyclomatic_complexity);

  // 3. Calculate the program's Halstead complexity
  int halstead_complexity = calculate_halstead_complexity(program);
  printf("Halstead complexity: %d\n", halstead_complexity);

  // 4. Calculate the program's Maintainability Index
  int maintainability_index = calculate_maintainability_index(program);
  printf("Maintainability Index: %d\n", maintainability_index);

  // 5. Print the program's summary
  printf("Program summary:\n");
  printf("  * Token count: %d\n", num_tokens);
  printf("  * Cyclomatic complexity: %d\n", cyclomatic_complexity);
  printf("  * Halstead complexity: %d\n", halstead_complexity);
  printf("  * Maintainability Index: %d\n", maintainability_index);
}

int calculate_cyclomatic_complexity(char *program) {
  int num_edges = 0;
  int num_nodes = 0;
  char *token = strtok(program, " ");
  while (token != NULL && token[0] != '\0') {
    if (token[0] == '(' || token[0] == '[' || token[0] == '{') {
      num_edges++;
    } else if (token[0] == ')' || token[0] == ']' || token[0] == '}') {
      num_edges--;
    }
    num_nodes++;
    token = strtok(NULL, " ");
  }
  return num_edges;
}

int calculate_halstead_complexity(char *program) {
  int num_operators = 0;
  char *token = strtok(program, " ");
  while (token != NULL && token[0] != '\0') {
    if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == ')' || token[0] == ',' || token[0] == '.' || token[0] == '(' || token[0] == '[' || token[0] == '{') {
      num_operators++;
    }
    token = strtok(NULL, " ");
  }
  return num_operators;
}

int calculate_maintainability_index(char *program) {
  int num_lines = 0;
  char *token = strtok(program, " ");
  while (token != NULL && token[0] != '\0') {
    num_lines++;
    token = strtok(NULL, " ");
  }
  return num_lines;
}

int main() {
  char *program = "int main() { int x = 5; return x + 3; }";
  analyze_program(program);
  return 0;
}