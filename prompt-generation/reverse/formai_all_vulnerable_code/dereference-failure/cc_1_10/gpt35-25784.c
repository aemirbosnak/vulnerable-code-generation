//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define TAB_SIZE 4

char* read_file(const char* file_name);
char* beautify_html(const char* html, int tab_size, int use_spaces);
void print_indent(int depth, int tab_size, int use_spaces);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./htmlbeautifier <input_file>\n");
        return -1;
    }

    char* input_file = argv[1];
    char* html_str = read_file(input_file);

    if (html_str == NULL || strlen(html_str) == 0)
    {
        fprintf(stderr, "Failed to read input file %s.\n", input_file);
        return -1;
    }

    int tab_size = TAB_SIZE;
    int use_spaces = 1;
    char* output_str = beautify_html(html_str, tab_size, use_spaces);

    printf("%s", output_str);

    free(html_str);
    free(output_str);

    return 0;
}

char* read_file(const char* file_name)
{
    FILE* file = fopen(file_name, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file %s.\n", file_name);
        return NULL;
    }

    char* buffer = (char*)malloc(MAX_LEN * sizeof(char));
    memset(buffer, 0, MAX_LEN);

    int len = fread(buffer, sizeof(char), MAX_LEN - 1, file);

    if (ferror(file))
    {
        fclose(file);
        free(buffer);
        fprintf(stderr, "Failed to read from file %s.\n", file_name);
        return NULL;
    }

    fclose(file);

    if (len == 0)
    {
        free(buffer);
        buffer = NULL;
    }

    return buffer;
}

char* beautify_html(const char* html, int tab_size, int use_spaces)
{
    char* output = (char*)malloc((strlen(html) + 1) * sizeof(char));
    memset(output, 0, strlen(html) + 1);

    int depth = 0;
    int tag_start = 0;
    int i = 0;

    while (html[i] != '\0')
    {
        if (html[i] == '<')
        {
            if (html[i + 1] == '/')
            {
                // Decrease depth
                if (depth > 0)
                {
                    depth--;
                }
                print_indent(depth, tab_size, use_spaces);
            }
            else
            {
                // Increase depth
                print_indent(depth, tab_size, use_spaces);
                depth++;
            }
            tag_start = 1; // Set to true
        }
        else if (html[i] == '>')
        {
            output[i] = html[i];
            output[i + 1] = '\n';
            i++;
            tag_start = 0; // Set to false
        }
        else if (html[i] == ' ' && tag_start)
        {
            // Remove extraneous space characters in tags
            continue;
        }
        else
        {
            output[i] = html[i];
        }
        i++;
    }

    return output;
}

void print_indent(int depth, int tab_size, int use_spaces)
{
    if (!use_spaces)
    {
        for (int i = 0; i < depth; i++)
        {
            printf("\t");
        }
    }
    else
    {
        for (int i = 0; i < depth * tab_size; i++)
        {
            printf(" ");
        }
    }
}