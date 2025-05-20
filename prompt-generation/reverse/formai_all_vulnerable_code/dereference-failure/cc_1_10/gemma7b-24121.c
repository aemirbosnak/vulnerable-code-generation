//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html)
{
    int i = 0;
    char *p = html;
    char *q = NULL;
    char indent = ' ';

    while (*p)
    {
        switch (*p)
        {
            case '<':
                q = strstr(p, ">");
                if (q)
                {
                    int len = q - p;
                    for (i = 0; i < len; i++)
                    {
                        *p++ = indent;
                    }
                }
                break;
            case ' ':
                if (q && *(q - 1) == '>' && indent > ' ')
                {
                    *p++ = indent;
                }
                break;
            default:
                p++;
        }

        indent++;
    }

    return;
}

int main()
{
    char *html = "<p>This is a <b>bold</b> sentence.</p>\n";
    beautify_html(html);
    printf("%s", html);

    return 0;
}