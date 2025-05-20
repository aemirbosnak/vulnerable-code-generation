//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
/*
* Program: HTML Beautifer
* Description: This program takes an HTML file as input and beautifies it by adding appropriate indentation, spacing and line breaks.
* Author: Your Name
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAB_SIZE 4      // Change this value to adjust the tab size

// Function prototypes
void beautify(char* html, int size);

int main()
{
    // Open the HTML file and read its contents
    FILE* fp;
    fp = fopen("index.html", "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = malloc(size);
    fread(buffer, size, 1, fp);
    fclose(fp);

    // Beautify the HTML code
    beautify(buffer, size);

    // Write the beautified HTML to a new file
    fp = fopen("beautified.html", "w");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to write file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, size, 1, fp);
    fclose(fp);

    printf("HTML file has been beautified successfully!\n");

    free(buffer);

    return 0;
}

// This function beautifies the given HTML code by adding appropriate indentation, spacing and line breaks.
void beautify(char* html, int size)
{
    int i = 0, j = 0, indent = 0;
    char c, prev = '\0';

    while(i < size)
    {
        c = html[i];

        if(c == '<')
        {
            if(html[i + 1] == '/')
            {
                indent -= TAB_SIZE;
                j -= TAB_SIZE;
            }

            for(int k = 0; k < indent; k++)
            {
                html[j++] = ' ';
            }
            html[j++] = c;

            if(!isspace(html[i + 1]) && html[i + 1] != '/')
            {
                indent += TAB_SIZE;
                j += TAB_SIZE;
            }
        }
        else if(c == '>')
        {
            html[j++] = c;

            if(prev == '/')
            {
                indent -= TAB_SIZE;
                j -= TAB_SIZE;
            }

            if(!(html[i + 1] == '<' && html[i + 2] == '/') && html[i + 1] != '\n')
            {
                html[j++] = '\n';
                for(int k = 0; k < indent; k++)
                {
                    html[j++] = ' ';
                }
            }

            if(html[i + 1] != '<' && html[i + 1] != '/')
            {
                indent += TAB_SIZE;
                j += TAB_SIZE;
            }
        }
        else
        {
            html[j++] = c;
        }

        prev = c;
        i++;
    }

    html[j] = '\0';
}