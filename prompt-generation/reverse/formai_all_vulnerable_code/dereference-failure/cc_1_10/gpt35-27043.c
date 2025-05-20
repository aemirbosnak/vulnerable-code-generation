//FormAI DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// A function to beautify an HTML code string
char* beautify_html(char* html)
{
    // Create an indentation string for each level
    const int INDENT_SIZE = 4;
    char* indent = (char*) malloc(INDENT_SIZE + 1);
    int i;
    for (i = 0; i < INDENT_SIZE; i++)
    {
        indent[i] = ' ';
    }
    indent[INDENT_SIZE] = '\0';

    // Loop through each character of the HTML string
    int html_len = strlen(html);
    char* beautified_html = (char*) malloc((html_len + 1) * sizeof(char));
    int indent_level = 0, beautified_len = 0;
    for (i = 0; i < html_len; i++)
    {
        char c = html[i];

        // If the character is a tag, add indentation and a line break before it
        if (c == '<')
        {
            int is_closing_tag = (html[i+1] == '/');
            if (beautified_len > 0 && beautified_html[beautified_len-1] != '\n')
            {
                beautified_html[beautified_len++] = '\n';
            }
            if (is_closing_tag)
            {
                indent_level--;
            }
            if (beautified_len > 0 && html[i-1] == '>')
            {
                beautified_html[beautified_len++] = '\n';
            }
            int j;
            for (j = 0; j < indent_level; j++)
            {
                strcat(beautified_html, indent);
                beautified_len += INDENT_SIZE;
            }
            if (!is_closing_tag)
            {
                indent_level++;
            }
        }

        // Add the character to the beautified HTML string
        beautified_html[beautified_len++] = c;
    }

    beautified_html[beautified_len] = '\0';
    free(indent);

    return beautified_html;
}

int main()
{
    // Example HTML code to beautify
    char* html = "<html><head><title>Hello World</title></head><body><h1>Welcome</h1></body></html>";

    // Beautify the HTML code
    char* beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("%s\n", beautified_html);

    free(beautified_html);

    return 0;
}