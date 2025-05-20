//Falcon2-11B DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
  // Sherlock Holmes: A Case of Missing Quotation Marks
  int i, j, k, n, num_quotes;
  char* a;
  char* b;
  char* c;

  // Allocate memory for strings a, b, and c
  a = (char*)malloc(sizeof(char) * 100);
  b = (char*)malloc(sizeof(char) * 100);
  c = (char*)malloc(sizeof(char) * 100);

  // Prompt user for string a
  printf("Enter a string: ");
  fgets(a, sizeof(a), stdin);

  // Remove trailing newline character from string a
  a[strcspn(a, "\n")] = '\0';

  // Prompt user for string b
  printf("Enter another string: ");
  fgets(b, sizeof(b), stdin);

  // Remove trailing newline character from string b
  b[strcspn(b, "\n")] = '\0';

  // Prompt user for string c
  printf("Enter a third string: ");
  fgets(c, sizeof(c), stdin);

  // Remove trailing newline character from string c
  c[strcspn(c, "\n")] = '\0';

  // Get the number of quotation marks in string a
  num_quotes = 0;
  for (i = 0; i < strlen(a); i++) {
    if (a[i] == '"') {
      num_quotes++;
    }
  }

  // Get the number of quotation marks in string b
  num_quotes = 0;
  for (i = 0; i < strlen(b); i++) {
    if (b[i] == '"') {
      num_quotes++;
    }
  }

  // Get the number of quotation marks in string c
  num_quotes = 0;
  for (i = 0; i < strlen(c); i++) {
    if (c[i] == '"') {
      num_quotes++;
    }
  }

  // Compare the number of quotation marks in string a with string b
  if (num_quotes == strlen(b)) {
    printf("The number of quotation marks in string a is equal to the length of string b.\n");
  } else {
    printf("The number of quotation marks in string a is not equal to the length of string b.\n");
  }

  // Compare the number of quotation marks in string a with string c
  if (num_quotes == strlen(c)) {
    printf("The number of quotation marks in string a is equal to the length of string c.\n");
  } else {
    printf("The number of quotation marks in string a is not equal to the length of string c.\n");
  }

  // Free the memory allocated for strings a, b, and c
  free(a);
  free(b);
  free(c);

  return 0;
}