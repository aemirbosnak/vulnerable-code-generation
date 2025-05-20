//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int beautify_html(char **html_code)
{
    int i = 0, j = 0, k = 0, line_number = 1, indent_level = 0;
    char buffer[MAX_BUFFER_SIZE], line[MAX_BUFFER_SIZE];
    char **lines = NULL;

    lines = malloc(sizeof(char *) * MAX_BUFFER_SIZE);

    while (*html_code[i] != '\0')
    {
        lines[k] = malloc(MAX_BUFFER_SIZE);

        for (j = 0; lines[k][j] = html_code[i][j]; j++)
        {
            if (html_code[i][j] == '<' && lines[k][j-1] == ' ' && lines[k][j-2] == ' ')
            {
                indent_level++;
            }
            else if (html_code[i][j] == '>' && lines[k][j-1] == ' ' && lines[k][j-2] == ' ')
            {
                indent_level--;
            }

            if (lines[k][j] != ' ' && lines[k][j] != '\n')
            {
                lines[k][j] = ' ';
            }
        }

        lines[k++][0] = '\n';

        i++;
    }

    *html_code = lines;

    return 0;
}

int main()
{
    char *html_code = "<p><b>Hello, world!</b></p>\n"
                              "<div>This is a div element.</div>\n";

    beautify_html(&html_code);

    printf("%s", html_code);

    free(html_code);

    return 0;
}