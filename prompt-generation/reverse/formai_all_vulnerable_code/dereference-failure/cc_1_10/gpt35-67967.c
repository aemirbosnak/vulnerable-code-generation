//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read the input HTML string
    char *input_html = malloc(sizeof(char) * 1000);
    printf("Enter the input HTML string:\n");
    scanf("%[^\n]s", input_html);

    // Traverse the input HTML string and beautify the tags
    char *output_html = malloc(sizeof(char) * 2000);
    int output_index = 0;
    int indent_level = 0;
    int input_length = strlen(input_html);
    for (int i = 0; i < input_length; i++)
    {
        // Copy the current character to the output
        output_html[output_index++] = input_html[i];

        // If we encounter the opening tag, increase the indent level
        if (input_html[i] == '<' && input_html[i+1] != '/')
        {
            indent_level++;
        }

        // If we encounter the closing tag, decrease the indent level
        if (input_html[i] == '<' && input_html[i+1] == '/')
        {
            indent_level--;
            output_index -= 2; // Remove the indentation from the closing tag
        }

        // If we encounter the end of the tag, insert a newline and indent
        if (input_html[i] == '>')
        {
            output_html[output_index++] = '\n';
            for (int j = 0; j < indent_level; j++)
            {
                output_html[output_index++] = '\t';
            }
        }
    }
    output_html[output_index] = '\0';

    // Print the beautified HTML string
    printf("\n\nOutput HTML:\n%s", output_html);

    // Free the memory
    free(input_html);
    free(output_html);

    return 0;
}