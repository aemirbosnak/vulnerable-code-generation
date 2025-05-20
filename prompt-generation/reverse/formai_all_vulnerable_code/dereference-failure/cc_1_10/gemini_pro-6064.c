//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Grateful Beautification Engine (GBE)
// Humbly crafted with a grateful heart and a passion for code aesthetics

// Macros for indentation
#define INDENT_SPACES 2
#define INDENT(n) for (int i = 0; i < n * INDENT_SPACES; i++) printf(" ");

// Recursively traverse and beautify HTML
void beautifyHTML(char *html, int level) {
  char *start = html; // Start of current tag/text
  char *end = html;   // End of current tag/text
  char *attr = NULL; // Start of attribute name
  char *val = NULL;  // Start of attribute value
  int in_tag = 0;   // Flag indicating inside a tag

  while (*end) {
    // Skip whitespace
    while (*end && isspace(*end)) end++;
    if (!*end) break; // End of string

    if (in_tag) {
      // Inside a tag, looking for attributes or end of tag
      if (*end == '=') {
        // Attribute value start
        val = end + 1;
      } else if (*end == '"' || *end == '\'') {
        // Attribute value end
        *val = 0; // Terminate attribute value
        val = NULL;
        attr = NULL;
      } else if (*end == '>') {
        // End of tag
        *end = 0; // Terminate tag
        printf("\n");
        INDENT(level);
        printf("</%s>", start + 1);
        in_tag = 0;
      } else if (!attr) {
        // Attribute name start
        attr = end;
      }
    } else {
      // Outside a tag, looking for start of tag or text
      if (*end == '<') {
        // Start of tag
        in_tag = 1;
        start = end;
      } else {
        // Text
        start = end;
        while (*end && *end != '<') end++;
        *end = 0; // Terminate text
        printf("\n");
        INDENT(level);
        printf("%s", start);
      }
    }

    end++; // Advance to next character
  }

  if (in_tag) {
    // Unclosed tag
    *end = 0; // Terminate tag
    printf("\n");
    INDENT(level);
    printf("</%s>", start + 1);
  }
}

int main() {
  // Sample HTML to beautify
  char *html = "<html><head><title>Grateful Beautification</title></head><body><h1>Hello, World!</h1><p>This HTML is beautifully indented.</p></body></html>";

  // Beautify and print the HTML
  beautifyHTML(html, 0);

  return 0;
}