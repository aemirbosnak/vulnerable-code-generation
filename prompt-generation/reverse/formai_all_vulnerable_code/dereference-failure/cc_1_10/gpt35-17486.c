//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void html_beautifier(char* input_file, char* output_file)
{
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Cannot create output file.\n");
        exit(1);
    }

    int c, i = 0, indent = 0;
    char buffer[1024];

    while ((c = fgetc(input)) != EOF) {
        if (c == '<') {
            if (fgetc(input) == '/') {
                indent--;
            }
            for (int j = 0; j < indent; j++) {
                fprintf(output, "    ");
            }
            indent++;
            fprintf(output, "<");
        }
        if (c == '>') {
            fprintf(output, ">\n");
        } else if (i < 1024) {
            buffer[i++] = c;
        }
        if (c == '\n') {
            buffer[i] = '\0';
            i = 0;
            for (int j = 0; j < indent; j++) {
                fprintf(output, "    ");
            }
            fprintf(output, "%s\n", buffer);
        }
    }
    fclose(input);
    fclose(output);

    printf("File successfully beautified!\n");
}

int main()
{
    char input_file[] = "input.html";
    char output_file[] = "output.html";
    html_beautifier(input_file, output_file);
}