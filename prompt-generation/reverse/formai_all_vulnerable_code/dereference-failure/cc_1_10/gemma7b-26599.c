//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html_code)
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0, j = 0, k = 0;
    int indent_level = 0;

    for (; html_code[i] != '\0'; i++)
    {
        switch (html_code[i])
        {
            case '<':
                buffer[j++] = html_code[i];
                if (html_code[i + 1] == ' ')
                {
                    buffer[j++] = ' ';
                }
                indent_level++;
                break;
            case '>':
                buffer[j++] = html_code[i];
                indent_level--;
                break;
            case '\n':
                buffer[j++] = '\n';
                for (k = 0; k < indent_level; k++)
                {
                    buffer[j++] = ' ';
                }
                break;
            default:
                buffer[j++] = html_code[i];
                break;
        }
    }

    free(buffer);

    return;
}

int main()
{
    char *html_code = "<p>This is a <b>bold</b> sentence.<br>"
                         "It has a <i>italic</i> phrase and a <u>underlined</u> word.</p>";

    beautify_html(html_code);

    printf("%s", html_code);

    return 0;
}