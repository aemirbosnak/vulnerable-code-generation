//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <string.h>

void beautify_html(char *html_code)
{
    char *p = html_code;
    char *q = html_code;
    int nesting_depth = 0;

    // Indent lines based on nesting depth
    while (*p)
    {
        if (*p == '<')
        {
             nesting_depth++;
        }
        else if (*p == '>')
        {
             nesting_depth--;
        }

        if (nesting_depth > 0)
        {
            int num_spaces = nesting_depth * 2;
            for (int i = 0; i < num_spaces; i++)
            {
                *q++ = ' ';
            }
        }

        *q++ = *p;
    }

    // Remove unnecessary white space
    char *r = html_code;
    while (*r)
    {
        if (*r == ' ' && *(r-1) == ' ' && *(r-2) == '<')
        {
            r--;
        }
        else
        {
            *q++ = *r;
        }
    }

    // Terminate the string
    *q = '\0';

    // Print the beautified HTML code
    printf("%s", html_code);
}

int main()
{
    char html_code[] = "<div><b>Hello, world!</b></div>\n";
    beautify_html(html_code);

    return 0;
}