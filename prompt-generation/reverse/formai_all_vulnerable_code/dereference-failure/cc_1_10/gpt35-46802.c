//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB_SIZE 4

char* beautify_html(char* html_input);

int main(int argc, char* argv[])
{
    char html_input[] = "<div><p>Hello, world!</p><br><span>Isn't this program beautiful?</span></div>";
    char* beautified_html = beautify_html(html_input);
    printf("%s", beautified_html);
    free(beautified_html);
    return 0;
}

char* beautify_html(char* html_input)
{
    int indent_count = 0;
    int input_length = strlen(html_input);
    char* beautified_html = malloc((input_length * 2 + 1) * sizeof(char));
    char* input_ptr = html_input;
    char* beautified_ptr = beautified_html;
    while (*input_ptr != '\0')
    {
        if (*input_ptr == '<')
        {
            if (*(input_ptr + 1) != '/')
            {
                for (int i = 0; i < indent_count; i++)
                {
                    *beautified_ptr++ = ' ';
                }
                indent_count += TAB_SIZE;
            }
            else
            {
                indent_count -= TAB_SIZE;
                if (indent_count < 0)
                {
                    indent_count = 0;
                }
                for (int i = 0; i < indent_count; i++)
                {
                    *beautified_ptr++ = ' ';
                }
            }
        }
        *beautified_ptr++ = *input_ptr++;
    }
    *beautified_ptr = '\0';
    return beautified_html;
}