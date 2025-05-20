//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html_code)
{
    char *p = html_code;
    char *q = html_code;
    int indent_level = 0;
    int in_tag = 0;

    while (*p)
    {
        switch (*p)
        {
            case '<':
                in_tag = 1;
                break;
            case ' ':
                if (in_tag)
                {
                    *q++ = ' ';
                }
                else if (indent_level)
                {
                    for (int i = 0; i < indent_level; i++)
                    {
                        *q++ = ' ';
                    }
                }
                break;
            case '>':
                in_tag = 0;
                indent_level++;
                break;
            default:
                *q++ = *p;
        }
        p++;
    }

    *q = NULL;
}

int main()
{
    char html_code[] = "<p>This is a sample HTML code.</p>\n"
                           "<div>This is a nested div.</div>";

    beautify_html(html_code);

    printf("%s", html_code);

    return 0;
}