//FormAI DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char* html) {
  int indent = 0;
  int len = strlen(html);
  char* output = (char*) malloc(len + 1);

  for (int i = 0, pos = 0; i < len; i++) {
    if (html[i] == '<') {
      // check if this is a closing tag
      int is_closing_tag = 0;
      if (html[i+1] == '/') {
        is_closing_tag = 1;
      }

      // print current line
      output[pos++] = '\n';
      for (int j = 0; j < indent; j++) {
        output[pos++] = ' ';
      }

      // print opening or closing tag
      for (int j = 0; j < strlen(html); j++) {
        if (html[i+j] == '>') {
          output[pos++] = html[i+j];
          output[pos++] = '\n';
          break;
        }
        output[pos++] = html[i+j];
      }

      if (is_closing_tag) {
        indent -= 2;
      } else {
        indent += 2;
      }

      i += strlen(html+i) - 1;
    } else {
      output[pos++] = html[i];
    }
  }

  output[len] = '\0';
  printf("Beautified HTML:\n%s\n", output);
  free(output);
}

int main() {
  char* html = "<html><head><title>Hello, world!</title></head><body><h1>Welcome to my website!</h1><p>Here you will find all sorts of wonderful things.</p><ul><li>Item 1</li><li>Item 2</li><li>Item 3</li></ul></body></html>";
  printf("Original HTML:\n%s\n", html);
  beautify_html(html);

  return 0;
}