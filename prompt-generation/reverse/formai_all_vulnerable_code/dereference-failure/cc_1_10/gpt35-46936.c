//FormAI DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// define the maximum length of lines
#define MAX_LINE_LEN 1024

// function to beautify HTML code
void beautifyHTML(FILE* src, FILE* dst, int tab_size)
{
    // variables to keep track of indentation
    int indent = 0;
    int indent_size = 0;

    // variable to check if inside a tag
    int inside_tag = 0;

    // variable to store current read character
    char c;

    // loop through the source file character by character
    while ((c = fgetc(src)) != EOF)
    {
        // if the character is a newline
        if (c == '\n')
        {
            // write the newline character to the destination file
            fputc(c, dst);

            // reset the indentation variables
            indent = 0;
            indent_size = 0;

            // set the inside_tag variable to false
            inside_tag = 0;
        }
        // if the character is a less than sign '<'
        else if (c == '<')
        {
            // write the character to the destination file
            fputc(c, dst);

            // set the inside_tag variable to true
            inside_tag = 1;
        }
        // if the character is a greater than sign '>'
        else if (c == '>')
        {
            // write the character to the destination file
            fputc(c, dst);

            // set the inside_tag variable to false
            inside_tag = 0;
        }
        // if the character is a space
        else if (c == ' ')
        {
            // if inside a tag and the previous character was not a space
            if (inside_tag && fgetc(src) != ' ')
            {
                // calculate the indentation size
                indent_size = (indent + tab_size) / tab_size * tab_size - indent;

                // write the calculated number of spaces to the destination file
                for (int i = 0; i < indent_size; i++)
                {
                    fputc(' ', dst);
                }

                // update the indentation variables
                indent += indent_size;
            }

            // write the character to the destination file
            fputc(c, dst);
        }
        // if the character is not a special character
        else
        {
            // write the character to the destination file
            fputc(c, dst);
        }
    }
}

int main()
{
    // open the source file for reading
    FILE* src = fopen("input.html", "r");

    // open the destination file for writing
    FILE* dst = fopen("output.html", "w");

    // check if either file failed to open
    if (src == NULL || dst == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    // call the beautifyHTML function with a tab size of four spaces
    beautifyHTML(src, dst, 4);

    // close the source and destination files
    fclose(src);
    fclose(dst);

    return 0;
}