//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SIZE 4

void print_indent(int level) {
    for (int i = 0; i < level * INDENTATION_SIZE; i++) {
        putchar(' ');
    }
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    if (input == NULL || output == NULL) {
        fprintf(stderr, "Oops! Something went wrong while fetching your files! 🕵️\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int in_script_or_style = 0;

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;
        while (*ptr) {
            // Check for opening tags and adjust indentation accordingly
            if (strstr(ptr, "<script") || strstr(ptr, "<style")) {
                in_script_or_style = 1;
            }

            if (*ptr == '<') {
                if (*(ptr + 1) != '/') {
                    // It's an opening tag, increase the indent
                    print_indent(indent_level++);
                    fprintf(output, "%s", ptr);
                    break;
                } else {
                    // It's a closing tag, decrease the indent
                    print_indent(--indent_level);
                    fprintf(output, "%s", ptr);
                    break;
                }
            }
            
            // Print the line normally if not a tag
            if (in_script_or_style) {
                // Print the line as it is if we're in <script> or <style>
                fprintf(output, "%s", line);
                break;
            }

            // Move forward to the next character
            ptr++;
        }

        // If we're not in script/style, close the block.
        if (!in_script_or_style) {
            if (strstr(line, "</script>") || strstr(line, "</style>")) {
                in_script_or_style = 0;
            }
        }
    }

    fclose(input);
    fclose(output);
    printf("🎉 Ta-da! Your HTML has been beautified! Check the file: %s 🎉\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("🛠️ Hey there, code wizard! Please provide input and output file names, like this:\n");
        printf("    ./html_beautifier messy.html neat.html\n");
        return 1;
    }

    printf("✨ Let the beautification begin! ✨\n");
    beautify_html(argv[1], argv[2]);
    return 0;
}