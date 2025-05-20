//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function declaration
void beautify(char *input_file, char *output_file);

int main()
{
    char input_file[100], output_file[100];

    printf("Enter the input file name: ");
    fgets(input_file, 100, stdin);
    input_file[strcspn(input_file, "\n")] = 0; //removing newline from the input string

    printf("Enter the output file name: ");
    fgets(output_file, 100, stdin);
    output_file[strcspn(output_file, "\n")] = 0; //removing newline from the output string

    beautify(input_file, output_file); //calling the beautify function

    printf("File beautified successfully!\n");

    return 0;
}

void beautify(char *input_file, char *output_file)
{
    FILE *in_file, *out_file;
    char input_line[500], beautified_line[500];
    int indent = 0, i;

    in_file = fopen(input_file, "r");
    out_file = fopen(output_file, "w");

    if (in_file == NULL || out_file == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }

    //reading each line from the input file and beautifying it
    while (fgets(input_line, 500, in_file) != NULL)
    {
        for (i = 0; i < indent; i++) //adding appropriate indentation to the line
            beautified_line[i] = '\t';

        int j = 0;
        while(input_line[j] == ' ' || input_line[j] == '\t') //removing leading whitespace from the line
            j++;

        strcat(beautified_line, &input_line[j]); //concatenating the line to the beautified_line with appropriate indentation

        //checking for opening and closing braces and adjusting indentation accordingly
        if (strstr(input_line, "{") != NULL)
            indent++;

        if (strstr(input_line, "}") != NULL)
            indent--;

        fprintf(out_file, "%s", beautified_line); //writing beautified line to the output file
        memset(&input_line[0], 0, sizeof(input_line)); //clearing the input_line for the next read
        memset(&beautified_line[0], 0, sizeof(beautified_line)); //clearing the beautified_line for the next write
    }

    fclose(in_file);
    fclose(out_file);
}