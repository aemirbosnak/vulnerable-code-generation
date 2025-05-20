//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void beautify_html(char *html)
{
  char *p = html;
  char *q = html;
  int indent = 0;

  while (*p)
  {
    if (*p == '<')
    {
      q = p;
      while (*q && *q != '>' && *q != '/' && *q != ' ')
      {
        q++;
      }

      if (q - p > 1)
      {
        int n = q - p;
        char *line = malloc(n + 1);
        memcpy(line, p, n);
        line[n] = '\0';

        printf("%*s", indent, line);

        free(line);
      }

      indent++;
    }
    else if (*p == '>')
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
  char *html = "<div><b>This is a heading</b><p>This is a paragraph.</p></div>";

  beautify_html(html);

  return 0;
}