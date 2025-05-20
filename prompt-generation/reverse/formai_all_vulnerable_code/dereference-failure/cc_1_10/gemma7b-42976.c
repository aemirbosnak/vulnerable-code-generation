//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html_code)
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int buffer_size = 0;
    int i = 0;
    int in_tag = 0;
    int prev_space = 0;

    for (; html_code[i] != '\0'; i++)
    {
        if (buffer_size >= MAX_BUFFER_SIZE)
        {
            buffer = (char *)realloc(buffer, MAX_BUFFER_SIZE * 2);
            buffer_size *= 2;
        }

        if (!in_tag && html_code[i] == '<')
        {
            in_tag = 1;
            prev_space = 0;
        }
        else if (in_tag && html_code[i] == '>')
        {
            in_tag = 0;
            if (prev_space)
            {
                buffer[buffer_size++] = ' ';
            }
        }
        else if (prev_space && html_code[i] != ' ' && html_code[i] != '\n')
        {
            buffer[buffer_size++] = ' ';
        }

        buffer[buffer_size++] = html_code[i];
    }

    free(buffer);

    printf("%s", buffer);
}

int main()
{
    char *html_code = "<p>This is a sample HTML code.</p><b>Bold text</b><br>";

    beautify_html(html_code);

    return 0;
}