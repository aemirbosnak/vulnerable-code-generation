//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define RECURSION_LIMIT 5

void print_spaces(int num_spaces);
void print_string(const char *str);

int main() {
  int choice;
  char str[MAX_LENGTH];

  printf("Welcome to the Recursive Printing Program!\n");
  printf("Choose an option (1-3): ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter a string (max %d characters): ", MAX_LENGTH);
      fgets(str, MAX_LENGTH, stdin);
      print_string(str);
      break;
    case 2:
      printf("Enter a number of spaces to print (max %d): ", RECURSION_LIMIT);
      int num_spaces = atoi(stdin);
      print_spaces(num_spaces);
      break;
    case 3:
      printf("Recursively print the string 'Hello World' %d times: ", RECURSION_LIMIT);
      print_string("Hello World");
      break;
    default:
      printf("Invalid input. Please try again.\n");
      break;
  }

  return 0;
}

void print_spaces(int num_spaces) {
  if (num_spaces > 0) {
    printf(" ");
    print_spaces(num_spaces - 1);
  }
}

void print_string(const char *str) {
  if (str != NULL) {
    printf("%s\n", str);
    print_string(str + strlen(str));
  }
}