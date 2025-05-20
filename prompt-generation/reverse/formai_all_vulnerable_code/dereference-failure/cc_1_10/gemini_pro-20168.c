//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *html;
    int len;
} HTMLBuffer;

typedef struct {
    HTMLBuffer *buffer;
    int line_count;
    int indent_level;
    int config_indent_spaces;
    int config_wrap_width;
    int config_indent_empty_lines;
} Beautifier;

void beautify_html(Beautifier *beautifier, FILE *input, FILE *output) {
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, input) != NULL) {
        beautifier->line_count++;
        beautifier->buffer->len += strlen(line);
        beautifier->buffer->html = realloc(beautifier->buffer->html, beautifier->buffer->len + 1);
        strcat(beautifier->buffer->html, line);
    }

    // Initialize the output buffer.
    beautifier->buffer = malloc(sizeof(HTMLBuffer));
    beautifier->buffer->html = malloc(beautifier->buffer->len + 1);
    beautifier->buffer->len = 0;

    beautifier->line_count = 0;
    beautifier->indent_level = 0;
    beautifier->config_indent_spaces = 2;
    beautifier->config_wrap_width = 80;
    beautifier->config_indent_empty_lines = 0;

    // Parse the input HTML and beautify it.
    char *token;
    char *line_ptr = beautifier->buffer->html;
    while ((token = strtok(line_ptr, "<>")) != NULL) {
        // If the token is an opening tag, increase the indent level.
        if (token[0] == '<') {
            beautifier->indent_level++;
        }

        // If the token is a closing tag, decrease the indent level.
        else if (token[0] == '/') {
            beautifier->indent_level--;
        }

        // If the token is a text node, wrap it if necessary.
        else {
            int len = strlen(token);
            if (len + beautifier->indent_level * beautifier->config_indent_spaces > beautifier->config_wrap_width) {
                // Wrap the text node.
                char *wrapped_token = malloc(len + 1);
                int wrapped_len = 0;
                for (int i = 0; i < len; i++) {
                    if (i == 0 || i % beautifier->config_wrap_width == 0) {
                        wrapped_token[wrapped_len++] = '\n';
                        for (int j = 0; j < beautifier->indent_level * beautifier->config_indent_spaces; j++) {
                            wrapped_token[wrapped_len++] = ' ';
                        }
                    }
                    wrapped_token[wrapped_len++] = token[i];
                }
                wrapped_token[wrapped_len] = '\0';

                // Replace the original token with the wrapped token.
                token = wrapped_token;
            }
        }

        // Add the token to the output buffer.
        strcat(beautifier->buffer->html, token);

        // If the token is a new line, indent the next line.
        if (token[0] == '\n' && beautifier->config_indent_empty_lines) {
            for (int i = 0; i < beautifier->indent_level * beautifier->config_indent_spaces; i++) {
                strcat(beautifier->buffer->html, " ");
            }
        }

        // Parse the next token.
        line_ptr = strtok(NULL, "<>");
    }

    // Write the output buffer to the output file.
    fputs(beautifier->buffer->html, output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return 1;
    }

    // Create the beautifier.
    Beautifier beautifier;
    beautifier.buffer = NULL;
    beautifier.line_count = 0;
    beautifier.indent_level = 0;
    beautifier.config_indent_spaces = 2;
    beautifier.config_wrap_width = 80;
    beautifier.config_indent_empty_lines = 0;

    // Beautify the HTML.
    beautify_html(&beautifier, input, output);

    // Close the input and output files.
    fclose(input);
    fclose(output);

    return 0;
}