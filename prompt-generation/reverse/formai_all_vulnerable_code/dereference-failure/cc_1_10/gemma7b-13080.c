//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void beautify_html(char *html_code)
{
  int i, j, k, indent = 0;
  char *p, *q, tmp_code[1000];

  p = html_code;
  q = tmp_code;

  for (i = 0; *p; i++)
  {
    switch (*p)
    {
      case '<':
        indent = 0;
        break;
      case '>':
        indent++;
        break;
      default:
        if (indent)
        {
          for (j = 0; j < indent; j++)
          {
            *q++ = ' ';
          }
        }
        *q++ = *p;
    }

    p++;
  }

  strcpy(html_code, tmp_code);
}

int main()
{
  char html_code[] = "<p>This is a <b>bold</b> sentence.</p>\n"
                     "<div>This is a div element.</div>\n"
                     "<p>This is another paragraph.</p>";

  beautify_html(html_code);

  printf("%s", html_code);

  return 0;
}