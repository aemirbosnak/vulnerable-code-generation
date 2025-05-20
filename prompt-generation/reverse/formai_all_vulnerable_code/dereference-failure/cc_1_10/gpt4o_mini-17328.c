//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4
#define MAX_LINE_LENGTH 1024

void beautify_html(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");
    
    if (!infile) {
        perror("Failed to open input file");
        return;
    }
    if (!outfile) {
        perror("Failed to open output file");
        fclose(infile);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), infile)) {
        char *pos = line;
        int is_tag = 0;

        while (*pos) {
            if (*pos == '<') {
                // If we encounter an opening tag, we may need to increase indent
                is_tag = 1;
                if (strncmp(pos, "</", 2) != 0) { // Not a closing tag
                    fprintf(outfile, "%.*s", indent_level * INDENT_SIZE, "    ");
                    fprintf(outfile, "%s", pos);
                    indent_level++;
                } else { // Closing tag
                    indent_level--;
                    fprintf(outfile, "%.*s", indent_level * INDENT_SIZE, "    ");
                    fprintf(outfile, "%s", pos);
                }
                
                // Move pos forward to the end of the tag
                while (*pos != '>' && *pos != '\0') {
                    pos++;
                }
                if (*pos == '>') {
                    pos++;
                }
            } else if (is_tag && *pos == '\n') {
                strcpy(line, pos); // Continue from where we left off
                break;
            } else {
                // Regular content; just print it with proper indentation
                fprintf(outfile, "%.*s", indent_level * INDENT_SIZE, "    ");
                fputs(line, outfile);
                break;
            }
            pos++; // Move to the next character
        }
    }

    fclose(infile);
    fclose(outfile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification complete. Output written to '%s'.\n", argv[2]);
    return EXIT_SUCCESS;
}