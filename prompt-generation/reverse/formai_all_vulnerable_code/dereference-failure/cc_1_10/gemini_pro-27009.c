//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mind-bending function to manipulate a string
char *mindbender(char *str) {
  // Reverse the string
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  // Replace all vowels with their uppercase counterparts
  for (int i = 0; i < len; i++) {
    switch (str[i]) {
      case 'a':
        str[i] = 'A';
        break;
      case 'e':
        str[i] = 'E';
        break;
      case 'i':
        str[i] = 'I';
        break;
      case 'o':
        str[i] = 'O';
        break;
      case 'u':
        str[i] = 'U';
        break;
    }
  }

  // Insert a space after every third character
  char *newstr = malloc(len + len / 3 + 1);
  int j = 0;
  for (int i = 0; i < len; i++) {
    newstr[j++] = str[i];
    if ((i + 1) % 3 == 0) {
      newstr[j++] = ' ';
    }
  }
  newstr[j] = '\0';

  // Return the modified string
  return newstr;
}

int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Mind-bend the string
  char *newstr = mindbender(str);

  // Print the modified string
  printf("Modified string: %s\n", newstr);

  // Free the allocated memory
  free(newstr);

  return 0;
}