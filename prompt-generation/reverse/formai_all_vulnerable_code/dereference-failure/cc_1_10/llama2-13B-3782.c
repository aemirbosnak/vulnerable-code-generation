//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 4

// Function to beautify HTML code
void html_beautify(char *input) {
  char *output = NULL;
  int i, j, tab_count = 0;
  char tab[TAB_SIZE];

  // Check if the input is empty
  if (input == NULL || *input == '\0') {
    return;
  }

  // Initialize the output string
  output = malloc(strlen(input) * 2);
  if (output == NULL) {
    printf("Error: Memory allocation failed\n");
    return;
  }

  // Loop through the input string
  for (i = 0; input[i] != '\0'; i++) {
    // Check if the current character is a tab
    if (input[i] == '\t') {
      // If it is, increment the tab count
      tab_count++;

      // If the tab count is greater than or equal to TAB_SIZE,
      // then add a newline character and reset the tab count
      if (tab_count >= TAB_SIZE) {
        output[j] = '\n';
        j++;
        tab_count = 0;
      }

      // Add the tab character to the output string
      output[j] = input[i];
      j++;
    } else {
      // If the current character is not a tab,
      // then add it to the output string
      output[j] = input[i];
      j++;
    }
  }

  // Add the remaining characters to the output string
  for (; i < strlen(input); i++) {
    output[j] = input[i];
    j++;
  }

  // Set the output string to the beautiful HTML code
  printf("%s\n", output);

  // Free the memory allocated for the output string
  free(output);
}

int main() {
  char input[100];

  // Ask the user for the input HTML code
  printf("Enter the HTML code: ");
  fgets(input, 100, stdin);

  // Beautify the HTML code
  html_beautify(input);

  return 0;
}