//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

// Define a function to reverse a string
void reverse_string(char *str) {
  int i, j;
  char temp;

  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

// Define a function to capitalize the first letter of a string
void capitalize_first(char *str) {
  if (str[0] >= 'a' && str[0] <= 'z') {
    str[0] = str[0] - 'a' + 'A';
  }
}

// Define a function to remove duplicates from a string
void remove_duplicates(char *str) {
  int i, j;
  char temp;

  for (i = 0, j = 1; i < strlen(str); i++, j++) {
    if (str[i] != str[j - 1]) {
      str[j] = str[i];
    }
  }
  str[j] = '\0';
}

int main() {
  char str[] = "hello world";

  // Reverse the string
  reverse_string(str);
  printf("Reversed string: %s\n", str);

  // Capitalize the first letter
  capitalize_first(str);
  printf("Capitalized string: %s\n", str);

  // Remove duplicates
  remove_duplicates(str);
  printf("String without duplicates: %s\n", str);

  return 0;
}