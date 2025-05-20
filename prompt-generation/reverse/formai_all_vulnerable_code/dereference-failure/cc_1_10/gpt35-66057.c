//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_LENGTH 4

char* beautify_html(char* html_input)
{
    char* prettified_html;

    /* Calculate the number of newlines needed for each tag */
    int num_newlines = 0;
    for (int i = 0; i < strlen(html_input); i++)
    {
        if (html_input[i] == '<') num_newlines++;
    }

    /* Allocate memory for the prettified HTML */
    prettified_html = (char*) malloc(strlen(html_input) + (num_newlines * (TAB_LENGTH + 1)) + 1);

    int indent_level = 0;
    int i = 0, j = 0;
    while (html_input[i] != '\0')
    {
        if (html_input[i] == '<')
        {
            if (html_input[i+1] == '/')
            {
                /* Closing tag */
                indent_level--;
            }
            else
            {
                /* Opening tag */
                for (int k = 1; k <= indent_level; k++)
                {
                    /* Indent with tabulation */
                    prettified_html[j] = '\t'; j++;
                }
                indent_level++;
            }
        }

        /* Copy the current character to the prettified HTML */
        prettified_html[j] = html_input[i]; i++; j++;

        if (prettified_html[j-1] == '>')
        {
            /* Close the tag with a newline */
            prettified_html[j] = '\n'; j++;
        }
    }

    /* Terminate the prettified HTML string with a null character */
    prettified_html[j] = '\0';

    return prettified_html;
}

int main()
{
    char* html_input = "<html><head><title>Test Page</title></head><body><h1>Welcome to my page!</h1></body></html>";
    char* prettified_html = beautify_html(html_input);
    printf("%s", prettified_html);

    free(prettified_html);
    return 0;
}