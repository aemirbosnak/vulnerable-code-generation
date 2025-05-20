//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_DEPTH 5

// Function to generate a random string
char* generate_random_string(int length) {
  char* str = malloc(length * sizeof(char));
  for (int i = 0; i < length; i++) {
    str[i] = 'a' + (rand() % 26);
  }
  return str;
}

// Function to print a tree of strings
void print_tree(char* root, int depth) {
  if (depth == 0) {
    printf("root\n");
    return;
  }

  for (int i = 0; i < depth; i++) {
    printf("    ");
  }

  printf("%s\n", root);

  if (depth > 0) {
    for (int i = 0; i < depth; i++) {
      printf("    ");
    }

    char* left = root + strlen(root) - 1;
    char* right = root + strlen(root);

    print_tree(left, depth - 1);
    print_tree(right, depth - 1);
  }
}

int main() {
  srand(time(NULL));

  char* root = generate_random_string(MAX_STRING_LENGTH);
  print_tree(root, MAX_DEPTH);

  free(root);
  return 0;
}