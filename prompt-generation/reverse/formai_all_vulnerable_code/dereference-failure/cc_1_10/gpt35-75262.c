//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
void beautify_html(char* code) {
  int i = 0, j = 0;

  // Loop through the code and remove unnecessary spaces and tabs
  while (code[i] != '\0') {
    // If the current character is a '<', remove all spaces and tabs until '>'
    if (code[i] == '<') {
      while (code[i] != '>' && code[i+1] != '<' && code[i] != '\0') {
        if (code[i+1] != '<') {
          if (code[i+1] == '\t' || code[i+1] == ' ') {
            i++;
          }
          else {
            code[j++] = code[i++];
          }
        }
        else {
          code[j++] = code[i++];
        }
      }
    }
    // If the current character is a '>', remove the space before it
    else if (code[i] == '>') {
      if (code[i-1] == ' ') {
        j--;
        code[j++] = code[i++];
        continue;
      }
      else {
        code[j++] = code[i++];
      }
    }
    // If the current character is a space or a tab, remove it
    else if (code[i] == ' ' || code[i] == '\t') {
      i++;
    }
    // If the current character is anything else, copy it to the new string
    else {
      code[j++] = code[i++];
    }
  }

  // Null terminate the new string
  code[j] = '\0';
}

int main() {
  // HTML code to beautify
  char* code = "<html>     <head>     <title>     My Title     </title>     </head>     <body>     <h1>     Welcome     </h1>     <p>     My paragraph.     </p>     </body>     </html>";

  // Beautify the HTML code
  beautify_html(code);

  // Print the beautified code
  printf("%s", code);

  return 0;
}