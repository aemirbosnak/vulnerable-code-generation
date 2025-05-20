//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char *str) {
  char *start = str;
  char *end = str + strlen(str) - 1;
  while (end > start) {
    char temp = *end;
    *end = *start;
    *start = temp;
    start++;
    end--;
  }
}

// Function to capitalize the first letter of a string
void capitalize_first_letter(char *str) {
  if (str[0] >= 'a' && str[0] <= 'z') {
    str[0] = str[0] - 'a' + 'A';
  }
}

// Function to remove duplicates from a string
void remove_duplicates(char *str) {
  char *start = str;
  char *end = str + strlen(str) - 1;
  char prev = '\0';
  while (end > start) {
    if (*end != prev) {
      *(end + 1) = '\0';
      prev = *end;
      end++;
    }
    start++;
  }
}

int main() {
  char str[] = "hello world";

  // Reverse the string
  reverse_string(str);
  printf("Reversed string: %s\n", str);

  // Capitalize the first letter
  capitalize_first_letter(str);
  printf("Capitalized string: %s\n", str);

  // Remove duplicates
  remove_duplicates(str);
  printf("String without duplicates: %s\n", str);

  return 0;
}