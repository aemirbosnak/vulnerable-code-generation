//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html_code)
{
  char *p = html_code;
  char *q = NULL;
  int indent = 0;

  while (*p)
  {
    if (*p == '<')
    {
      q = strchr(p, '>');
      if (q)
      {
        int tag_length = q - p;
        char *tag_name = malloc(tag_length + 1);
        strncpy(tag_name, p, tag_length);
        tag_name[tag_length] = '\0';

        if (indent)
        {
          printf("%*s", indent, "");
        }
        printf("<%s>", tag_name);

        if (tag_length)
        {
          printf(" ");
        }

        indent++;
      }
    }
    else if (*p == '>' && indent)
    {
      indent--;
    }
    else
    {
      printf("%c", *p);
    }

    p++;
  }

  printf("\n");
}

int main()
{
  char html_code[] = "<p>This is a <b>bold</b> paragraph.</p>\n";
  beautify_html(html_code);

  return 0;
}