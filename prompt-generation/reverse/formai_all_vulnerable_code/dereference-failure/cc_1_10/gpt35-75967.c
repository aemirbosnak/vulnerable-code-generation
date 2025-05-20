//FormAI DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAB_SIZE 4

// Function to add indentation to the output file
void write_indentation(FILE *output_file, int indent_level)
{
    int i;
    for(i = 0; i < indent_level; i++)
    {
        fputs(" ", output_file);
    }
}

// Function to check if a given character is a newline character
bool is_newline(char c)
{
    return c == '\n' || c == '\r';
}

// Function to check if a given character is a whitespace character
bool is_whitespace(char c)
{
    return c == ' ' || c == '\t' || is_newline(c);
}

// Function to beautify the HTML code
void beautify_html(FILE *input_file, FILE *output_file)
{
    int indent_level = 0;
    bool in_tag = false;

    char current_char, previous_char = '\0';
    while ((current_char = fgetc(input_file)) != EOF)
    {
        if (current_char == '<')
        {
            in_tag = true;
        }

        // If we encounter a newline character, we need to add indentation to the output file
        if (is_newline(current_char))
        {
            fputc(current_char, output_file);
            write_indentation(output_file, indent_level);
        }
        else
        {
            fputc(current_char, output_file);
        }

        // If we encounter a closing tag, we need to decrease the indentation level
        if (current_char == '>' && !in_tag && previous_char == '/')
        {
            indent_level--;
        }

        if (current_char == '>')
        {
            in_tag = false;
            if (previous_char != '/' && !is_newline(previous_char))
            {
                indent_level++;
            }
        }

        previous_char = current_char;
    }
}

int main()
{
    char input_filename[100], output_filename[100];

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL)
    {
        printf("Input file not found!\n");
        return 1;
    }

    if (output_file == NULL)
    {
        printf("Output file not found!\n");
        return 1;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML formatting complete!\n");

    return 0;
}