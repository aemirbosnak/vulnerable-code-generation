//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html_code)
{
  char *p = html_code;
  char *q = NULL;
  int indent = 0;

  // Allocate memory for the beautified HTML code
  html_code = (char *)malloc((int)strlen(html_code) * 2);

  // Traverse the HTML code and insert line breaks and indents
  while (*p)
  {
    // Check if the current character is a tag or closing tag
    if (*p == '<' || *p == '>' || *p == '}' || *p == ')')
    {
      // Insert a line break before the tag
      q = strstr(p, ">");
      if (q)
      {
        memcpy(html_code + indent * 2, "\n", 2);
        indent++;
      }
    }
    // Increment the indent for nested tags
    else if (*p == '(')
    {
      indent++;
    }
    // Decrement the indent for closing tags
    else if (*p == ')')
    {
      indent--;
    }

    // Copy the current character to the beautified code
    html_code[0] = *p;
    html_code++;
  }

  // Free the memory allocated for the original HTML code
  free(html_code);
}

int main()
{
  char html_code[] = "<div><b>Hello, world!</b></div>";

  beautify_html(html_code);

  printf("%s\n", html_code);

  return 0;
}