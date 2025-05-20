//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <ctype.h>

void beautify(FILE *input, FILE *output, int indent_level);
void print_indent(FILE *output, int indent_level);

int main()
{
    FILE *input, *output;
    input = fopen("input.html", "r");
    output = fopen("output.html", "w");

    if (input == NULL || output == NULL)
    {
        printf("Error opening files.");
        return 0;
    }

    beautify(input, output, 0);

    fclose(input);
    fclose(output);
    return 0;
}

void beautify(FILE *input, FILE *output, int indent_level)
{
    int c;
    int last_char = ' ';
    int in_tag = 0;
    int in_attr = 0;

    while ((c = fgetc(input)) != EOF)
    {
        if (c == '<')
        {
            in_tag = 1;
            print_indent(output, indent_level);
            fputc(c, output);
        }
        else if (c == '>')
        {
            in_tag = 0;
            fputc(c, output);

            if (last_char == '/')
            {
                indent_level--;
            }

            fputc('\n', output);
        }
        else if (c == '"')
        {
            in_attr = !in_attr;
            fputc(c, output);
        }
        else if (c == ' ' && in_tag && !in_attr)
        {
            fputc(c, output);

            while ((c = fgetc(input)) == ' ');

            fputc(c, output);
        }
        else
        {
            fputc(c, output);
        }

        last_char = c;
    }
}

void print_indent(FILE *output, int indent_level)
{
    int i;

    for (i = 0; i < indent_level; i++)
    {
        fputc('\t', output);
    }
}