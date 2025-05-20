//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: brave
// cHTMLBeautifier.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to beautify HTML code
void cHTMLBeautifier(char *input) {
  char *output = malloc(strlen(input) * 2);
  int i, j;

  // Iterate through each line of the input HTML code
  for (i = 0; input[i] != '\0'; i++) {
    // Check if the current character is a newline
    if (input[i] == '\n') {
      // If it is, then add a newline to the output
      output[j] = '\n';
      j++;
    }

    // Check if the current character is a whitespace
    else if (isspace(input[i])) {
      // If it is, then add a space to the output
      output[j] = ' ';
      j++;
    }

    // Check if the current character is an opening tag
    else if (input[i] == '<') {
      // If it is, then check if the next character is a closing tag
      if (input[i + 1] == '/>') {
        // If it is, then add the opening tag to the output
        output[j] = '<';
        j++;
      } else {
        // If it is not, then iterate through the next characters
        for (j = i + 1; input[j] != '>'; j++) {
          // Add each character to the output, but do not add the closing tag
          output[j] = input[j];
        }
      }
    }

    // Check if the current character is a closing tag
    else if (input[i] == '</') {
      // If it is, then check if the next character is a closing tag
      if (input[i + 1] == '>') {
        // If it is, then add the closing tag to the output
        output[j] = '</';
        j++;
      }
    }

    // Add each character to the output, but do not add any closing tags
    output[j] = input[i];
    j++;
  }

  // Print the beautified HTML code
  printf("%s\n", output);
}

int main() {
  char input[] = "<p>Hello <b>world</b>!</p>";
  cHTMLBeautifier(input);
  return 0;
}