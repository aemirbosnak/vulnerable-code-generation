//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char* input_file, char* output_file)
{
    FILE* input_fp = fopen(input_file, "r");
    FILE* output_fp = fopen(output_file, "w");

    if (input_fp == NULL || output_fp == NULL) {
        printf("Error opening input/output file. Please try again.\n");
        return;
    }

    char current_char;
    int indent_level = 0;
    while ((current_char = fgetc(input_fp)) != EOF) {
        switch (current_char) {
            case '<':
                fputc(current_char, output_fp);
                if (fgetc(input_fp) == '/') {
                    indent_level--;
                } else {
                    indent_level++;
                }
                break;
            
            case '>':
                fputc(current_char, output_fp);
                fputc('\n', output_fp);
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', output_fp);
                }
                break;

            case '\n':
                indent_level--;
                fputc(current_char, output_fp);
                break;

            default:
                fputc(current_char, output_fp);
                break;
        }
    }

    fclose(input_fp);
    fclose(output_fp);
}

int main(void)
{
    char input_file[] = "input.html";
    char output_file[] = "output.html";
    beautify(input_file, output_file);
    printf("HTML beautification complete!\n");
    return 0;
}