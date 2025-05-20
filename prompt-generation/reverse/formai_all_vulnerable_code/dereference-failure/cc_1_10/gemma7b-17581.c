//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char **buffer)
{
    char *p = *buffer;
    char *q = *buffer;
    int line_length = 0;
    int in_comment = 0;

    while (*p)
    {
        if (in_comment)
        {
            if (*p == '/' && *(p-1) == '*')
            {
                in_comment = 0;
            }
        }
        else
        {
            if (*p == '<' && *(p+1) == '/')
            {
                line_length = 0;
            }

            if (line_length > 80)
            {
                q = *buffer;
                *buffer = realloc(*buffer, MAX_BUFFER_SIZE * 2);
                *buffer = (char *)realloc(*buffer, MAX_BUFFER_SIZE * 2);
                q = *buffer;
                while (*q)
                {
                    *q = '\n';
                    q++;
                }
                line_length = 0;
            }

            if (*p == '>' && *(p-1) == '<')
            {
                line_length++;
            }

            *q++ = *p;
        }
        p++;
    }

    *buffer = realloc(*buffer, MAX_BUFFER_SIZE);

    return;
}

int main()
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *html_code = "<p>This is a sample HTML code.<br>"
                           "<b>Bold text</b><br>"
                           "<div>This is a div element.</div>"
                           "<em>Italic text</em>";

    strcpy(buffer, html_code);

    beautify_html(&buffer);

    printf("%s", buffer);

    free(buffer);

    return 0;
}