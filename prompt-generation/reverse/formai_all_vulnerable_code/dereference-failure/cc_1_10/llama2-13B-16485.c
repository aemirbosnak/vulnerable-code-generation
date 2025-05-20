//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_POEMS 10

// Global variables
char *poems[MAX_POEMS];
int poem_count = 0;

// Functions
void generate_poem(void);
void print_poem(int);

int main(void) {
  srand(time(NULL));

  // Generate poems
  for (int i = 0; i < MAX_POEMS; i++) {
    generate_poem();
  }

  // Print poems
  for (int i = 0; i < poem_count; i++) {
    print_poem(i);
  }

  return 0;
}

// Function to generate a poem
void generate_poem(void) {
  // Generate a random line length
  int line_length = rand() % MAX_LINE_LENGTH + 1;

  // Generate a random number of lines
  int line_count = rand() % 3 + 1;

  // Generate a poem
  char *poem = malloc(line_count * line_length * sizeof(char));
  for (int i = 0; i < line_count; i++) {
    for (int j = 0; j < line_length; j++) {
      poem[i * line_length + j] = rand() % 94 + 32;
    }
  }

  // Add the poem to the list
  poems[poem_count] = poem;
  poem_count++;
}

// Function to print a poem
void print_poem(int index) {
  printf("Poem %d:\n", index + 1);
  for (int i = 0; i < poem_count; i++) {
    if (i == index) {
      printf(" %s\n", poems[i]);
    } else {
      printf(" %s\n", poems[i]);
    }
  }
}