//FormAI DATASET v1.0 Category: HTML beautifier ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAB_SIZE 4

void print_tabs(int indent_level)
{
    int i;

    for(i = 0; i < indent_level * TAB_SIZE; ++i)
        printf(" ");
}

bool is_tag(char* line)
{
    int i;

    for(i = 0; line[i] != '\0'; ++i)
    {
        if(line[i] == '<')
            return true;

        if(line[i] == '>')
            return false;
    }

    return false;
}

int main()
{
    FILE* input_file;
    FILE* output_file;
    char* input_file_path = "input.html";
    char* output_file_path = "output.html";
    int indent_level = 0;

    input_file = fopen(input_file_path, "r");

    if(!input_file)
    {
        printf("Failed to open input file\n");
        return 1;
    }

    output_file = fopen(output_file_path, "w");

    if(!output_file)
    {
        printf("Failed to open output file\n");
        return 1;
    }

    char line[1000];
    int i;

    while(fgets(line, sizeof(line), input_file))
    {
        if(is_tag(line))
        {
            print_tabs(indent_level);
            fprintf(output_file, "%s", line);
            ++indent_level;
        }
        else if(line[0] == '<' && line[1] == '/')
        {
            --indent_level;
            print_tabs(indent_level);
            fprintf(output_file, "%s", line);
        }
        else
        {
            print_tabs(indent_level);
            fprintf(output_file, "%s", line);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}