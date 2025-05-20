//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html_code) {
  char *p, *q, *r, *s;
  int line_number = 1;
  int indent_level = 0;

  p = html_code;
  r = s = malloc(MAX_BUFFER_SIZE);

  while (*p) {
    switch (*p) {
      case '<':
        if (*(p-1) == '/') {
          // Closing tag
          indent_level--;
        } else {
          // Opening tag
          indent_level++;
        }
        break;
      case '\n':
        // Line break
        snprintf(s, MAX_BUFFER_SIZE, "%*s\n", indent_level * 2, "");
        strcat(r, s);
        line_number++;
        break;
      default:
        snprintf(s, MAX_BUFFER_SIZE, "%*s", indent_level * 2, "");
        strcat(r, s);
        break;
    }
    p++;
  }

  free(r);
  free(s);

  return;
}

int main() {
  char html_code[] = "<p>This is a sample HTML code snippet.<br>"
                           "<b>This text is bold.</b><br>"
                           "<div>This is a div element."
                           "</div>";

  beautify_html(html_code);

  printf("%s\n", html_code);

  return 0;
}