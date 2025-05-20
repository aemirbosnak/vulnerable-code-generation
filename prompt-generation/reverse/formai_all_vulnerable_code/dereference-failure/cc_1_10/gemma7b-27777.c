//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char **html_buffer)
{
    char *buffer = *html_buffer;
    char *start = buffer;
    char *end = buffer;
    char *line_start = NULL;
    int line_number = 0;

    while (end)
    {
        if (*end == '\n')
        {
            line_start = end - MAX_BUFFER_SIZE + 1;
            line_number++;
            end++;
        }
        else if (*end == '}' || *end == ')')
        {
            end++;
            while (*line_start && *line_start != '{')
            {
                printf("%s", line_start);
                line_start--;
            }
            printf("\n");
            line_start = end;
            line_number++;
        }
        else
        {
            end++;
        }
    }

    printf("\n");
    *html_buffer = buffer;
}

int main()
{
    char *html_buffer = malloc(MAX_BUFFER_SIZE);
    strcpy(html_buffer, "<div><b>Hello, world!</b></div>");

    beautify_html(&html_buffer);

    printf("%s", html_buffer);

    free(html_buffer);

    return 0;
}