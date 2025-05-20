//FormAI DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

void beautify_html(char *input_file_name, char *output_file_name);

int main()
{
    char input_file[MAX_LENGTH], output_file[MAX_LENGTH];

    printf("Enter input HTML file name: ");
    scanf("%s", input_file);

    printf("Enter output HTML file name: ");
    scanf("%s", output_file);

    beautify_html(input_file, output_file);

    printf("\nBeautification complete!\n\n");

    return 0;
}

void beautify_html(char *input_file_name, char *output_file_name)
{
    FILE *input_file, *output_file;
    char ch, prev_ch;
    int indent_level = 0, i;

    input_file = fopen(input_file_name, "r");

    if (input_file == NULL)
    {
        printf("Error opening input file!\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "w");

    if (output_file == NULL)
    {
        printf("Error opening output file!\n");
        exit(1);
    }

    while ((ch = fgetc(input_file)) != EOF)
    {
        if (ch == '<')
        {
            if (prev_ch == '\n' || prev_ch == '\r')
            {
                for (i = 0; i < indent_level; i++)
                {
                    fputc('\t', output_file);
                }
            }

            fputc(ch, output_file);

            if (fgetc(input_file) == '/')
            {
                indent_level--;
            }
            else
            {
                indent_level++;
            }

            fputc('\n', output_file);

            for (i = 0; i < indent_level; i++)
            {
                fputc('\t', output_file);
            }
        }
        else if (ch == '>')
        {
            fputc(ch, output_file);
            fputc('\n', output_file);

            if (prev_ch == '/')
            {
                indent_level--;
            }

            for (i = 0; i < indent_level; i++)
            {
                fputc('\t', output_file);
            }
        }
        else
        {
            fputc(ch, output_file);
        }

        prev_ch = ch;
    }

    fclose(input_file);
    fclose(output_file);
}