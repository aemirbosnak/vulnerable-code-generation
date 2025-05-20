//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *html); // function prototype

int main() {
  char html[1000];

  // input HTML code
  printf("Enter the HTML code:\n");
  fgets(html, 1000, stdin);
  
  beautify(html); // calling the function to beautify the HTML code
  
  return 0;
}

void beautify(char *html) {
  int i, j, k;
  int indent = 0;
  int len = strlen(html);
  char *result = (char *) malloc(len * sizeof(char));

  // loop through each character of the HTML code
  for(i = 0, j = 0; i < len - 1; i++) {
    // check if current character is '<'
    if(html[i] == '<') {
      // check if next character is '/'
      if(html[i + 1] == '/') {
        indent--; // reduce the indentation level
      }
      
      // add indentation to the result string
      for(k = 0; k < indent; k++) {
        result[j++] = '\t';
      }
      
      // copy the tag to the result string
      while(html[i] != '>') {
        result[j++] = html[i++];
      }
      result[j++] = html[i];

      // add a new line after opening tag
      if(html[i] == '>' && html[i - 1] != '/') {
        result[j++] = '\n';
      }

      // increase the indentation level
      if(html[i] == '<' && html[i + 1] != '/') {
        indent++;
      }
    }
    // copy other characters to the result string
    else {
      result[j++] = html[i];
    }
  }

  // terminate the result string
  result[j] = '\0';

  // print the beautified HTML code
  printf("Beautified HTML code:\n%s", result);
  
  // free the memory allocated to result string
  free(result);
}