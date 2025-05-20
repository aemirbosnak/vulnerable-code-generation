//FormAI DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* filename) {
    FILE *input_file, *output_file; 
    input_file = fopen(filename, "r"); //open file in read mode
    output_file = fopen("beauty.html", "w"); //create new file for output
    if (!input_file) {
        printf("Unable to open file.\n");
        return;
    }
    char current_char, next_char;
    int indent = 0;
    int should_indent = 0;
    while ((current_char = fgetc(input_file)) != EOF) {
        switch(current_char) {
            case '<':
                should_indent = 1;
                fputc(current_char, output_file);
                if ((next_char = fgetc(input_file)) == '/') {
                    indent--;
                } else {
                    indent++;
                } 
                fputc(next_char, output_file);
                if (next_char != '/') {
                    fputc('\n', output_file);
                }
                break;
            case '>':
                fputc(current_char, output_file);
                fputc('\n', output_file);
                should_indent = 1;
                break;
            default:
                fputc(current_char, output_file);
                break;
        }
        if (should_indent) {
            should_indent = 0;
            for (int i = 0; i < indent; i++) {
                fputc('\t', output_file);
            }
        }
    }
    fclose(input_file);
    fclose(output_file);
    printf("File beautified successfully.\n");
}

int main() {
    beautifyHTML("example.html");
    return 0;
}